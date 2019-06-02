//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_INVALIDENUMEXCEPTION_H
#define GRAPHICLIBRARY_INVALIDENUMEXCEPTION_H

#include "exception.h"

namespace gl {

class InvalidEnumException : public Exception {
 public:
  explicit InvalidEnumException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_INVALIDENUMEXCEPTION_H
