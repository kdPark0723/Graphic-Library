//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/internal/gl3wInitializer.h"

#include <gtest/gtest.h>

#include "factory/internal/glfwFactory.h"

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"

TEST(GL3WInitializer_ConstructorAndDestructor, normal) {
  gl::internal::GL3WInitializer{{4, 3}};
}

TEST(GL3WInitializer_init, normal) {
  gl::internal::GL3WInitializer gl3WInitializer{{100, 100}};

  ASSERT_THROW(gl3WInitializer.init(), gl::NotSupportException);
}