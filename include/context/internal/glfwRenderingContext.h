//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_GLFWRENDERINGCONTEXT_H
#define GRAPHICLIBRARY_GLFWRENDERINGCONTEXT_H

#include "../../initializer/glLoaderInitializer.h"
#include "../renderingContext.h"
#include "../../window/surface.h"

namespace gl {
namespace internal {

class GLfwRenderingContext : public RenderingContext {
 public:
  explicit GLfwRenderingContext(Surface &surface, GLLoaderInitializer& glLoaderInitializer);
  ~GLfwRenderingContext() final;

  void doneCurrent() final;
  void makeCurrent() final;

  void swapBuffers() final;
 private:
  void makeCurrent(Surface *surface);

  Surface *surface;
  GLLoaderInitializer* glLoaderInitializer;
};

}
}

#endif //GRAPHICLIBRARY_GLFWRENDERINGCONTEXT_H
