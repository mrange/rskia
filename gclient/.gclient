hooks = [
  {
    "name": "gyp",
    "pattern": ".",
    "action": ["python", "src/build/gyp_using_skia.py"]
  },]
solutions = [
  { "name"        : "src",
    "url"         : "https://github.com/mrange/rskia.git",
    "deps_file"   : "DEPS",
    "managed"     : True,
    "custom_deps" : {
    },
    "safesync_url": "",
  },
  { "name"        : "src/third_party/skia",
    "url"         : "https://skia.googlesource.com/skia.git@43a6f405e6aa0726fd18eb2b1575ac12ea093610",
    "deps_file"   : "DEPS",
    "managed"     : True,
    "custom_deps" : {
    },
    "safesync_url": "",
  },]
cache_dir = None
