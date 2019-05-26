//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_WINDOWSURFACE_H
#define GRAPHICLIBRARY_WINDOWSURFACE_H

#include "surface.h"

namespace gl {

class WindowSurface : public Surface {
 public:
  WindowSurface() = default;
  virtual ~WindowSurface() = default;
};

}

#endif //GRAPHICLIBRARY_WINDOWSURFACE_H
