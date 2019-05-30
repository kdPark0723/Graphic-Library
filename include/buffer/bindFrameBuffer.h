//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_BINDFRAMEBUFFER_H
#define GRAPHICLIBRARY_BINDFRAMEBUFFER_H

#include "frameBuffer.h"

#include "../context/renderingContext.h"

namespace gl {

class BindFrameBuffer : public FrameBuffer {
 public:
  explicit BindFrameBuffer(RenderingContext &context, const FrameBuffer::Buffer &buffer);
  ~BindFrameBuffer() final;

  inline void clear(GLint drawBuffer, const GLint *value) final;
  inline void clear(GLint drawBuffer, const GLuint *value) final;
//  void clear(const Buffer &buffer, GLint drawBuffer, const GLfloat &value) final;
  inline void clear(GLint drawBuffer, const GLfloat *value) final;

 private:
  RenderingContext *context;
  FrameBuffer::Buffer buffer;
};

}

#include "bindFrameBuffer-inc.h"

#endif //GRAPHICLIBRARY_BINDFRAMEBUFFER_H
