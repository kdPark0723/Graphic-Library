//
// Created by siyualbak on 19. 5. 26.
//

#include "factory/internal/glfwFactory.h"

#include "initializer/internal/glfwInitializer.h"
#include "window/internal/glfwScreenSurface.h"
#include "context/internal/glfwRenderingContext.h"

gl::internal::GLFWFactory::GLFWFactory(const gl::Initializer::Version &version, GLLoaderInitializer &glLoaderInitializer)
  : initializer{std::make_unique<GLFWInitializer>(version)}, glLoaderInitializer{&glLoaderInitializer} {
  initializer->init();
}

gl::internal::GLFWFactory::~GLFWFactory() = default;

std::shared_ptr<gl::Surface> gl::internal::GLFWFactory::createSurface(const ::std::string &title,
                                                                      const gl::Size &size) const {
  return std::shared_ptr<gl::Surface>();
}

std::shared_ptr<gl::Window> gl::internal::GLFWFactory::createWindow(const ::std::string &title,
                                                                    const gl::Size &size) const {
  return std::shared_ptr<gl::Window>{std::make_shared<GLfwWindow>(title, size)};
}

std::shared_ptr<gl::ScreenSurface> gl::internal::GLFWFactory::createScreenSurface(gl::Window &window) const {
  return std::shared_ptr<gl::ScreenSurface>(std::make_shared<GLfwScreenSurface>(window, *glLoaderInitializer));
}

std::shared_ptr<gl::OffScreenSurface> gl::internal::GLFWFactory::createOffScreenSurface() const {
  return std::shared_ptr<gl::OffScreenSurface>();
}


