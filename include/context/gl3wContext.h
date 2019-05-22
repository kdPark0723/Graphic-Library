//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GL3WCONTEXT_H
#define GRAPHICLIBRARY_GL3WCONTEXT_H

#include "context.h"

namespace gl {

class GL3WInitializer : public Initializer {
 public:
  explicit GL3WInitializer(const Version &version);
  ~GL3WInitializer() override;

  void init() override;

 private:
  Version version;
};

}

#endif //GRAPHICLIBRARY_GL3WCONTEXT_H
