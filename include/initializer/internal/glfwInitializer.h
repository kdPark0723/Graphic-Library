//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GLFWINITIALIZER_H
#define GRAPHICLIBRARY_GLFWINITIALIZER_H

#include "initializer/initializer.h"

namespace gl {
namespace internal {

class GLFWInitializer : public Initializer {
 public:
  explicit GLFWInitializer(const Version &version);
  ~GLFWInitializer() override;

  void init() override;

 private:
  static void errorCallback(int errorCode, const char* errorDescription);

  Version version;
  bool isInited;
};

}
}

#endif //GRAPHICLIBRARY_GLFWINITIALIZER_H
