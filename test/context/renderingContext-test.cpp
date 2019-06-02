//
// Created by siyualbak on 19. 6. 2.
//

//
// Created by siyualbak on 19. 5. 26.
//

#include <gtest/gtest.h>

#include "context/renderingContext.h"
#include "program.h"
#include "shader/shaderProgram.h"
#include "shader/shader.h"
#include "vertex/vertexArray.h"

TEST(RenderingContext_constructorAndDestructor, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  surface->getRenderingContext();
}

TEST(RenderingContext_makeCurrent, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();
  rendererContext->makeCurrent();
}

TEST(RenderingContext_doneCurrent, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  rendererContext->makeCurrent();
  rendererContext->doneCurrent();
}

TEST(RenderingContext_getFrameBuffer, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  rendererContext->makeCurrent();

  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);
}

TEST(RenderingContext_drawArrays, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  rendererContext->makeCurrent();

  auto frameBuffer = rendererContext->getFrameBuffer(gl::FrameBuffer::Buffer::Color);

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

  gl::VertexArray vertexArray{1};

  vertexArray.bind();

  shaderProgram.use();

  rendererContext->drawArrays(gl::RenderingContext::DrawMode::Points, 0, 1);
}

TEST(RenderingContext_pointSize, normal) {
  gl::Program program{{4, 3}};

  auto factory = program.getFactory();
  auto window = factory->createWindow("Test", {1024, 768});
  auto surface = factory->createScreenSurface(*window);
  auto rendererContext = surface->getRenderingContext();

  rendererContext->makeCurrent();
  rendererContext->pointSize(40.0f);
}