//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_GL3WCONTEXT_H
#define GRAPHICLIBRARY_GL3WCONTEXT_H

#include "context.h"

namespace gl {

class GL3WContext : public Context {
 public:
  explicit GL3WContext(const Version &version);
  ~GL3WContext() override;

  void init() override;

 private:
  Version version;
};

}

#endif //GRAPHICLIBRARY_GL3WCONTEXT_H
