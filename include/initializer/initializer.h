//
// Created by siyualbak on 19. 5. 21.
//

#ifndef GRAPHICLIBRARY_INITIALIZER_H
#define GRAPHICLIBRARY_INITIALIZER_H

namespace gl {

class Initializer {
 public:
  struct Version {
    int major, minor;
  };

  Initializer() = default;
  virtual ~Initializer() = default;

  virtual void init() = 0;
};

}

#endif //GRAPHICLIBRARY_INITIALIZER_H
