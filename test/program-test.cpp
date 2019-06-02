//
// Created by siyualbak on 19. 5. 31.
//

#include <gtest/gtest.h>

#include "program.h"

TEST(Program_ConstructorAndDestructor, normal) {
  gl::Program program{{4, 3}};
}

TEST(Program_GetFactory, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();

  ASSERT_NE(factory, nullptr);
}