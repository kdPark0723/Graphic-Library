//
// Created by siyualbak on 19. 5. 30.
//

#ifndef GRAPHICLIBRARY_BINDFRAMEBUFFER_INC_H
#define GRAPHICLIBRARY_BINDFRAMEBUFFER_INC_H

#include "bindFrameBuffer.h"

#include "openGL.h"
#include "util/converGLTypes.h"

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLint *value) {
  glClearBufferiv(util::getGLenum(buffer), drawBuffer, value);
}

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLuint *value) {
  glClearBufferuiv(util::getGLenum(buffer), drawBuffer, value);
}

//void gl::BindFrameBuffer::clear(const gl::FrameBuffer::Buffer &buffer, GLint drawBuffer, const GLfloat &value) {
//
//  glClearBufferfi(util::getGLenum(buffer), drawBuffer, value);
//}

void gl::BindFrameBuffer::clear(GLint drawBuffer, const GLfloat *value) {
  glClearBufferfv(util::getGLenum(buffer), drawBuffer, value);
}

#endif //GRAPHICLIBRARY_BINDFRAMEBUFFER_INC_H
