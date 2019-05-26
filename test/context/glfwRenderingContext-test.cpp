//
// Created by siyualbak on 19. 5. 26.
//

#include "context/internal/glfwRenderingContext.h"

#include <gtest/gtest.h>

#include "initializer/internal/glfwInitializer.h"
#include "window/internal/glfwWindowSurface.h"

TEST(GLFWRenderingContext_ConstructorAndDestructor_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLFWWindowSurface glfwWindowSurface{"Test", {1024, 768}};
  gl::internal::GLFWRenderingContext{glfwWindowSurface};
}

TEST(GLFWRenderingContext_MakeCurrent_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLFWWindowSurface glfwWindowSurface{"Test", {1024, 768}};
  gl::internal::GLFWRenderingContext glfwRenderingContext{glfwWindowSurface};

  glfwRenderingContext.makeCurrent();

  ASSERT_EQ(glfwGetCurrentContext(), glfwWindowSurface.getPlatformSurface());
}

TEST(GLFWRenderingContext_DoneCurrent_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLFWWindowSurface glfwWindowSurface{"Test", {1024, 768}};
  gl::internal::GLFWRenderingContext glfwRenderingContext{glfwWindowSurface};

  glfwRenderingContext.makeCurrent();
  glfwRenderingContext.doneCurrent();

  ASSERT_NE(glfwGetCurrentContext(), glfwWindowSurface.getPlatformSurface());
}

TEST(GLFWRenderingContext_GetFrameBuffer_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::internal::GLFWWindowSurface glfwWindowSurface{"Test", {1024, 768}};
  gl::internal::GLFWRenderingContext glfwRenderingContext{glfwWindowSurface};

  auto frameBuffer = glfwRenderingContext.getFrameBuffer(gl::FrameBuffer::Buffer::Color);
}