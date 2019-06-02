//
// Created by siyualbak on 19. 6. 2.
//

#ifndef GRAPHICLIBRARY_SHADER_H
#define GRAPHICLIBRARY_SHADER_H

#include <string>
#include "openGL.h"

namespace gl {

class Shader {
 public:
  enum class Type {
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_FRAGMENT_SHADER,
    TessellationControl = GL_TESS_CONTROL_SHADER,
    TessellationEvaluation = GL_TESS_EVALUATION_SHADER,
  };

  inline explicit Shader(const Type &type);
  Shader(const Shader &other) = delete;

  inline ~Shader();

  inline void source(const ::std::string &code);
  inline void compile();

  inline const Type &getType() const;

  static ::std::string readShaderCode(const ::std::string &file);

  Shader &operator=(const Shader &rhs) = delete;

 private:
  const Type type;

  GLuint shader;

  friend class ShaderProgram;
};

}

#include "shader-inc.h"

#endif //GRAPHICLIBRARY_SHADER_H
