//
// Created by siyualbak on 19. 6. 2.
//

#include <gtest/gtest.h>

#include "shader/shaderProgram.h"
#include "shader/shader.h"
#include "program.h"

TEST(ShaderProgram_constructorAndDestructor, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::ShaderProgram shaderProgram{};
}

TEST(ShaderProgram_link, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::ShaderProgram shaderProgram{};

  gl::Shader vertexShader{gl::Shader::Type::Vertex};
  gl::Shader fragmentShader{gl::Shader::Type::Fragment};

  static const GLchar vertexShaderCode[] = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
    "}"
  };
  static const GLchar fragmentShaderCode[] = {
    "#version 430 core\n"
    "\n"
    "out vec4 color;\n"
    "\n"
    "void main() {\n"
    "  color = vec4(0.0, 0.8, 1.0, 1.0);\n"
    "}"
  };

  vertexShader.source(vertexShaderCode);
  vertexShader.compile();

  fragmentShader.source(fragmentShaderCode);
  fragmentShader.compile();

  shaderProgram.attach(vertexShader);
  shaderProgram.attach(fragmentShader);
}

TEST(ShaderProgram_attach, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();

  gl::ShaderProgram shaderProgram{};

  gl::Shader vertexShader{gl::Shader::Type::Vertex};
  gl::Shader fragmentShader{gl::Shader::Type::Fragment};

  static const GLchar vertexShaderCode[] = {
    "#version 430 core\n"
    "\n"
    "void main() {\n"
    "  gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
    "}"
  };
  static const GLchar fragmentShaderCode[] = {
    "#version 430 core\n"
    "\n"
    "out vec4 color;\n"
    "\n"
    "void main() {\n"
    "  color = vec4(0.0, 0.8, 1.0, 1.0);\n"
    "}"
  };

  vertexShader.source(vertexShaderCode);
  vertexShader.compile();

  fragmentShader.source(fragmentShaderCode);
  fragmentShader.compile();

  shaderProgram.attach(vertexShader);
  shaderProgram.attach(fragmentShader);

  shaderProgram.link();
}

