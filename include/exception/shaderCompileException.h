//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_SHADERCOMPLIEEXCEPTION_H
#define GRAPHICLIBRARY_SHADERCOMPLIEEXCEPTION_H

#include "exception.h"

namespace gl {

class ShaderCompileException : public Exception {
 public:
  explicit ShaderCompileException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_SHADERCOMPLIEEXCEPTION_H
