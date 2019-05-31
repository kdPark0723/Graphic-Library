//
// Created by siyualbak on 19. 5. 26.
//

#include "program.h"

int main() {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  while (!window->shouldClose()) {
    rendererContext->swapBuffers();
  }

  return 0;
}