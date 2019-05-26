//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/internal/glfwInitializer.h"

#include <GLFW/glfw3.h>
#include <sstream>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"
#include "exception/internalLibraryException.h"

gl::internal::GLFWInitializer::GLFWInitializer(const gl::Initializer::Version &version)
  : version{version}, isInited{false} {
}

gl::internal::GLFWInitializer::~GLFWInitializer() {
  if (isInited)
    glfwTerminate();
}

void gl::internal::GLFWInitializer::init() {
  glfwSetErrorCallback(errorCallback);

  if (!glfwInit())
    throw CantInitException{"gl::GLFWContext::init: Can't init glfw."};

  isInited = true;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version.major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version.minor);

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void gl::internal::GLFWInitializer::errorCallback(int errorCode, const char *errorDescription) {
  std::stringstream error{};
  error << "gl::GLFWContext::errorCallback: ErrorCode[" << errorCode << "]: " << errorDescription;

  throw InternalLibraryException{error.str()};
}
