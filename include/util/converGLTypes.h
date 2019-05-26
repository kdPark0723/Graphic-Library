//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_CONVERGLTYPES_H
#define GRAPHICLIBRARY_CONVERGLTYPES_H

#include "../openGL.h"

namespace gl {
namespace util {

template<typename Integer>
constexpr GLenum getGLenum(Integer value) {
  return static_cast<GLenum>(value);
}

template<typename Integer>
constexpr GLenum getGLsizeiptr(Integer size) {
  return static_cast<GLsizeiptr>(size);
}

template<typename Integer>
constexpr GLenum getGLintptr(Integer value) {
  return static_cast<GLintptr>(value);
}

template<typename Integer>
constexpr GLshort getGLshort(Integer value) {
  return static_cast<GLshort>(value);
}

template<typename Integer>
constexpr GLint getGLint(Integer value) {
  return static_cast<GLint>(value);
}

template<typename Integer>
constexpr GLuint getGLuint(Integer value) {
  return static_cast<GLuint>(value);
}

template<typename FloatingPoint>
constexpr GLfloat getGLfloat(FloatingPoint value) {
  return static_cast<GLfloat>(value);
}

template<typename FloatingPoint>
constexpr GLdouble getGLdouble(FloatingPoint value) {
  return static_cast<GLdouble>(value);
}
}

}

#endif //GRAPHICLIBRARY_CONVERGLTYPES_H
