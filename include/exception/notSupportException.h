//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_NOTSUPPORTEXCEPTION_H
#define GRAPHICLIBRARY_NOTSUPPORTEXCEPTION_H

#include "exception.h"

namespace gl {

class NotSupportException : public Exception {
 public:
  explicit NotSupportException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_NOTSUPPORTEXCEPTION_H
