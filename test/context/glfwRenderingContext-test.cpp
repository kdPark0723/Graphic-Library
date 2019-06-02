//
// Created by siyualbak on 19. 5. 26.
//

#include "context/internal/glfwRenderingContext.h"

#include <gtest/gtest.h>

#include "initializer/internal/glfwInitializer.h"
#include "initializer/internal/gl3wInitializer.h"
#include "window/internal/glfwScreenSurface.h"
#include "window/internal/glfwWindow.h"

TEST(GLFWRenderingContext_ConstructorAndDestructor, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow glfwWindow{"Test", {1024, 768}};
  gl::internal::GLfwScreenSurface glfwWindowSurface{glfwWindow, gl3WInitializer};
  gl::internal::GLfwRenderingContext{glfwWindowSurface, gl3WInitializer};
}

TEST(GLFWRenderingContext_MakeCurrent, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow glfwWindow{"Test", {1024, 768}};
  gl::internal::GLfwScreenSurface glfwWindowSurface{glfwWindow, gl3WInitializer};
  gl::internal::GLfwRenderingContext glfwRenderingContext{glfwWindowSurface, gl3WInitializer};

  glfwRenderingContext.makeCurrent();

  ASSERT_EQ(glfwGetCurrentContext(), glfwWindowSurface.getPlatformSurface());
}

TEST(GLFWRenderingContext_DoneCurrent, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow glfwWindow{"Test", {1024, 768}};
  gl::internal::GLfwScreenSurface glfwWindowSurface{glfwWindow, gl3WInitializer};
  gl::internal::GLfwRenderingContext glfwRenderingContext{glfwWindowSurface, gl3WInitializer};

  glfwRenderingContext.makeCurrent();
  glfwRenderingContext.doneCurrent();

  ASSERT_NE(glfwGetCurrentContext(), glfwWindowSurface.getPlatformSurface());
}

TEST(GLFWRenderingContext_GetFrameBuffer, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLfwWindow glfwWindow{"Test", {1024, 768}};
  gl::internal::GLfwScreenSurface glfwWindowSurface{glfwWindow, gl3WInitializer};
  gl::internal::GLfwRenderingContext glfwRenderingContext{glfwWindowSurface, gl3WInitializer};
  glfwRenderingContext.makeCurrent();

  auto frameBuffer = glfwRenderingContext.getFrameBuffer(gl::FrameBuffer::Buffer::Color);
}