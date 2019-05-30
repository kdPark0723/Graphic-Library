//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_SIZE_H
#define GRAPHICLIBRARY_SIZE_H

namespace gl {

struct Size {
  int width{}, height{};
};

inline bool operator!=(const Size &lhs, const Size &rhs);
inline bool operator==(const Size &lhs, const Size &rhs);

}

#include "size-inc.h"

#endif //GRAPHICLIBRARY_SIZE_H
