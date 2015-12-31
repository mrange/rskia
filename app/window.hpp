#ifndef RSKIA_WINDOW_HPP
#define RSKIA_WINDOW_HPP

#include "SkSurface.h"
#include "SkWindow.h"

class GrContext;
struct GrGLInterface;
class GrRenderTarget;
class SkCanvas;

class MainWindow : public SkOSWindow
{
public:
  using base_t = SkOSWindow;

  enum class DeviceType
  {
    Raster,
    GPU   ,
  };

  MainWindow (void* hwnd);
  virtual ~MainWindow () override;

  // Changes the device type of the object.
  bool setUpBackend ();

  DeviceType getDeviceType () const { return fType; }

protected:
  SkSurface* createSurface () override;

  void draw (SkCanvas* canvas) override;
  void drawContents (SkCanvas* canvas);

  void onSizeChange () override;

private:
  bool findNextMatch ();
  void setTitle ();
  void setUpRenderTarget ();
  bool onHandleChar (SkUnichar unichar) override;
  void tearDownBackend ();

  int                   fFrameCount     ;
  SkScalar              fRotationAngle  ;

  DeviceType            fType           ;
  AttachmentInfo        fAttachmentInfo ;
  GrGLInterface const * fInterface      ;
  GrContext*            fContext        ;
  GrRenderTarget*       fRenderTarget   ;
  SkSurface*            fSurface        ;
};

#endif // RSKIA_WINDOW_HPP
