//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_CANTINITEXCEPTION_H
#define GRAPHICLIBRARY_CANTINITEXCEPTION_H

#include "exception.h"

namespace gl {

class CantInitException : public Exception {
 public:
  explicit CantInitException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_CANTINITEXCEPTION_H
