//
// Created by siyualbak on 19. 5. 29.
//

#include "window/internal/glfwWindow.h"

#include "exception/cantInitException.h"

gl::internal::GLfwWindow::GLfwWindow(const ::std::string &title, const gl::Size &size): title{title} {
  window = glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr);
  if (window == nullptr)
    throw CantInitException{"gl::internal::GLFWWindowSurface::GLFWWindowSurface: Can't create window"};
}

gl::internal::GLfwWindow::~GLfwWindow() {
  glfwDestroyWindow(window);

}

const ::std::string gl::internal::GLfwWindow::getTitle() const {
  return title;
}

const gl::Size gl::internal::GLfwWindow::getSize() const {
  Size size;
  glfwGetWindowSize(window, &size.width, &size.height);

  return size;
}

bool gl::internal::GLfwWindow::shouldClose() const {
  return glfwWindowShouldClose(window);
}

void *gl::internal::GLfwWindow::getWindowSurface() {
  return const_cast<void *>(const_cast<const GLfwWindow *>(this)->getWindowSurface());
}

const void *gl::internal::GLfwWindow::getWindowSurface() const {
  return window;
}
