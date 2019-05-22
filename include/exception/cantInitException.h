//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_CANTLOADEXCEPTION_H
#define GRAPHICLIBRARY_CANTLOADEXCEPTION_H

#include "exception.h"

namespace gl {

class CantLoadException : public Exception {
 public:
  explicit CantLoadException(const std::string& what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_CANTLOADEXCEPTION_H
