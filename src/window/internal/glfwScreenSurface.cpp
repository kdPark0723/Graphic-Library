//
// Created by siyualbak on 19. 5. 26.
//

#include "window/internal/glfwScreenSurface.h"

#include "exception/cantInitException.h"
#include "context/internal/glfwRenderingContext.h"

gl::internal::GLfwScreenSurface::GLfwScreenSurface(Window &window, GLLoaderInitializer& glLoaderInitializer)
  : window{&window}, loaderInitializer{&glLoaderInitializer}, renderingContext{std::make_unique<gl::internal::GLfwRenderingContext>(*this, *loaderInitializer)} {
}
gl::internal::GLfwScreenSurface::~GLfwScreenSurface() = default;

void *gl::internal::GLfwScreenSurface::getPlatformSurface() {
  return const_cast<void *>(const_cast<const GLfwScreenSurface *>(this)->getPlatformSurface());
}

const void *gl::internal::GLfwScreenSurface::getPlatformSurface() const {
  return window->getWindowSurface();
}

gl::RenderingContext *gl::internal::GLfwScreenSurface::getRenderingContext() {
  return renderingContext.get();
}
