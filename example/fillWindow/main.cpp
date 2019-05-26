//
// Created by siyualbak on 19. 5. 26.
//

#include <iostream>

#include "factory/internal/glfwFactory.h"
#include "initializer/internal/gl3wInitializer.h"
#include "buffer/frameBuffer.h"
#include "exception/exception.h"

int main() {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
  auto rendererContext = glfwFactory.createRenderingContext(*surface);
  rendererContext->makeCurrent();

  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl3WInitializer.init();

  auto colorBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
  while (!surface->shouldClose()) {
    static const GLfloat RED[] = {1.0f, 0.0f, 0.0f, 1.0f};

    colorBuffer->clear(0, RED);

    rendererContext->swapBuffers();
  }

  return 0;
}