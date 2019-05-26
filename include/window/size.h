//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_SIZE_H
#define GRAPHICLIBRARY_SIZE_H

namespace gl {

struct Size {
  int width{}, height{};
};

bool operator!=(const Size &lhs, const Size &rhs);
bool operator==(const Size &lhs, const Size &rhs);

}

#endif //GRAPHICLIBRARY_SIZE_H
