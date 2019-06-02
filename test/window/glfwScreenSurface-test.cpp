//
// Created by siyualbak on 19. 5. 29.
//
#include <gtest/gtest.h>

#include "window/internal/glfwScreenSurface.h"

#include "initializer/internal/glfwInitializer.h"
#include "initializer/internal/gl3wInitializer.h"
#include "window/internal/glfwWindow.h"

TEST(GLFWSceenSurface_ConstructorAndDestructor, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow window{"Test", {1024, 768}};

  gl::internal::GLfwScreenSurface{window, gl3WInitializer};
}

TEST(GLFWSceenSurface_GetRenderingContext, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow window{"Test", {1024, 768}};

  gl::internal::GLfwScreenSurface surface{window, gl3WInitializer};

  auto renderingContext = surface.getRenderingContext();

  ASSERT_NE(renderingContext, nullptr);
}