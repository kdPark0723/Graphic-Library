//
// Created by siyualbak on 19. 5. 26.
//

#include <iostream>

#include "initializer/glLoaderInitializerImp.h"
#include "factory/factoryImp.h"
#include "buffer/frameBuffer.h"
#include "exception/exception.h"

int main() {
  gl::GLLoaderInitializerImp loaderInitializer{{4, 3}};
  gl::FactoryImp factory{{4, 3}, loaderInitializer};

  auto window = factory.createWindow("Test", {1024, 768});
  auto surface = factory.createScreenSurface(*window);
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