#ifndef RSKIA_INPUT_STREAM_HPP
#define RSKIA_INPUT_STREAM_HPP

#include <cstdint>
#include <string>
#include <type_traits>

#include "common.hpp"

template<typename TValue>
struct is_value : std::integral_constant<
    bool
  ,     std::is_integral<TValue>::value
    ||  std::is_floating_point<TValue>::value
    ||  std::is_enum<TValue>::value
  >
{
};

struct input_stream
{
  inline input_stream (char * b, std::size_t sz)
    : buffer    (b)
    , size      (sz)
    , position  (0)
  {
    RSKIA_ASSERT (b);
  }

  RSKIA_NO_COPY_MOVE(input_stream);

  inline std::size_t aligned_pos (std::size_t alignment)
  {
    return position;
  }

  template<typename TValue>
  inline std::enable_if_t<is_value<TValue>::value> peek (TValue & v)
  {
    using value_t = std::decay_t<TValue>;
    auto pos  = aligned_pos (alignof (value_t));
    auto next = pos + sizeof (value_t);

    if (next <= size)
    {
      v = *reinterpret_cast<TValue const *> (buffer + pos);
    }
    else
    {
      v = TValue ();
    }
  }

  template<typename TValue>
  inline std::enable_if_t<is_value<TValue>::value> read (TValue & v)
  {
    using value_t = std::decay_t<TValue>;
    auto pos  = aligned_pos (alignof (value_t));
    auto next = pos + sizeof (value_t);

    if (next <= size)
    {
      v = *reinterpret_cast<TValue const *> (buffer + pos);
      position = next;
    }
    else
    {
      v = TValue ();
      position = size;
    }
  }

  void read (std::wstring & v)
  {
    v.clear ();

    std::uint16_t sz;
    read (sz);
    v.reserve (sz);

    auto next = position + sz;
    if (next <= size)
    {
      std::wstring tmp (reinterpret_cast<wchar_t const *> (buffer + position), sz);
      v = std::move (v);
    }
    else
    {
      position = size;
    }

  }

private:
  char const * const  buffer    ;
  std::size_t const   size      ;
  std::size_t         position  ;
};

#endif // RSKIA_INPUT_STREAM_HPP
