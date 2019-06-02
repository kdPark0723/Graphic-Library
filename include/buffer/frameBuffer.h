//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_FRAMBUFFER_H
#define GRAPHICLIBRARY_FRAMBUFFER_H

#include "buffer.h"

#include "../openGL.h"

namespace gl {

class FrameBuffer : public Buffer {
 public:
  enum class Buffer {
    Color = GL_COLOR,
    Depth = GL_DEPTH,
    Stencil = GL_STENCIL,
  };

  FrameBuffer() = default;
  ~FrameBuffer() override = default;

  virtual void clear(GLint drawBuffer, const GLint *value) = 0;
  virtual void clear(GLint drawBuffer, const GLuint *value) = 0;
//  virtual void clear(const Buffer &buffer, GLint drawBuffer, const GLfloat &value) = 0;
  virtual void clear(GLint drawBuffer, const GLfloat *value) = 0;
};

}

#endif //GRAPHICLIBRARY_FRAMBUFFER_H
