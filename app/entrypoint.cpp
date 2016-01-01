#include "common.hpp"

#include "session.hpp"

extern "C"
{
  RSKIA_SHARED_EXPORT void * create_session ()
  {
    return new session ();
  }

  RSKIA_SHARED_EXPORT void destroy_session (void * s)
  {
    delete static_cast<session*> (s);
  }

}
