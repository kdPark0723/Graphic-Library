//
// Created by siyualbak on 19. 5. 26.
//

#include "window/size.h"

bool gl::operator!=(const gl::Size &lhs, const gl::Size &rhs) {
  return !(lhs == rhs);
}
bool gl::operator==(const gl::Size &lhs, const gl::Size &rhs) {
  return lhs.width == rhs.width && lhs.height == rhs.height;
}

