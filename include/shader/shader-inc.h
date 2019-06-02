//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_SHADER_INC_H
#define GRAPHICLIBRARY_SHADER_INC_H

#include "shader.h"

#include <string>

#include "../util/converGLTypes.h"
#include "../exception/shaderCompileException.h"

gl::Shader::Shader(const Shader::Type &type)
  : type{type} {
  shader = glCreateShader(util::getGLenum(type));
}

gl::Shader::~Shader() {
  if (shader != 0)
    glDeleteShader(shader);
}

void gl::Shader::source(const ::std::string &code) {
  const GLchar *str = code.c_str();

  glShaderSource(shader, 1, &str, nullptr);
}

void gl::Shader::compile() {
  glCompileShader(shader);

  int result;
  int infoLogLength;

  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

  if (infoLogLength > 0) {
    std::string errorMessage{};
    errorMessage.resize(infoLogLength + 1);

    glGetShaderInfoLog(shader,
                       infoLogLength,
                       nullptr,
                       (GLchar *) (errorMessage.data()));
    throw gl::ShaderCompileException{errorMessage};
  }
}

const gl::Shader::Type &gl::Shader::getType() const {
  return type;
}

#endif //GRAPHICLIBRARY_SHADER_INC_H
