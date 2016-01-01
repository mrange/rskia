require 'carnelian/executor'

$NoName = "<NoName>"
$NoType = "<NoName>"

def parameter(type, name, defaultValue=nil)
  {
    type:           type        || $NoType,
    name:           name        || $NoName,
    defaultValue:   defaultValue          ,
  }
end

def prefix(name, prependParameters=nil)
  {
    isInternal:         false                       ,
    name:               name              || $NoName,
    prependParameters:  prependParameters || []     ,
  }
end

$InternalInput  = prefix("Internal" )
$GlobalInput    = prefix("Global"   )
$BitmapInput    = prefix("Bitmap"   , [parameter("bitmap_id", "bitmapId")])
$BrushInput     = prefix("Brush"    , [parameter("brush_id" , "brushId")])
$VisualInput    = prefix("Visual"   , [parameter("visual_id", "visualId")])

def method(id, prefix, verb, noun, parameters=nil)
  {
    id:             id                    ,
    prefix:         prefix      || $NoName,
    verb:           verb        || $NoName,
    noun:           noun        || $NoName,
    parameters:     parameters  || []     ,
  }
end


$Model =
  [
    method(16 , $InternalInput , "Do"      , "Nothing"       ),
    method(17 , $InternalInput , "Discard" , "Window"        ),
    method(18 , $InternalInput , "Create"  , "BitmapFromBits"),

    method(32 , $GlobalInput   , "Set"     , "Background"    ,
      [
        parameter("string", "color", %{"#004"}) ,
      ]),
    method(33 , $GlobalInput   , "Clear"   , "Visuals"       ),
    method(34 , $GlobalInput   , "Hide"    , "Window"        ),
    method(35 , $GlobalInput   , "Show"    , "Window"        ),
    method(36 , $GlobalInput   , "Await"   , "Downloads"     ),
    method(37 , $GlobalInput   , "Await"   , "Refresh"       ),

    method(48 , $BitmapInput   , "Download", "Bitmap"        ,
      [
        parameter("string", "uri", %{""http://cliparts.co/cliparts/BTg/ERG/BTgERG4oc.png"}) ,
      ]),

    method(64 , $BrushInput     , "Create"  , "SolidBrush"    ,
      [
        parameter("string", "color", %{"#fff"} ),
      ]),
    method(65 , $BrushInput     , "Create"  , "LinearGradientBrush"    ,
      [
        parameter("double", "startX"    , "0.0"       ),
        parameter("double", "startY"    , "0.0"       ),
        parameter("double", "endX"      , "0.0"       ),
        parameter("double", "endY"      , "1.0"       ),
        parameter("string", "extendMode", %{"mirror"} ),
      ]),
    method(66 , $BrushInput     , "Create"  , "RadialGradientBrush"    ,
      [
        parameter("double", "centerX"   , "0.5"       ),
        parameter("double", "centerY"   , "0.5"       ),
        parameter("double", "radiusX"   , "1.0"       ),
        parameter("double", "radiusY"   , "1.0"       ),
        parameter("double", "offsetX"   , "-0.25"     ),
        parameter("double", "offsetY"   , "-0.25"     ),
        parameter("string", "extendMode", %{"mirror"} ),
      ]),
    method(67 , $BrushInput , "Create"  , "GradientStopForBrush"    ,
      [
        parameter("string"  , "color"   , %{"#fff"} ),
        parameter("double"  , "offset"  , "0.0"     ),
      ]),

    method(80 , $VisualInput    , "Remove"  , "Visual"),
    method(81 , $VisualInput    , "Clone"   , "Visual",
      [
        parameter("visual_id"   , "cloneVisualId" ),
      ]),
    method(82 , $VisualInput    , "Move"    , "Visual",
      [
        parameter("double", "x" , "100.0" ),
        parameter("double", "y" , "100.0" ),
      ]),
    method(83 , $VisualInput    , "Move"    , "VisualToTop"     ),
    method(84 , $VisualInput    , "Move"    , "VisualToBottom"  ),
    method(85 , $VisualInput    , "Resize"  , "Visual",
      [
        parameter("double", "width"   , "200.0" ),
        parameter("double", "height"  , "200.0" ),
      ]),
    method(86 , $VisualInput  , "Create"  , "BitmapVisual",
      [
        parameter("bitmap_id" , "bitmapId"            ),
        parameter("double"    , "opacity"   , "1.0"   ),
        parameter("double"    , "centerX"   , "344.0" ),
        parameter("double"    , "centerY"   , "257.0" ),
        parameter("double"    , "width"     , "488.0" ),
        parameter("double"    , "height"    , "314.0" ),
      ]),
    method(87 , $VisualInput  , "Create"  , "RectangleVisual",
      [
        parameter("brush_id"  , "fillBrushId"   , "3"     ),
        parameter("brush_id"  , "strokeBrushId" , "1"     ),
        parameter("double"    , "strokeWidth"   , "3.0"   ),
        parameter("double"    , "centerX"       , "200.0" ),
        parameter("double"    , "centerY"       , "100.0" ),
        parameter("double"    , "width"         , "100.0" ),
        parameter("double"    , "height"        , "100.0" ),
      ]),
    method(88 , $VisualInput  , "Create"  , "EllipseVisual",
      [
        parameter("brush_id"  , "fillBrushId"   , "4"     ),
        parameter("brush_id"  , "strokeBrushId" , "1"     ),
        parameter("double"    , "strokeWidth"   , "3.0"   ),
        parameter("double"    , "centerX"       , "100.0" ),
        parameter("double"    , "centerY"       , "200.0" ),
        parameter("double"    , "width"         , "100.0" ),
        parameter("double"    , "height"        , "100.0" ),
      ]),
#    new MethodDescriptor  (VisualInput      , "Create"        , "TextVisual"          )
#    {
#      PD ("int"     , "fillBrushId"   , "1"                 ),
#      PD ("int"     , "textFormatId"  , "0"                 ),
#      PD ("double"  , "centerX"       , "200.0"             ),
#      PD ("double"  , "centerY"       , "200.0"             ),
#      PD ("double"  , "width"         , "100.0"             ),
#      PD ("double"  , "height"        , "100.0"             ),
#      PD ("string"  , "text"          , "\"Hello World!\""  ),
#    },
  ]

CarnelianExecutor.execute_metaprogram_to_file "generated_message_handler.mp", "../app/generated_message_handler.hpp"
