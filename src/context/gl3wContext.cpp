//
// Created by siyualbak on 19. 5. 22.
//

#include "context/gl3wContext.h"

#include <GL/gl3w.h>
#include <sstream>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"

gl::GL3WContext::GL3WContext(const gl::Context::Version &version)
  : version{version} {
}

gl::GL3WContext::~GL3WContext() = default;

void gl::GL3WContext::init() {
  if (!gl3wInit())
    throw CantInitException{"gl::GL3WInitializer::init: Can't load gl."};
  if (!gl3wIsSupported(version.major, version.minor)) {
    std::stringstream error{};
    error << "gl::GL3WInitializer::init: " << version.major << "." << version.minor << " is not supported.";

    throw NotSupportException{error.str()};
  }
}
