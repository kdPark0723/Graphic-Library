//
// Created by siyualbak on 19. 5. 29.
//

#ifndef GRAPHICLIBRARY_GLLOADINITIALIZER_H
#define GRAPHICLIBRARY_GLLOADINITIALIZER_H

#include "initializer.h"
#include "openGL.h"

namespace gl {

class GLLoaderInitializer : public Initializer {
 public:
  GLLoaderInitializer() = default;
  ~GLLoaderInitializer() override = default;

  void init() override;

 private:
  static void errorCallback(GLenum source,
                            GLenum type,
                            GLuint id,
                            GLenum severity,
                            GLsizei length,
                            const GLchar *message,
                            const void *userParam);

  static bool isInited;
};

}

#endif //GRAPHICLIBRARY_GLLOADINITIALIZER_H
