
#ifndef RSKIA_GENERATED_HPP
#define RSKIA_GENERATED_HPP

#include "common.hpp"
#include "input_stream.hpp"

// -----------------------------------------------------------------------------
// Message__Internal_Do_Nothing (16)
struct Message__Internal_Do_Nothing
{
  Message__Internal_Do_Nothing ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Internal_Do_Nothing);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 16);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Internal_Discard_Window (17)
struct Message__Internal_Discard_Window
{
  Message__Internal_Discard_Window ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Internal_Discard_Window);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 17);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Internal_Create_BitmapFromBits (18)
struct Message__Internal_Create_BitmapFromBits
{
  Message__Internal_Create_BitmapFromBits ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Internal_Create_BitmapFromBits);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 18);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Set_Background (32)
struct Message__Global_Set_Background
{
  Message__Global_Set_Background ()
    : color {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Set_Background);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 32);

    is.read (color);
  }

  std::wstring color;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Clear_Visuals (33)
struct Message__Global_Clear_Visuals
{
  Message__Global_Clear_Visuals ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Clear_Visuals);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 33);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Hide_Window (34)
struct Message__Global_Hide_Window
{
  Message__Global_Hide_Window ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Hide_Window);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 34);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Show_Window (35)
struct Message__Global_Show_Window
{
  Message__Global_Show_Window ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Show_Window);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 35);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Await_Downloads (36)
struct Message__Global_Await_Downloads
{
  Message__Global_Await_Downloads ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Await_Downloads);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 36);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Global_Await_Refresh (37)
struct Message__Global_Await_Refresh
{
  Message__Global_Await_Refresh ()
  {
  }

  RSKIA_ONLY_MOVE (Message__Global_Await_Refresh);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 37);

  }

};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Bitmap_Download_Bitmap (48)
struct Message__Bitmap_Download_Bitmap
{
  Message__Bitmap_Download_Bitmap ()
    : bitmapId {}
    , uri {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Bitmap_Download_Bitmap);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 48);

    is.read (bitmapId);
    is.read (uri);
  }

  bitmap_id bitmapId;
  std::wstring uri;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Brush_Create_SolidBrush (64)
struct Message__Brush_Create_SolidBrush
{
  Message__Brush_Create_SolidBrush ()
    : brushId {}
    , color {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Brush_Create_SolidBrush);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 64);

    is.read (brushId);
    is.read (color);
  }

  brush_id brushId;
  std::wstring color;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Brush_Create_LinearGradientBrush (65)
struct Message__Brush_Create_LinearGradientBrush
{
  Message__Brush_Create_LinearGradientBrush ()
    : brushId {}
    , startX {}
    , startY {}
    , endX {}
    , endY {}
    , extendMode {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Brush_Create_LinearGradientBrush);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 65);

    is.read (brushId);
    is.read (startX);
    is.read (startY);
    is.read (endX);
    is.read (endY);
    is.read (extendMode);
  }

  brush_id brushId;
  double startX;
  double startY;
  double endX;
  double endY;
  std::wstring extendMode;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Brush_Create_RadialGradientBrush (66)
struct Message__Brush_Create_RadialGradientBrush
{
  Message__Brush_Create_RadialGradientBrush ()
    : brushId {}
    , centerX {}
    , centerY {}
    , radiusX {}
    , radiusY {}
    , offsetX {}
    , offsetY {}
    , extendMode {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Brush_Create_RadialGradientBrush);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 66);

    is.read (brushId);
    is.read (centerX);
    is.read (centerY);
    is.read (radiusX);
    is.read (radiusY);
    is.read (offsetX);
    is.read (offsetY);
    is.read (extendMode);
  }

  brush_id brushId;
  double centerX;
  double centerY;
  double radiusX;
  double radiusY;
  double offsetX;
  double offsetY;
  std::wstring extendMode;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Brush_Create_GradientStopForBrush (67)
struct Message__Brush_Create_GradientStopForBrush
{
  Message__Brush_Create_GradientStopForBrush ()
    : brushId {}
    , color {}
    , offset {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Brush_Create_GradientStopForBrush);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 67);

    is.read (brushId);
    is.read (color);
    is.read (offset);
  }

  brush_id brushId;
  std::wstring color;
  double offset;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Remove_Visual (80)
struct Message__Visual_Remove_Visual
{
  Message__Visual_Remove_Visual ()
    : visualId {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Remove_Visual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 80);

    is.read (visualId);
  }

  visual_id visualId;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Clone_Visual (81)
struct Message__Visual_Clone_Visual
{
  Message__Visual_Clone_Visual ()
    : visualId {}
    , cloneVisualId {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Clone_Visual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 81);

    is.read (visualId);
    is.read (cloneVisualId);
  }

  visual_id visualId;
  visual_id cloneVisualId;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Move_Visual (82)
struct Message__Visual_Move_Visual
{
  Message__Visual_Move_Visual ()
    : visualId {}
    , x {}
    , y {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Move_Visual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 82);

    is.read (visualId);
    is.read (x);
    is.read (y);
  }

  visual_id visualId;
  double x;
  double y;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Move_VisualToTop (83)
struct Message__Visual_Move_VisualToTop
{
  Message__Visual_Move_VisualToTop ()
    : visualId {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Move_VisualToTop);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 83);

    is.read (visualId);
  }

  visual_id visualId;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Move_VisualToBottom (84)
struct Message__Visual_Move_VisualToBottom
{
  Message__Visual_Move_VisualToBottom ()
    : visualId {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Move_VisualToBottom);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 84);

    is.read (visualId);
  }

  visual_id visualId;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Resize_Visual (85)
struct Message__Visual_Resize_Visual
{
  Message__Visual_Resize_Visual ()
    : visualId {}
    , width {}
    , height {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Resize_Visual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 85);

    is.read (visualId);
    is.read (width);
    is.read (height);
  }

  visual_id visualId;
  double width;
  double height;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Create_BitmapVisual (86)
struct Message__Visual_Create_BitmapVisual
{
  Message__Visual_Create_BitmapVisual ()
    : visualId {}
    , bitmapId {}
    , opacity {}
    , centerX {}
    , centerY {}
    , width {}
    , height {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Create_BitmapVisual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 86);

    is.read (visualId);
    is.read (bitmapId);
    is.read (opacity);
    is.read (centerX);
    is.read (centerY);
    is.read (width);
    is.read (height);
  }

  visual_id visualId;
  bitmap_id bitmapId;
  double opacity;
  double centerX;
  double centerY;
  double width;
  double height;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Create_RectangleVisual (87)
struct Message__Visual_Create_RectangleVisual
{
  Message__Visual_Create_RectangleVisual ()
    : visualId {}
    , fillBrushId {}
    , strokeBrushId {}
    , strokeWidth {}
    , centerX {}
    , centerY {}
    , width {}
    , height {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Create_RectangleVisual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 87);

    is.read (visualId);
    is.read (fillBrushId);
    is.read (strokeBrushId);
    is.read (strokeWidth);
    is.read (centerX);
    is.read (centerY);
    is.read (width);
    is.read (height);
  }

  visual_id visualId;
  brush_id fillBrushId;
  brush_id strokeBrushId;
  double strokeWidth;
  double centerX;
  double centerY;
  double width;
  double height;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Message__Visual_Create_EllipseVisual (88)
struct Message__Visual_Create_EllipseVisual
{
  Message__Visual_Create_EllipseVisual ()
    : visualId {}
    , fillBrushId {}
    , strokeBrushId {}
    , strokeWidth {}
    , centerX {}
    , centerY {}
    , width {}
    , height {}
  {
  }

  RSKIA_ONLY_MOVE (Message__Visual_Create_EllipseVisual);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == 88);

    is.read (visualId);
    is.read (fillBrushId);
    is.read (strokeBrushId);
    is.read (strokeWidth);
    is.read (centerX);
    is.read (centerY);
    is.read (width);
    is.read (height);
  }

  visual_id visualId;
  brush_id fillBrushId;
  brush_id strokeBrushId;
  double strokeWidth;
  double centerX;
  double centerY;
  double width;
  double height;
};
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Visitor
struct message_visitor_i
{
  message_visitor_i ()          = default;
  virtual ~message_visitor_i () = default;

  // Visit__Internal_Do_Nothing (16)
  virtual void Visit__Internal_Do_Nothing (Message__Internal_Do_Nothing &&) = 0;
  // Visit__Internal_Discard_Window (17)
  virtual void Visit__Internal_Discard_Window (Message__Internal_Discard_Window &&) = 0;
  // Visit__Internal_Create_BitmapFromBits (18)
  virtual void Visit__Internal_Create_BitmapFromBits (Message__Internal_Create_BitmapFromBits &&) = 0;
  // Visit__Global_Set_Background (32)
  virtual void Visit__Global_Set_Background (Message__Global_Set_Background &&) = 0;
  // Visit__Global_Clear_Visuals (33)
  virtual void Visit__Global_Clear_Visuals (Message__Global_Clear_Visuals &&) = 0;
  // Visit__Global_Hide_Window (34)
  virtual void Visit__Global_Hide_Window (Message__Global_Hide_Window &&) = 0;
  // Visit__Global_Show_Window (35)
  virtual void Visit__Global_Show_Window (Message__Global_Show_Window &&) = 0;
  // Visit__Global_Await_Downloads (36)
  virtual void Visit__Global_Await_Downloads (Message__Global_Await_Downloads &&) = 0;
  // Visit__Global_Await_Refresh (37)
  virtual void Visit__Global_Await_Refresh (Message__Global_Await_Refresh &&) = 0;
  // Visit__Bitmap_Download_Bitmap (48)
  virtual void Visit__Bitmap_Download_Bitmap (Message__Bitmap_Download_Bitmap &&) = 0;
  // Visit__Brush_Create_SolidBrush (64)
  virtual void Visit__Brush_Create_SolidBrush (Message__Brush_Create_SolidBrush &&) = 0;
  // Visit__Brush_Create_LinearGradientBrush (65)
  virtual void Visit__Brush_Create_LinearGradientBrush (Message__Brush_Create_LinearGradientBrush &&) = 0;
  // Visit__Brush_Create_RadialGradientBrush (66)
  virtual void Visit__Brush_Create_RadialGradientBrush (Message__Brush_Create_RadialGradientBrush &&) = 0;
  // Visit__Brush_Create_GradientStopForBrush (67)
  virtual void Visit__Brush_Create_GradientStopForBrush (Message__Brush_Create_GradientStopForBrush &&) = 0;
  // Visit__Visual_Remove_Visual (80)
  virtual void Visit__Visual_Remove_Visual (Message__Visual_Remove_Visual &&) = 0;
  // Visit__Visual_Clone_Visual (81)
  virtual void Visit__Visual_Clone_Visual (Message__Visual_Clone_Visual &&) = 0;
  // Visit__Visual_Move_Visual (82)
  virtual void Visit__Visual_Move_Visual (Message__Visual_Move_Visual &&) = 0;
  // Visit__Visual_Move_VisualToTop (83)
  virtual void Visit__Visual_Move_VisualToTop (Message__Visual_Move_VisualToTop &&) = 0;
  // Visit__Visual_Move_VisualToBottom (84)
  virtual void Visit__Visual_Move_VisualToBottom (Message__Visual_Move_VisualToBottom &&) = 0;
  // Visit__Visual_Resize_Visual (85)
  virtual void Visit__Visual_Resize_Visual (Message__Visual_Resize_Visual &&) = 0;
  // Visit__Visual_Create_BitmapVisual (86)
  virtual void Visit__Visual_Create_BitmapVisual (Message__Visual_Create_BitmapVisual &&) = 0;
  // Visit__Visual_Create_RectangleVisual (87)
  virtual void Visit__Visual_Create_RectangleVisual (Message__Visual_Create_RectangleVisual &&) = 0;
  // Visit__Visual_Create_EllipseVisual (88)
  virtual void Visit__Visual_Create_EllipseVisual (Message__Visual_Create_EllipseVisual &&) = 0;
};
// -----------------------------------------------------------------------------

void dispatch (input_stream & is, message_visitor_i & v)
{
  std::int32_t message_id = 0;
  is.peek (message_id);

  switch (message_id)
  {
  case 16:
    {
      Message__Internal_Do_Nothing msg;
      msg.unserialize (is);
      v.Visit__Internal_Do_Nothing (std::move (msg));
    }
    break;
  case 17:
    {
      Message__Internal_Discard_Window msg;
      msg.unserialize (is);
      v.Visit__Internal_Discard_Window (std::move (msg));
    }
    break;
  case 18:
    {
      Message__Internal_Create_BitmapFromBits msg;
      msg.unserialize (is);
      v.Visit__Internal_Create_BitmapFromBits (std::move (msg));
    }
    break;
  case 32:
    {
      Message__Global_Set_Background msg;
      msg.unserialize (is);
      v.Visit__Global_Set_Background (std::move (msg));
    }
    break;
  case 33:
    {
      Message__Global_Clear_Visuals msg;
      msg.unserialize (is);
      v.Visit__Global_Clear_Visuals (std::move (msg));
    }
    break;
  case 34:
    {
      Message__Global_Hide_Window msg;
      msg.unserialize (is);
      v.Visit__Global_Hide_Window (std::move (msg));
    }
    break;
  case 35:
    {
      Message__Global_Show_Window msg;
      msg.unserialize (is);
      v.Visit__Global_Show_Window (std::move (msg));
    }
    break;
  case 36:
    {
      Message__Global_Await_Downloads msg;
      msg.unserialize (is);
      v.Visit__Global_Await_Downloads (std::move (msg));
    }
    break;
  case 37:
    {
      Message__Global_Await_Refresh msg;
      msg.unserialize (is);
      v.Visit__Global_Await_Refresh (std::move (msg));
    }
    break;
  case 48:
    {
      Message__Bitmap_Download_Bitmap msg;
      msg.unserialize (is);
      v.Visit__Bitmap_Download_Bitmap (std::move (msg));
    }
    break;
  case 64:
    {
      Message__Brush_Create_SolidBrush msg;
      msg.unserialize (is);
      v.Visit__Brush_Create_SolidBrush (std::move (msg));
    }
    break;
  case 65:
    {
      Message__Brush_Create_LinearGradientBrush msg;
      msg.unserialize (is);
      v.Visit__Brush_Create_LinearGradientBrush (std::move (msg));
    }
    break;
  case 66:
    {
      Message__Brush_Create_RadialGradientBrush msg;
      msg.unserialize (is);
      v.Visit__Brush_Create_RadialGradientBrush (std::move (msg));
    }
    break;
  case 67:
    {
      Message__Brush_Create_GradientStopForBrush msg;
      msg.unserialize (is);
      v.Visit__Brush_Create_GradientStopForBrush (std::move (msg));
    }
    break;
  case 80:
    {
      Message__Visual_Remove_Visual msg;
      msg.unserialize (is);
      v.Visit__Visual_Remove_Visual (std::move (msg));
    }
    break;
  case 81:
    {
      Message__Visual_Clone_Visual msg;
      msg.unserialize (is);
      v.Visit__Visual_Clone_Visual (std::move (msg));
    }
    break;
  case 82:
    {
      Message__Visual_Move_Visual msg;
      msg.unserialize (is);
      v.Visit__Visual_Move_Visual (std::move (msg));
    }
    break;
  case 83:
    {
      Message__Visual_Move_VisualToTop msg;
      msg.unserialize (is);
      v.Visit__Visual_Move_VisualToTop (std::move (msg));
    }
    break;
  case 84:
    {
      Message__Visual_Move_VisualToBottom msg;
      msg.unserialize (is);
      v.Visit__Visual_Move_VisualToBottom (std::move (msg));
    }
    break;
  case 85:
    {
      Message__Visual_Resize_Visual msg;
      msg.unserialize (is);
      v.Visit__Visual_Resize_Visual (std::move (msg));
    }
    break;
  case 86:
    {
      Message__Visual_Create_BitmapVisual msg;
      msg.unserialize (is);
      v.Visit__Visual_Create_BitmapVisual (std::move (msg));
    }
    break;
  case 87:
    {
      Message__Visual_Create_RectangleVisual msg;
      msg.unserialize (is);
      v.Visit__Visual_Create_RectangleVisual (std::move (msg));
    }
    break;
  case 88:
    {
      Message__Visual_Create_EllipseVisual msg;
      msg.unserialize (is);
      v.Visit__Visual_Create_EllipseVisual (std::move (msg));
    }
    break;
  default:
    RSKIA_ASSERT (false);
    break;
  }

  RSKIA_ASSERT (!is.overflowed ());
  RSKIA_ASSERT (!is.underflowed ());
}

#endif // RSKIA_GENERATED_HPP
