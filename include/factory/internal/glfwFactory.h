//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_GLFWFACTORY_H
#define GRAPHICLIBRARY_GLFWFACTORY_H

#include "../factory.h"

#include "../../initializer/initializer.h"
#include "../../initializer/glLoaderInitializer.h"

namespace gl {
namespace internal {

class GLFWFactory : public Factory {
 public:
  GLFWFactory(const Initializer::Version &version, GLLoaderInitializer &glLoaderInitializer);
  ~GLFWFactory() final;

  std::shared_ptr<Surface> createSurface(const ::std::string &title, const Size &size) const final;
  std::shared_ptr<Window> createWindow(const ::std::string &title, const Size &size) const final;
  std::shared_ptr<ScreenSurface> createScreenSurface(Window &window) const final;
  std::shared_ptr<OffScreenSurface> createOffScreenSurface() const final;

 private:
  ::std::unique_ptr<Initializer> initializer;
  GLLoaderInitializer *glLoaderInitializer;
};

}
}

#endif //GRAPHICLIBRARY_GLFWFACTORY_H
