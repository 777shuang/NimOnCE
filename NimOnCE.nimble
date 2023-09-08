# Package

version       = "0.1.0"
author        = "777shuang"
description   = "An example of an application works on Windows CE"
license       = "MIT"
srcDir        = "src"
bin           = @["test"]

# Dependencies

requires "nim >= 1.4.2"
requires "sdl1 >= 1.0.0"
requires "winim"

# Task

task sdl, "SDLのセットアップ":
    exec "cd SDL-1.2; ./configure --prefix=$CEGCC/arm-mingw32ce --host=arm-mingw32ce --target=arm-mingw32ce"
    exec "cd SDL-1.2; make"

task libdl, "不足している関数を補う":
    exec "arm-mingw32ce-gcc -march=armv5tej -mcpu=arm926ej-s -s -Ofast -c libdl_dummy.c"
    exec "arm-mingw32ce-ar rcs libdl.a libdl_dummy.o"