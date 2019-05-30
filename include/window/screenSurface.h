//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_SCREENSURFACE_H
#define GRAPHICLIBRARY_SCREENSURFACE_H

#include "surface.h"

namespace gl {

class ScreenSurface : public Surface {
 public:
  ScreenSurface() = default;
  virtual ~ScreenSurface() = default;
};

}

#endif //GRAPHICLIBRARY_SCREENSURFACE_H
