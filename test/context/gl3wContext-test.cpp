//
// Created by siyualbak on 19. 5. 22.
//

#include "initializer/gl3wContext.h"

#include <gtest/gtest.h>

#include "exception/cantLoadException.h"
#include "exception/notSupportException.h"

TEST(GL3WInitializer_ConstructorAndDestructor_normal_Test, normal) {
  gl::GL3WInitializer gl3WInitializer{{4, 3}};
}

TEST(GL3WInitializer_init_normal_Test, normal) {
  gl::GL3WInitializer gl3WInitializer{{100, 100}};

  ASSERT_THROW(gl3WInitializer.init(), gl::NotSupportException);
}