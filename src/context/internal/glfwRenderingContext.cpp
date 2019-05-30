//
// Created by siyualbak on 19. 5. 26.
//

#include "context/internal/glfwRenderingContext.h"

#include <GLFW/glfw3.h>

#include "exception/cantSetCurrentContextException.h"

gl::internal::GLfwRenderingContext::GLfwRenderingContext(gl::Surface &surface, GLLoaderInitializer& glLoaderInitializer)
  : surface{&surface}, glLoaderInitializer{&glLoaderInitializer} {
}

gl::internal::GLfwRenderingContext::~GLfwRenderingContext() = default;

void gl::internal::GLfwRenderingContext::doneCurrent() {
  makeCurrent(nullptr);
}

void gl::internal::GLfwRenderingContext::makeCurrent() {
  makeCurrent(surface);
}

void gl::internal::GLfwRenderingContext::makeCurrent(Surface *surface) {
  try {
    if (surface != nullptr)
      glfwMakeContextCurrent(static_cast<GLFWwindow *>(surface->getPlatformSurface()));
    else
      glfwMakeContextCurrent(nullptr);
    glLoaderInitializer->init();
  } catch (...) {
    throw CantSetCurrentContextException{"gl::internal::GLFWRenderingContext: Can't make context current."};
  }
}

void gl::internal::GLfwRenderingContext::swapBuffers() {
  glfwSwapBuffers(static_cast<GLFWwindow *>(surface->getPlatformSurface()));
  glfwPollEvents();
}

