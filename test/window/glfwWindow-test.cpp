//
// Created by siyualbak on 19. 5. 26.
//

#include "window/internal/glfwWindow.h"

#include <gtest/gtest.h>

#include "initializer/internal/glfwInitializer.h"

#include "exception/internalLibraryException.h"

TEST(GLFWWindow_ConstructorAndDestructor, normal) {
  {
    gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
    glfwInitializer.init();

    gl::internal::GLfwWindow{"Test", {1024, 768}};
  }
  {
    gl::internal::GLFWInitializer glfwInitializer{{100, 100}};
    glfwInitializer.init();

    ASSERT_THROW(gl::internal::GLfwWindow("Test", {1024, 768}), gl::InternalLibraryException);
  }
}

TEST(GLFWWindow_GetTitle, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  std::string title{"Test"};
  gl::internal::GLfwWindow glfwWindowSurface{title, {1024, 768}};
  ASSERT_EQ(title, glfwWindowSurface.getTitle());
}

TEST(GLFWWindow_GetSize, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();

  gl::Size size{1024, 768};
  gl::Size diffSize{1024, 1024};
  gl::internal::GLfwWindow glfwWindowSurface{"Test", size};

  ASSERT_EQ(size, glfwWindowSurface.getSize());
  ASSERT_NE(diffSize, glfwWindowSurface.getSize());
}
