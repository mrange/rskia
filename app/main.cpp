#include "window.hpp"

#include "SkGraphics.h"

void application_init ()
{
  SkGraphics::Init ();
  SkEvent::Init ();
}

void application_term ()
{
  SkEvent::Term ();
}
