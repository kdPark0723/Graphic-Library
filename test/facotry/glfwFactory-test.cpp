//
// Created by siyualbak on 19. 5. 26.
//

#include <gtest/gtest.h>

#include "factory/internal/glfwFactory.h"
#include "initializer/internal/gl3wInitializer.h"

TEST(GLFWFactory_ConstructorAndDestructor, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWFactory glfwFactory{{4, 3}, gl3WInitializer};
}

TEST(GLFWFactory_CreateWindow, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWFactory glfwFactory{{4, 3}, gl3WInitializer};

  auto window = glfwFactory.createWindow("Test", {1024, 768});
}

TEST(GLFWFactory_CreateScreenSurface, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{4, 3}};
  gl::internal::GLFWFactory glfwFactory{{4, 3}, gl3WInitializer};

  auto window = glfwFactory.createWindow("Test", {1024, 768});
  auto surface = glfwFactory.createScreenSurface(*window);
}