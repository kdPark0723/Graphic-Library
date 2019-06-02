//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_RENDERINGCONTEXT_INC_H
#define GRAPHICLIBRARY_RENDERINGCONTEXT_INC_H

#include "renderingContext.h"

#include "../openGL.h"
#include "../util/converGLTypes.h"

void gl::RenderingContext::drawArrays(const gl::RenderingContext::DrawMode &mode, int first, size_t count) {
  glDrawArrays(util::getGLenum(mode), util::getGLint(first), util::getGLsizei(count));
}

void gl::RenderingContext::pointSize(float size) {
  glPointSize(util::getGLfloat(size));
}

#endif //GRAPHICLIBRARY_RENDERINGCONTEXT_INC_H
