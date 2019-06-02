//
// Created by siyualbak on 19. 6. 2.
//

#include "shader/shader.h"

#include <string>
#include <fstream>
#include <sstream>

::std::string gl::Shader::readShaderCode(const ::std::string &file) {
  std::string shaderSource;
  std::ifstream shaderStream{file.c_str()};

  if (shaderStream.is_open()) {
    std::stringstream stringStream{};

    stringStream << shaderStream.rdbuf();
    shaderSource = stringStream.str();

    shaderStream.close();
  } else {
// Todo throw exception
  }

  return shaderSource;
}