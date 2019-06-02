//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_VERTEXARRAY_H
#define GRAPHICLIBRARY_VERTEXARRAY_H

#include "openGL.h"

namespace gl {

class VertexArray {
 public:
  inline explicit VertexArray(size_t size);
  inline ~VertexArray();

  inline void bind();

 private:
  GLuint arrays;
  GLsizei size;
};

}

#include "vertexArray-inc.h"

#endif //GRAPHICLIBRARY_VERTEXARRAY_H
