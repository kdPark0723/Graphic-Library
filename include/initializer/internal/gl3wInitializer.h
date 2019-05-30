//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GL3WINITIALIZER_H
#define GRAPHICLIBRARY_GL3WINITIALIZER_H

#include "initializer/glLoaderInitializer.h"

namespace gl {
namespace internal {

class GL3WInitializer : public GLLoaderInitializer {
 public:
  explicit GL3WInitializer(const Version &version);
  ~GL3WInitializer() override;

  void init() override;

 private:
  static bool isInited;
  Version version;
};

}
}

#endif //GRAPHICLIBRARY_GL3WINITIALIZER_H
