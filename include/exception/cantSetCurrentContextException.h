//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_CANTSETCURRENTCONTEXTEXCEPTION_H
#define GRAPHICLIBRARY_CANTSETCURRENTCONTEXTEXCEPTION_H

#include "exception.h"

namespace gl {

class CantSetCurrentContextException : public Exception {
 public:
  explicit CantSetCurrentContextException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_CANTSETCURRENTCONTEXTEXCEPTION_H
