//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_INVALIDVALUEEXCEPTION_H
#define GRAPHICLIBRARY_INVALIDVALUEEXCEPTION_H

#include "exception.h"

namespace gl {

class InvalidValueException : public Exception {
 public:
  explicit InvalidValueException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_INVALIDVALUEEXCEPTION_H
