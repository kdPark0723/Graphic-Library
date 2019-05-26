//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_FACTORY_H
#define GRAPHICLIBRARY_FACTORY_H

#include <memory>
#include <string>

#include "../window/surface.h"
#include "../window/windowSurface.h"
#include "window/offScreenSurface.h"

#include "../window/size.h"

#include "../context/renderingContext.h"

namespace gl {

class Factory {
 public:
  Factory() = default;
  virtual ~Factory() = default;

  virtual ::std::unique_ptr<Surface> createSurface(const ::std::string &title, const Size &size) const = 0;
  virtual ::std::unique_ptr<WindowSurface> createWindowSurface(const ::std::string &title, const Size &size) const = 0;
  virtual ::std::unique_ptr<OffScreenSurface> createOffScreenSurface(const ::std::string &title,
                                                                     const Size &size) const = 0;

  virtual ::std::unique_ptr<RenderingContext> createRenderingContext(Surface &surface) const = 0;
};

}

#endif //GRAPHICLIBRARY_FACTORY_H
