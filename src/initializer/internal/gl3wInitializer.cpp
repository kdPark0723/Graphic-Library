//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/internal/gl3wInitializer.h"

#include <GL/gl3w.h>
#include <sstream>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"

bool gl::internal::GL3WInitializer::isInited = false;

gl::internal::GL3WInitializer::GL3WInitializer(const gl::Initializer::Version &version)
  : version{version} {
}

gl::internal::GL3WInitializer::~GL3WInitializer() = default;

void gl::internal::GL3WInitializer::init() {
  if (!isInited) {
    if (gl3wInit())
      throw CantInitException{"gl::GL3WInitializer::init: Can't load gl."};

    isInited = true;
  }

  if (!gl3wIsSupported(version.major, version.minor)) {
    std::stringstream error{};
    error << "gl::GL3WInitializer::init: " << version.major << "." << version.minor << " is not supported.";

    throw NotSupportException{error.str()};
  }
}
