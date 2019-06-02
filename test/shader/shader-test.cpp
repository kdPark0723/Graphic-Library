//
// Created by siyualbak on 19. 6. 2.
//

#include <gtest/gtest.h>

#include "shader/shader.h"
#include "program.h"

#include "exception/shaderCompileException.h"

TEST(Shader_constructorAndDestructor, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::Shader shader{gl::Shader::Type::Vertex};
}

TEST(Shader_getType, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::Shader shader{gl::Shader::Type::Vertex};

  ASSERT_EQ(shader.getType(), gl::Shader::Type::Vertex);
}

TEST(Shader_source, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::Shader shader{gl::Shader::Type::Vertex};

  static const GLchar vertexShader[] = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
    "}"
  };
  shader.source(vertexShader);
}

TEST(Shader_complie, ComplieCorrectCode) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::Shader shader{gl::Shader::Type::Vertex};

  static const GLchar vertexShader[] = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
    "}"
  };
  shader.source(vertexShader);
  shader.compile();
}

TEST(Shader_complie, ComplieWorngCode) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::Shader shader{gl::Shader::Type::Vertex};

  static const GLchar vertexShader[] = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0,\n"
    "}"
  };
  shader.source(vertexShader);
  ASSERT_THROW(shader.compile(), gl::ShaderCompileException);
}

TEST(Shader_readShaderCode, normal) {
  static const std::string vertexShader = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
    "}"
  };

  auto code = gl::Shader::readShaderCode("/mnt/d/Project/GraphicLibrary /test/asset/shader/trueVertexShader.glsl");

  ASSERT_EQ(code, vertexShader);
}
