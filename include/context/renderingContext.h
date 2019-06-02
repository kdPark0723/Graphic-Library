//
// Created by siyualbak on 19. 5. 23.
//

#ifndef GRAPHICLIBRARY_GLCONTEXT_H
#define GRAPHICLIBRARY_GLCONTEXT_H

#include <memory>

#include "../openGL.h"
#include "../buffer/frameBuffer.h"

namespace gl {

class RenderingContext {
 public:
  enum class DrawMode {
    Points = GL_POINTS,
  };

  explicit RenderingContext() = default;
  virtual ~RenderingContext() = default;

  virtual void doneCurrent() = 0;
  virtual void makeCurrent() = 0;

  virtual void swapBuffers() = 0;

  ::std::unique_ptr<FrameBuffer> getFrameBuffer(const FrameBuffer::Buffer &buffer);

  inline void drawArrays(const DrawMode &mode, int first, size_t count);
  inline void pointSize(float size);
};

}

#include "renderingContext-inc.h"

#endif //GRAPHICLIBRARY_GLCONTEXT_H
