//
// Created by siyualbak on 19. 5. 26.
//

#include "buffer/bindFrameBuffer.h"

#include <gtest/gtest.h>

#include "factory/internal/glfwFactory.h"
#include "initializer/internal/gl3wInitializer.h"

TEST(BindFrameBuffer_ConstructorAndDestructor_normal_test, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWFactory glfwFactory{{4, 3}, gl3WInitializer};

  auto window = glfwFactory.createWindow("Test", {1024, 768});
  auto surface = glfwFactory.createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
}

TEST(BindFrameBuffer_Clear_normal_test, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWFactory glfwFactory{{4, 3}, gl3WInitializer};

  auto window = glfwFactory.createWindow("Test", {1024, 768});
  auto surface = glfwFactory.createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);

  rendererContext->makeCurrent();

  GLint ints[] = {0, 0, 0, 0};
  frameBuffer->clear(0, ints);

  GLuint uints[] = {0, 0, 0, 0};
  frameBuffer->clear(0, uints);

  GLfloat floats[] = {0, 0, 0, 0};
  frameBuffer->clear(0, floats);
}