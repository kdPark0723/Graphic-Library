//
// Created by siyualbak on 19. 5. 30.
//

#ifndef GRAPHICLIBRARY_SIZE_INC_H
#define GRAPHICLIBRARY_SIZE_INC_H

#include "size.h"

bool gl::operator!=(const gl::Size &lhs, const gl::Size &rhs) {
  return !(lhs == rhs);
}
bool gl::operator==(const gl::Size &lhs, const gl::Size &rhs) {
  return lhs.width == rhs.width && lhs.height == rhs.height;
}

#endif //GRAPHICLIBRARY_SIZE_INC_H
