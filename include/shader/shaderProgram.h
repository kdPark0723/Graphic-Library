//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_SHADERPROGRAM_H
#define GRAPHICLIBRARY_SHADERPROGRAM_H

#include "shader.h"

namespace gl {

class ShaderProgram {
 public:
  inline ShaderProgram();
  ShaderProgram(const ShaderProgram &other) = delete;
  inline ShaderProgram(ShaderProgram &&rhs) noexcept;

  inline ~ShaderProgram();

  inline void attach(Shader &shader);
  inline void link();
  inline void use();

  ShaderProgram &operator=(const ShaderProgram &rhs) = delete;
  inline ShaderProgram &operator=(ShaderProgram &&rhs);

 private:
  GLuint program;
};

}

#include "shaderProgram-inc.h"

#endif //GRAPHICLIBRARY_SHADERPROGRAM_H
