from sdl import nil

proc main(): cint {.exportc.} =
  discard sdl.init(sdl.INIT_EVERYTHING)

  discard sdl.setVideoMode(640, 480, 32, sdl.HWSURFACE)

  sdl.delay(3000)

  sdl.quit()

  return 0