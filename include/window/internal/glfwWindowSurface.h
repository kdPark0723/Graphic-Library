//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_GLFWWINDOWSURFACE_H
#define GRAPHICLIBRARY_GLFWWINDOWSURFACE_H

#include <GLFW/glfw3.h>

#include "../windowSurface.h"

namespace gl {
namespace internal {

class GLFWWindowSurface : public WindowSurface {
 public:
  GLFWWindowSurface(const ::std::string &title, const Size &size);
  ~GLFWWindowSurface() final;

  const ::std::string getTitle() const final;
  const Size getSize() const final;

  bool shouldClose() const final;

  void *getPlatformSurface() final;
  const void *getPlatformSurface() const final;

 private:
  GLFWwindow *window;

  ::std::string title;
};

}
}

#endif //GRAPHICLIBRARY_GLFWWINDOWSURFACE_H
