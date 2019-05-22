//
// Created by siyualbak on 19. 5. 22.
//

//
// Created by siyualbak on 19. 5. 22.
//

#include "context/glfwContext.h"

#include <gtest/gtest.h>

#include "exception/cantInitException.h"
#include "exception/notSupportException.h"
#include "exception/internalLibraryException.h"

TEST(GLFWInitializer_ConstructorAndDestructor_normal_Test, normal) {
  gl::GLFWContext glfwContext{{4, 3}};
}

TEST(GLFWInitializer_init_normal_Test, normal) {
  gl::GLFWContext glfwContext{{100, 100}};

  ASSERT_THROW(glfwContext.init(), gl::InternalLibraryException);
}