//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/glfwContext.h"

#include <GLFW/glfw3.h>
#include <sstream>

#include "exception/cantLoadException.h"
#include "exception/notSupportException.h"
#include "exception/internalLibraryException.h"

gl::GLFWInitializer::GLFWInitializer(const gl::Initializer::Version &version)
  : version{version}, isInited{false} {
  if (mainInitializer == nullptr)
    mainInitializer = this;
}

gl::GLFWInitializer::~GLFWInitializer() {
  if (mainInitializer == this)
    mainInitializer = nullptr;
  if (isInited)
    glfwTerminate();
}

void gl::GLFWInitializer::init() {
  glfwSetErrorCallback(errorCallback);

  if (!glfwInit())
    throw CantLoadException{"gl::GLFWInitializer::init: Can't init glfw."};

  isInited = true;

  glfwWindowHint(GLFW_VERSION_MAJOR, version.minor);
  glfwWindowHint(GLFW_VERSION_MAJOR, version.minor);
}

void gl::GLFWInitializer::errorCallback(int errorCode, const char *errorDescription) {
  std::stringstream error{};
  error << "gl::GLFWInitializer::errorCallback: ErrorCode[" << errorCode << "]: " << errorDescription;

  throw InternalLibraryException{error.str()};
}
