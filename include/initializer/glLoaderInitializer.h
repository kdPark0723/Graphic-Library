//
// Created by siyualbak on 19. 5. 29.
//

#ifndef GRAPHICLIBRARY_GLLOADINITIALIZER_H
#define GRAPHICLIBRARY_GLLOADINITIALIZER_H

#include "initializer.h"

namespace gl {
namespace internal {

class GLLoaderInitializer : public Initializer {
 public:
  GLLoaderInitializer() = default;
  ~GLLoaderInitializer() override = default;
};

}
}

#endif //GRAPHICLIBRARY_GLLOADINITIALIZER_H
