//
// Created by siyualbak on 19. 5. 26.
//

#include "context/internal/glfwRenderingContext.h"

#include <GLFW/glfw3.h>

#include "exception/cantSetCurrentContextException.h"

gl::internal::GLFWRenderingContext::GLFWRenderingContext(gl::Surface &surface)
  : surface{&surface} {
}

gl::internal::GLFWRenderingContext::~GLFWRenderingContext() {
}

void gl::internal::GLFWRenderingContext::doneCurrent() {
  makeCurrent(nullptr);
}

void gl::internal::GLFWRenderingContext::makeCurrent() {
  makeCurrent(surface);
}

void gl::internal::GLFWRenderingContext::makeCurrent(Surface *surface) {
  try {
    if (surface != nullptr)
      glfwMakeContextCurrent(static_cast<GLFWwindow *>(surface->getPlatformSurface()));
    else
      glfwMakeContextCurrent(nullptr);
  } catch (...) {
    throw CantSetCurrentContextException{"gl::internal::GLFWRenderingContext: Can't make context current."};
  }
}

void gl::internal::GLFWRenderingContext::swapBuffers() {
  glfwSwapBuffers(static_cast<GLFWwindow *>(surface->getPlatformSurface()));
  glfwPollEvents();
}

