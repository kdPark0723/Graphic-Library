//
// Created by siyualbak on 19. 5. 26.
//

#include "window/internal/glfwWindowSurface.h"

#include "exception/cantInitException.h"

gl::internal::GLFWWindowSurface::GLFWWindowSurface(const ::std::string &title, const Size &size)
  : title{title} {
  window = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
  if (window == nullptr)
    throw CantInitException{"gl::internal::GLFWWindowSurface::GLFWWindowSurface: Can't create window"};
}
gl::internal::GLFWWindowSurface::~GLFWWindowSurface() {
  glfwDestroyWindow(window);
}

const ::std::string gl::internal::GLFWWindowSurface::getTitle() const {
  return title;
}

const gl::Size gl::internal::GLFWWindowSurface::getSize() const {
  Size size;
  glfwGetWindowSize(window, &size.width, &size.height);

  return size;
}

bool gl::internal::GLFWWindowSurface::shouldClose() const {
  return glfwWindowShouldClose(window);
}

void *gl::internal::GLFWWindowSurface::getPlatformSurface() {
  return const_cast<void *>(const_cast<const GLFWWindowSurface *>(this)->getPlatformSurface());
}

const void *gl::internal::GLFWWindowSurface::getPlatformSurface() const {
  return window;
}
