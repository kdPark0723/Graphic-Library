//
// Created by siyualbak on 19. 5. 26.
//

#ifndef GRAPHICLIBRARY_SURFACE_H
#define GRAPHICLIBRARY_SURFACE_H

#include "../context/renderingContext.h"

namespace gl {

class Surface {
 public:
  Surface() = default;
  virtual ~Surface() = default;

  virtual void *getPlatformSurface() = 0;
  virtual const void *getPlatformSurface() const = 0;

  virtual RenderingContext* getRenderingContext() = 0;
};

}

#endif //GRAPHICLIBRARY_SURFACE_H
