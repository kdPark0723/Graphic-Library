//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GLFWCONTEXT_H
#define GRAPHICLIBRARY_GLFWCONTEXT_H

#include "context.h"

namespace gl {

class GLFWContext : public Context {
 public:
  explicit GLFWContext(const Version &version);
  ~GLFWContext() override;

  void init() override;

 private:
  static void errorCallback(int errorCode, const char* errorDescription);

  Version version;
  bool isInited;
};

}

#endif //GRAPHICLIBRARY_GLFWCONTEXT_H
