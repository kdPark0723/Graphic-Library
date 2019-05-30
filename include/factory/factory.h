//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_FACTORY_H
#define GRAPHICLIBRARY_FACTORY_H

#include <memory>
#include <string>

#include "../window/surface.h"
#include "../window/screenSurface.h"
#include "../window/offScreenSurface.h"
#include "../window/window.h"
#include "../window/size.h"
#include "../context/renderingContext.h"

namespace gl {

class Factory {
 public:
  Factory() = default;
  virtual ~Factory() = default;

  virtual ::std::shared_ptr<Surface> createSurface(const ::std::string &title, const Size &size) const = 0;
  virtual ::std::shared_ptr<Window> createWindow(const ::std::string &title, const Size &size) const = 0;
  virtual ::std::shared_ptr<ScreenSurface> createScreenSurface(Window &window) const = 0;
  virtual ::std::shared_ptr<OffScreenSurface> createOffScreenSurface() const = 0;
};

}

#endif //GRAPHICLIBRARY_FACTORY_H
