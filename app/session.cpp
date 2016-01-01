#include "session.hpp"

#include "common.hpp"
#include "generated_message_handler.hpp"
#include "input_stream.hpp"
#include "window.hpp"


#include "SkGraphics.h"

session::session ()
{
  SkGraphics::Init ();
  SkEvent::Init ();
}

session::~session ()
{
  SkEvent::Term ();
}
