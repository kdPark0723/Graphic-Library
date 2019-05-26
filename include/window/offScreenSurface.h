//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_OFFSCREENSURFACE_H
#define GRAPHICLIBRARY_OFFSCREENSURFACE_H

#include "surface.h"

namespace gl {

class OffScreenSurface : public Surface {
 public:
  OffScreenSurface() = default;
  virtual ~OffScreenSurface() = default;
};

}

#endif //GRAPHICLIBRARY_OFFSCREENSURFACE_H
