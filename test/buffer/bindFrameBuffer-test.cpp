//
// Created by siyualbak on 19. 5. 26.
//

#include "buffer/bindFrameBuffer.h"

#include <gtest/gtest.h>

#include "factory/internal/glfwFactory.h"
#include "initializer/internal/gl3wInitializer.h"

TEST(BindFrameBuffer_ConstructorAndDestructor_normal_test, normal) {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
  auto rendererContext = glfwFactory.createRenderingContext(*surface);
  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
}

TEST(BindFrameBuffer_Clear_normal_test, normal) {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
  auto rendererContext = glfwFactory.createRenderingContext(*surface);

  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};

  try {
    gl3WInitializer.init();
  } catch (...) {
  }

  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);

  GLint ints[] = {0, 0, 0, 0};
  frameBuffer->clear(0, ints);

  GLuint uints[] = {0, 0, 0, 0};
  frameBuffer->clear(0, uints);

  GLfloat floats[] = {0, 0, 0, 0};
  frameBuffer->clear(0, floats);
}