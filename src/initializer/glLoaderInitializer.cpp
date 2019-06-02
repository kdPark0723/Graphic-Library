//
// Created by siyualbak on 19. 6. 2.
//

#include "initializer/glLoaderInitializer.h"

#include "exception/exception.h"
#include "exception/invalidValueException.h"
#include "exception/invalidOperationException.h"
#include "exception/invalidEnumException.h"

bool gl::GLLoaderInitializer::isInited = false;

gl::Exception getException(GLenum type, const GLchar *message) {
  switch (type) {
    case GL_INVALID_VALUE:return gl::InvalidValueException{message};
    case GL_INVALID_OPERATION:return gl::InvalidOperationException{message};
    case GL_INVALID_ENUM:return gl::InvalidEnumException{message};
  }

  return gl::Exception{message};
}

void gl::GLLoaderInitializer::errorCallback(GLenum source,
                                            GLenum type,
                                            GLuint id,
                                            GLenum severity,
                                            GLsizei length,
                                            const GLchar *message,
                                            const void *userParam) {
  throw getException(type, message);
}

void gl::GLLoaderInitializer::init() {
#if defined(_DEBUG) || defined(DEBUG)
  if (!isInited) {
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(errorCallback, 0);

    isInited = true;
  }
#endif
}
