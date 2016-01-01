#ifndef RSKIA_COMMON_HPP
#define RSKIA_COMMON_HPP

#include <cassert>
#include <cstdint>

#define RSKIA_ASSERT assert
#define RSKIA_SHARED_EXPORT __declspec(dllexport)

#define RSKIA_NO_COPY_MOVE(type)          \
  type (type const &)             = delete; \
  type (type &&)                  = delete; \
  type & operator= (type const &) = delete; \
  type & operator= (type &&)      = delete

#define RSKIA_ONLY_MOVE(type)             \
  type (type const &)             = delete ;\
  type (type &&)                  = default;\
  type & operator= (type const &) = delete ;\
  type & operator= (type &&)      = default

enum class bitmap_id : std::int32_t
{

};

enum class brush_id : std::int32_t
{

};

enum class visual_id : std::int32_t
{

};

#endif // RSKIA_COMMON_HPP
