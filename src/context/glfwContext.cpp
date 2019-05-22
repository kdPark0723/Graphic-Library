//
// Created by siyualbak on 19. 5. 22.
//

#include "context/glfwContext.h"

#include <GLFW/glfw3.h>
#include <sstream>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"
#include "exception/internalLibraryException.h"

gl::GLFWContext::GLFWContext(const gl::Context::Version &version)
  : version{version}, isInited{false} {
}

gl::GLFWContext::~GLFWContext() {
  if (isInited)
    glfwTerminate();
}

void gl::GLFWContext::init() {
  glfwSetErrorCallback(errorCallback);

  if (!glfwInit())
    throw CantInitException{"gl::GLFWContext::init: Can't init glfw."};

  isInited = true;

  glfwWindowHint(GLFW_VERSION_MAJOR, version.minor);
  glfwWindowHint(GLFW_VERSION_MAJOR, version.minor);

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void gl::GLFWContext::errorCallback(int errorCode, const char *errorDescription) {
  std::stringstream error{};
  error << "gl::GLFWContext::errorCallback: ErrorCode[" << errorCode << "]: " << errorDescription;

  throw InternalLibraryException{error.str()};
}
