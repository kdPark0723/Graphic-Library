//
// Created by siyualbak on 19. 5. 26.
//

#include "window/internal/glfwWindowSurface.h"

#include <gtest/gtest.h>

#include "initializer/internal/glfwInitializer.h"

#include "exception/internalLibraryException.h"

TEST(GLFWWindowSurface_ConstructorAndDestructor_normal_test, normal) {
  {
    gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
    glfwInitializer.init();

    gl::internal::GLFWWindowSurface{"Test", {1024, 768}};
  }
  {
    gl::internal::GLFWInitializer glfwInitializer{{100, 100}};
    glfwInitializer.init();

    ASSERT_THROW(gl::internal::GLFWWindowSurface("Test", {1024, 768}), gl::InternalLibraryException);
  }
}

TEST(GLFWWindowSurface_GetTitle_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  std::string title{"Test"};
  gl::internal::GLFWWindowSurface glfwWindowSurface{title, {1024, 768}};
  ASSERT_EQ(title, glfwWindowSurface.getTitle());
}

TEST(GLFWWindowSurface_GetSize_normal_test, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::Size size{1024, 768};
  gl::Size diffSize{1024, 1024};
  gl::internal::GLFWWindowSurface glfwWindowSurface{"Test", size};
  ASSERT_EQ(size, glfwWindowSurface.getSize());
  ASSERT_NE(diffSize, glfwWindowSurface.getSize());
}
