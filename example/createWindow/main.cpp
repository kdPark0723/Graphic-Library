//
// Created by siyualbak on 19. 5. 26.
//

#include "factory/internal/glfwFactory.h"

int main() {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
  auto rendererContext = glfwFactory.createRenderingContext(*surface);

  while (!surface->shouldClose()) {
    rendererContext->swapBuffers();
  }

  return 0;
}