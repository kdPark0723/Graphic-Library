//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_GLFWSCREENSURFACE_H
#define GRAPHICLIBRARY_GLFWSCREENSURFACE_H

#include "openGL.h"
#include <GLFW/glfw3.h>
#include <memory>

#include "../../initializer/glLoaderInitializer.h"

#include "../screenSurface.h"
#include "glfwWindow.h"

namespace gl {
namespace internal {

class GLfwScreenSurface : public ScreenSurface {
 public:
  GLfwScreenSurface(Window &window, GLLoaderInitializer& glLoaderInitializer);
  ~GLfwScreenSurface() final;

  void *getPlatformSurface() final;
  const void *getPlatformSurface() const final;

  RenderingContext* getRenderingContext() final;
 private:
  Window *window;
  GLLoaderInitializer *loaderInitializer;
  ::std::unique_ptr<RenderingContext> renderingContext;
};

}
}

#endif //GRAPHICLIBRARY_GLFWSCREENSURFACE_H
