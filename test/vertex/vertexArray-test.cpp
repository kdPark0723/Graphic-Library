//
// Created by siyualbak on 19. 6. 2.
//

#include <gtest/gtest.h>

#include "program.h"
#include "vertex/vertexArray.h"

TEST(VertexArray_constructorAndDestructor, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::VertexArray{1};
}

TEST(VertexArray_bind, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::VertexArray vertexArray{1};

  vertexArray.bind();
}