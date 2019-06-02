//
// Created by siyualbak on 19. 5. 22.
//

//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/internal/glfwInitializer.h"

#include <gtest/gtest.h>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"
#include "exception/internalLibraryException.h"

TEST(GLFWInitializer_ConstructorAndDestructor, normal) {
  gl::internal::GLFWInitializer{{4, 3}};
}

TEST(GLFWInitializer_init, normal) {
  gl::internal::GLFWInitializer glfwInitializer{{4, 3}};
  glfwInitializer.init();
}