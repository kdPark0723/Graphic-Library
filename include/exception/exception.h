//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_EXCEPTION_H
#define GRAPHICLIBRARY_EXCEPTION_H

#include <stdexcept>

namespace gl {

class Exception : public ::std::runtime_error {
 public:
  explicit Exception(const std::string &what_arg)
    : ::std::runtime_error{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_EXCEPTION_H
