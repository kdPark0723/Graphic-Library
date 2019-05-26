//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_GLFWFACTORY_H
#define GRAPHICLIBRARY_GLFWFACTORY_H

#include "../factory.h"

#include "../../initializer/initializer.h"

namespace gl {
namespace internal {

class GLFWFactory : public Factory {
 public:
  GLFWFactory(const Initializer::Version &version);
  ~GLFWFactory() final;

  ::std::unique_ptr<Surface> createSurface(const ::std::string &title, const Size &size) const final;
  ::std::unique_ptr<WindowSurface> createWindowSurface(const ::std::string &title, const Size &size) const final;
  ::std::unique_ptr<OffScreenSurface> createOffScreenSurface(const ::std::string &title, const Size &size) const final;

  ::std::unique_ptr<RenderingContext> createRenderingContext(Surface &surface) const final;

 private:
  ::std::unique_ptr<Initializer> initializer;
};

}
}

#endif //GRAPHICLIBRARY_GLFWFACTORY_H
