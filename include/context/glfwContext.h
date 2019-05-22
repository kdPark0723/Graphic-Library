//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GLFWCONTEXT_H
#define GRAPHICLIBRARY_GLFWCONTEXT_H

#include "context.h"

namespace gl {

class GLFWInitializer : public Initializer {
 public:
  explicit GLFWInitializer(const Version &version);
  ~GLFWInitializer() override;

  void init() override;

 private:
  static void errorCallback(int errorCode, const char* errorDescription);

  static GLFWInitializer *mainInitializer;

  Version version;
  bool isInited;
};

}

#endif //GRAPHICLIBRARY_GLFWCONTEXT_H
