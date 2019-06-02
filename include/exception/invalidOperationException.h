//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_INVALIDOPERATIONEXCEPTION_H
#define GRAPHICLIBRARY_INVALIDOPERATIONEXCEPTION_H

#include "exception.h"

namespace gl {

class InvalidOperationException : public Exception {
 public:
  explicit InvalidOperationException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_INVALIDOPERATIONEXCEPTION_H
