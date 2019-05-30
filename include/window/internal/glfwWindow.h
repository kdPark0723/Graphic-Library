//
// Created by siyualbak on 19. 5. 29.
//

#ifndef GRAPHICLIBRARY_GLFWWINDOW_H
#define GRAPHICLIBRARY_GLFWWINDOW_H

#include <GLFW/glfw3.h>

#include "window/window.h"

namespace gl {
namespace internal {

class GLfwWindow : public Window {
 public:
  GLfwWindow(const ::std::string &title, const Size &size);
  ~GLfwWindow() final;

  const ::std::string getTitle() const final;
  const Size getSize() const final;

  bool shouldClose() const final;

   void *getWindowSurface() final;
   const void *getWindowSurface() const final;

 private:
  GLFWwindow *window;

  ::std::string title;
};

}
}

#endif //GRAPHICLIBRARY_GLFWWINDOW_H
