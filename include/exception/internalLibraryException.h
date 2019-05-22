//
// Created by siyualbak on 19. 5. 22.
//

#ifndef GRAPHICLIBRARY_INTERNALLIBRARYEXCEPTION_H
#define GRAPHICLIBRARY_INTERNALLIBRARYEXCEPTION_H

#include "exception.h"

namespace gl {

class InternalLibraryException : public Exception {
 public:
  explicit InternalLibraryException(const std::string &what_arg)
    : Exception{what_arg} {};
};

}

#endif //GRAPHICLIBRARY_INTERNALLIBRARYEXCEPTION_H
