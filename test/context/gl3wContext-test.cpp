//
// Created by siyualbak on 19. 5. 22.
//

#include "context/gl3wContext.h"

#include <gtest/gtest.h>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"

TEST(GL3WInitializer_ConstructorAndDestructor_normal_Test, normal) {
  gl::GL3WContext gl3WContext{{4, 3}};
}

TEST(GL3WInitializer_init_normal_Test, normal) {
  gl::GL3WContext gl3WContext{{100, 100}};

  ASSERT_THROW(gl3WContext.init(), gl::NotSupportException);
}