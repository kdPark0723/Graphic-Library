//
// Created by siyualbak on 19. 5. 26.
//

#include <iostream>

#include "program.h"
#include "buffer/frameBuffer.h"

int main() {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();

  auto window1 = factory->createWindow("Test1", {1024, 768});
  auto window2 = factory->createWindow("Test1", {1024, 768});

  auto surface1 = factory->createScreenSurface(*window1);
  auto surface2 = factory->createScreenSurface(*window2);

  auto rendererContext1 = surface1->getRenderingContext();
  auto rendererContext2 = surface2->getRenderingContext();

  auto colorBuffer1 = rendererContext1->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
  auto colorBuffer2 = rendererContext2->getFrameBuffer(gl::FrameBuffer::Buffer::Color);

  while (true) {
    if (!window1->shouldClose()) {
      static const GLfloat RED[] = {1.0f, 0.0f, 0.0f, 1.0f};
      rendererContext1->makeCurrent();

      colorBuffer1->clear(0, RED);

      rendererContext1->swapBuffers();
    }
    if (!window2->shouldClose()) {
      static const GLfloat BRUE[] = {0.0f, 0.0f, 1.0f, 1.0f};
      rendererContext2->makeCurrent();

      colorBuffer2->clear(0, BRUE);

      rendererContext2->swapBuffers();
    }

    if (window1->shouldClose() && window2->shouldClose()) {
      break;
    }
  }

  return 0;
}