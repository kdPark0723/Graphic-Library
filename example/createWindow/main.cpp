//
// Created by siyualbak on 19. 5. 26.
//

#include "initializer/glLoaderInitializerImp.h"
#include "factory/factoryImp.h"

int main() {
  gl::GLLoaderInitializerImp loaderInitializer{{4, 3}};
  gl::FactoryImp factory{{4, 3}, loaderInitializer};

  auto window = factory.createWindow("Test", {1024, 768});
  auto surface = factory.createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  while (!window->shouldClose()) {
    rendererContext->swapBuffers();
  }

  return 0;
}