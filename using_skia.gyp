{
  'includes': [
    'third_party/skia/gyp/apptype_console.gypi',
  ],
  'targets': [
    {
      'configurations': {
        'Debug': { },
        'Release': { }
      },
      'target_name': 'using_skia',
      'type': 'executable',
      'dependencies': [
        'third_party/skia/gyp/skia_lib.gyp:skia_lib',
        'third_party/skia/gyp/views.gyp:views'
      ],
      'include_dirs': [
        'third_party/skia/include/config',
        'third_party/skia/include/core',
        'third_party/skia/include/gpu',
        'third_party/skia/include/views',
        'third_party/skia/include/xml'
      ],
      'sources': [
        'app/main.cpp',
        'app/window.cpp'
      ],
      'ldflags': [
        '-lskia', '-stdlib=libc++', '-std=c++11'
      ],
      'cflags': [
        '-Werror', '-W', '-Wall', '-Wextra', '-Wno-unused-parameter', '-g', '-O0'
      ]
    }
  ]
}
