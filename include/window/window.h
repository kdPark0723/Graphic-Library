//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_WINDOW_H
#define GRAPHICLIBRARY_WINDOW_H

#include <string>

#include "size.h"

namespace gl {

class Window {
 public:
  Window() = default;
  virtual ~Window() = default;

  virtual const ::std::string getTitle() const = 0;
  virtual const Size getSize() const = 0;
  virtual bool shouldClose() const = 0;
};

}

#endif //GRAPHICLIBRARY_WINDOW_H
