#include "window.hpp"

#include "gl/GrGLInterface.h"
#include "GrContext.h"
#include "SkApplication.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkGr.h"

MainWindow::MainWindow (void* hwnd)
  : base_t          (hwnd)
  , fFrameCount      (0)
  , fRotationAngle  (0)
  , fType           (DeviceType::GPU)
  , fSurface        (nullptr)
  , fContext        (nullptr)
  , fRenderTarget   (nullptr)
  , fAttachmentInfo {}
  , fInterface      (nullptr)
{
  this->setTitle ();
  this->setUpBackend ();
}

MainWindow::~MainWindow ()
{
  tearDownBackend ();
}

void MainWindow::tearDownBackend ()
{
  SkSafeUnref (fRenderTarget);
  fRenderTarget = NULL;

  SkSafeUnref (fContext);
  fContext = NULL;

  SkSafeUnref (fInterface);
  fInterface = NULL;

  base_t::detach ();
}

void MainWindow::setTitle ()
{
  SkString title ("Hello World ");
  title.appendf (fType == DeviceType::Raster ? "raster" : "opengl");
  base_t::setTitle (title.c_str ());
}

bool MainWindow::setUpBackend ()
{
  this->setColorType (kRGBA_8888_SkColorType);
  this->setVisibleP (true);
  this->setClipToBounds (false);

  bool result = attach (kNativeGL_BackEndType, 0 /*msaa*/, &fAttachmentInfo);
  if (false == result)
  {
    SkDebugf ("Not possible to create backend.\n");
    detach ();
    return false;
  }

  fInterface = GrGLCreateNativeInterface ();

  SkASSERT (NULL != fInterface);

  fContext = GrContext::Create (kOpenGL_GrBackend, (GrBackendContext)fInterface);
  SkASSERT (NULL != fContext);

  this->setUpRenderTarget ();
  return true;
}

void MainWindow::setUpRenderTarget ()
{
  SkSafeUnref (fRenderTarget);
  fRenderTarget = this->renderTarget (fAttachmentInfo, fInterface, fContext);
}

void MainWindow::drawContents (SkCanvas* canvas)
{
  // Clear background
  canvas->drawColor (SK_ColorWHITE);

  SkPaint paint;
  paint.setColor (SK_ColorRED);

  // Draw a rectangle with red paint
  SkRect rect
    {
      10  , 10  ,
      128 , 128 ,
    };
  canvas->drawRect (rect, paint);

  // Set up a linear gradient and draw a circle
  {
    SkPoint linearPoints[]
      {
        {0    , 0   },
        {300  , 300 },
      };

    SkColor linearColors[] { SK_ColorGREEN, SK_ColorBLACK, };

    SkShader* shader = SkGradientShader::CreateLinear (
        linearPoints
      , linearColors
      , NULL
      , 2
      , SkShader::kMirror_TileMode
      );

    SkAutoUnref shader_deleter (shader);

    paint.setShader (shader);
    paint.setFlags (SkPaint::kAntiAlias_Flag);

    canvas->drawCircle (200, 200, 64, paint);

    // Detach shader
    paint.setShader (NULL);
  }

  // Draw a message with a nice black paint.
  paint.setFlags (
      SkPaint::kAntiAlias_Flag
    | SkPaint::kSubpixelText_Flag   // ... avoid waggly text when rotating.
    | SkPaint::kUnderlineText_Flag
    );
  paint.setColor (SK_ColorBLACK);
  paint.setTextSize (20);

  canvas->save ();

  ++fFrameCount;
  char buffer[256];
  sprintf (buffer, "FrameCount: %d", fFrameCount);

  // Translate and rotate
  canvas->translate (300, 300);
  fRotationAngle += 0.2f;
  if (fRotationAngle > 360)
  {
    fRotationAngle -= 360;
  }
  canvas->rotate (fRotationAngle);

  // Draw the text:
  canvas->drawText (buffer, strlen (buffer), 0, 0, paint);

  canvas->restore ();
}

SkSurface* MainWindow::createSurface ()
{
  SkSurfaceProps props (base_t::getSurfaceProps ());

  if (DeviceType::GPU == fType)
  {
    return SkSurface::NewRenderTargetDirect (fRenderTarget, &props);
  }

  SkImageInfo info = SkImageInfo::MakeN32Premul (
      SkScalarRoundToInt (this->width ())
    , SkScalarRoundToInt (this->height ())
    );

  return fSurface = SkSurface::NewRaster (info, &props);
}

void MainWindow::draw (SkCanvas* canvas)
{
  drawContents (canvas);
  // in case we have queued drawing calls
  fContext->flush ();
  // Invalidate the window to force a redraw. Poor man's animation mechanism.
  this->inval (NULL);

  if (DeviceType::Raster == fType)
  {
    // need to send the raster bits to the (gpu) window
    SkImage* snap = fSurface->newImageSnapshot ();
    size_t rowBytes;
    SkImageInfo info;
    const void* pixels = snap->peekPixels (&info, &rowBytes);
    fRenderTarget->writePixels (
        0
      , 0
      , snap->width ()
      , snap->height ()
      , SkImageInfo2GrPixelConfig (
            info.colorType ()
          , info.alphaType ()
          , info.profileType ()
          )
      , pixels
      , rowBytes
      ,GrContext::kFlushWrites_PixelOp
      );
    SkSafeUnref (snap);
  }
  base_t::present ();
}

void MainWindow::onSizeChange ()
{
  setUpRenderTarget ();
}

bool MainWindow::onHandleChar (SkUnichar unichar)
{
  if (' ' == unichar)
  {
    fType = fType == DeviceType::Raster ? DeviceType::GPU : DeviceType::Raster;
    tearDownBackend ();
    setUpBackend ();
    this->setTitle ();
    this->inval (NULL);
  }

  return true;
}

SkOSWindow* create_sk_window (void* hwnd, int , char**)
{
  return new MainWindow (hwnd);
}
