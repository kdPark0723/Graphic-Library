//
// Created by siyualbak on 19. 5. 26.
//

#include "factory/internal/glfwFactory.h"

#include "initializer/internal/glfwInitializer.h"
#include "window/internal/glfwWindowSurface.h"
#include "context/internal/glfwRenderingContext.h"

gl::internal::GLFWFactory::GLFWFactory(const gl::Initializer::Version &version)
  : initializer{std::make_unique<GLFWInitializer>(version)} {
  initializer->init();
}

gl::internal::GLFWFactory::~GLFWFactory() = default;

std::unique_ptr<gl::Surface> gl::internal::GLFWFactory::createSurface(const ::std::string &title,
                                                                      const gl::Size &size) const {
  return std::unique_ptr<gl::Surface>();
}

std::unique_ptr<gl::WindowSurface> gl::internal::GLFWFactory::createWindowSurface(const ::std::string &title,
                                                                                  const gl::Size &size) const {
  return std::unique_ptr<gl::WindowSurface>{std::make_unique<GLFWWindowSurface>(title, size)};
}

std::unique_ptr<gl::OffScreenSurface> gl::internal::GLFWFactory::createOffScreenSurface(const ::std::string &title,
                                                                                        const gl::Size &size) const {
  return std::unique_ptr<gl::OffScreenSurface>();
}

std::unique_ptr<gl::RenderingContext> gl::internal::GLFWFactory::createRenderingContext(gl::Surface &surface) const {
  return std::unique_ptr<gl::RenderingContext>(std::make_unique<GLFWRenderingContext>(surface));
}
