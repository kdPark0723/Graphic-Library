//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_VERTEXARRAY_INC_H
#define GRAPHICLIBRARY_VERTEXARRAY_INC_H

#include "vertexArray.h"

#include "openGL.h"
#include "util/converGLTypes.h"

gl::VertexArray::VertexArray(size_t size)
  : arrays{0}, size{util::getGLsizei(size)} {
  glGenVertexArrays(this->size, &arrays);
}

gl::VertexArray::~VertexArray() {
  glDeleteVertexArrays(size, &arrays);
}

void gl::VertexArray::bind() {
  glBindVertexArray(arrays);
}

#endif //GRAPHICLIBRARY_VERTEXARRAY_INC_H
