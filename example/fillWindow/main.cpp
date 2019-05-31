//
// Created by siyualbak on 19. 5. 26.
//

#include <iostream>

#include "program.h"
#include "buffer/frameBuffer.h"

int main() {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  auto colorBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
  while (!window->shouldClose()) {
    static const GLfloat RED[] = {1.0f, 0.0f, 0.0f, 1.0f};

    colorBuffer->clear(0, RED);

    rendererContext->swapBuffers();
  }

  return 0;
}