//
// Created by siyualbak on 19. 5. 21.
//

#ifndef GRAPHICLIBRARY_CONTEXT_H
#define GRAPHICLIBRARY_CONTEXT_H

namespace gl {

class Context {
 public:
  struct Version {
    int major, minor;
  };

  Context() = default;
  virtual ~Context() = default;

  virtual void init() = 0;
};

}

#endif //GRAPHICLIBRARY_CONTEXT_H
