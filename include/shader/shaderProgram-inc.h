//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_SHADERPROGRAM_INC_H
#define GRAPHICLIBRARY_SHADERPROGRAM_INC_H

#include "shaderProgram.h"

#include "openGL.h"

gl::ShaderProgram::ShaderProgram() {
  program = glCreateProgram();
}

gl::ShaderProgram::ShaderProgram(gl::ShaderProgram &&rhs) noexcept {
  program = rhs.program;
  rhs.program = 0;
}

gl::ShaderProgram::~ShaderProgram() {
  if (program != 0)
    glDeleteProgram(program);
}

void gl::ShaderProgram::attach(gl::Shader &shader) {
  glAttachShader(program, shader.shader);
}

void gl::ShaderProgram::link() {
  glLinkProgram(program);
}

void gl::ShaderProgram::use() {
  glUseProgram(program);
}

gl::ShaderProgram &gl::ShaderProgram::operator=(gl::ShaderProgram &&rhs) {
  if (program != 0)
    glDeleteProgram(program);

  program = rhs.program;
  rhs.program = 0;

  return *this;
}

#endif //GRAPHICLIBRARY_SHADERPROGRAM_INC_H
