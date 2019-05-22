//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/gl3wContext.h"

#include <GL/gl3w.h>
#include <sstream>

#include "exception/cantLoadException.h"
#include "exception/notSupportException.h"

gl::GL3WInitializer::GL3WInitializer(const gl::Initializer::Version &version)
  : version{version} {
}

gl::GL3WInitializer::~GL3WInitializer() = default;

void gl::GL3WInitializer::init() {
  if (!gl3wInit())
    throw CantLoadException{"gl::GL3WInitializer::init: Can't load gl."};
  if (!gl3wIsSupported(version.major, version.minor)) {
    std::stringstream error{};
    error << "gl::GL3WInitializer::init: " << version.major << "." << version.minor << " is not supported.";

    throw NotSupportException{error.str()};
  }
}
