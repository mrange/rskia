@@@ metaprogram
@@@ extension hpp

#ifndef RSKIA_GENERATED_HPP
#define RSKIA_GENERATED_HPP

#include "common.hpp"
#include "input_stream.hpp"

@@> for method in $Model
@@>   mid                 = method.get :id
@@>   mprefix             = method.get :prefix
@@>   mverb               = method.get :verb
@@>   mnoun               = method.get :noun
@@>   mparameters         = method.get :parameters
@@>   xname               = mprefix.get :name
@@>   xprependParameters  = mprefix.get :prependParameters
// -----------------------------------------------------------------------------
// Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ (@@=mid=@@)
struct Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@
{
  Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ ()
@@> delimiter = ": "
@@> for parameter in (xprependParameters + mparameters)
@@>   ptype         = parameter.get :type
@@>   pname         = parameter.get :name
@@>   pdefaultValue = parameter.get :defaultValue
@@>   pmappedtype   = $TypeMap.get(ptype)
    @@=delimiter=@@@@=pname=@@ {}
@@>   delimiter = ", "
@@> end
  {
  }

  RSKIA_ONLY_MOVE (Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@);

  void unserialize (input_stream & is)
  {
    std::int32_t message_id;
    is.read (message_id);
    RSKIA_ASSERT (message_id == @@=mid=@@);

@@> for parameter in (xprependParameters + mparameters)
@@>   ptype         = parameter.get :type
@@>   pname         = parameter.get :name
@@>   pdefaultValue = parameter.get :defaultValue
@@>   pmappedtype   = $TypeMap.get(ptype)
    is.read (@@=pname=@@);
@@> end
  }

@@> for parameter in (xprependParameters + mparameters)
@@>   ptype         = parameter.get :type
@@>   pname         = parameter.get :name
@@>   pdefaultValue = parameter.get :defaultValue
@@>   pmappedtype   = $TypeMap.get(ptype)
  @@=pmappedtype=@@ @@=pname=@@;
@@> end
};
// -----------------------------------------------------------------------------

@@> end

// -----------------------------------------------------------------------------
// Visitor
struct message_visitor_i
{
  message_visitor_i ()          = default;
  virtual ~message_visitor_i () = default;

@@> for method in $Model
@@>   mid                 = method.get :id
@@>   mprefix             = method.get :prefix
@@>   mverb               = method.get :verb
@@>   mnoun               = method.get :noun
@@>   mparameters         = method.get :parameters
@@>   xname               = mprefix.get :name
@@>   xprependParameters  = mprefix.get :prependParameters
  // Visit__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ (@@=mid=@@)
  virtual void Visit__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ (Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ &&) = 0;
@@> end
};
// -----------------------------------------------------------------------------

void dispatch (input_stream & is, message_visitor_i & v)
{
  std::int32_t message_id = 0;
  is.peek (message_id);

  switch (message_id)
  {
@@> for method in $Model
@@>   mid                 = method.get :id
@@>   mprefix             = method.get :prefix
@@>   mverb               = method.get :verb
@@>   mnoun               = method.get :noun
@@>   mparameters         = method.get :parameters
@@>   xname               = mprefix.get :name
@@>   xprependParameters  = mprefix.get :prependParameters
  case @@=mid=@@:
    {
      Message__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ msg;
      msg.unserialize (is);
      v.Visit__@@=xname=@@_@@=mverb=@@_@@=mnoun=@@ (std::move (msg));
    }
    break;
@@> end
  default:
    RSKIA_ASSERT (false);
    break;
  }

  RSKIA_ASSERT (!is.overflowed ());
  RSKIA_ASSERT (!is.underflowed ());
}

#endif // RSKIA_GENERATED_HPP
@@+ $TypeMap =
@@+   {
@@+     "string"    => "std::wstring" ,
@@+     "int"       => "std::int32_t" ,
@@+     "double"    => "double"       ,
@@+     "bitmap_id" => "bitmap_id"    ,
@@+     "brush_id"  => "brush_id"     ,
@@+     "visual_id" => "visual_id"    ,
@@+   }

@@+ class Hash
@@+     def get (key, defaultValue=nil)
@@+         value = self[key]
@@+         return value unless value == nil
@@+         return defaultValue || ("KEY_'%s'_NOT_FOUND" % key.to_s)
@@+     end
@@+ end
