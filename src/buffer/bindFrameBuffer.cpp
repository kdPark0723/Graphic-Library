//
// Created by siyualbak on 19. 5. 26.
//

#include "buffer/bindFrameBuffer.h"

#include "openGL.h"
#include "util/converGLTypes.h"

gl::BindFrameBuffer::BindFrameBuffer(RenderingContext &context, const gl::FrameBuffer::Buffer &buffer)
  : context{&context}, buffer{buffer} {
}
gl::BindFrameBuffer::~BindFrameBuffer() = default;

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLint *value) {
  context->makeCurrent();

  glClearBufferiv(util::getGLenum(buffer), drawBuffer, value);
}

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLuint *value) {
  context->makeCurrent();

  glClearBufferuiv(util::getGLenum(buffer), drawBuffer, value);
}

//void gl::BindFrameBuffer::clear(const gl::FrameBuffer::Buffer &buffer, GLint drawBuffer, const GLfloat &value) {
//  context->makeCurrent();
//
//  glClearBufferfi(util::getGLenum(buffer), drawBuffer, value);
//}

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLfloat *value) {
  context->makeCurrent();

  glClearBufferfv(util::getGLenum(buffer), drawBuffer, value);
}

