//
// Created by siyualbak on 19. 5. 26.
//

#include "factory/internal/glfwFactory.h"

#include <gtest/gtest.h>

TEST(GLFWFactory_ConstructorAndDestructor_normal_test, normal) {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};
}

TEST(GLFWFactory_CreateWindowSurface_normal_test, normal) {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
}

TEST(GLFWFactory_CreateRenderingContext_normal_test, normal) {
  gl::internal::GLFWFactory glfwFactory{{4, 3}};

  auto surface = glfwFactory.createWindowSurface("Test", {1024, 768});
  auto rendererContext = glfwFactory.createRenderingContext(*surface);
}