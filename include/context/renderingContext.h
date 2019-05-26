//
// Created by siyualbak on 19. 5. 23.
//

#ifndef GRAPHICLIBRARY_GLCONTEXT_H
#define GRAPHICLIBRARY_GLCONTEXT_H

#include <memory>

#include "../buffer/frameBuffer.h"

namespace gl {

class RenderingContext {
 public:
  explicit RenderingContext() = default;
  virtual ~RenderingContext() = default;

  virtual void doneCurrent() = 0;
  virtual void makeCurrent() = 0;

  virtual void swapBuffers() = 0;

  ::std::unique_ptr<FrameBuffer> getFrameBuffer(const FrameBuffer::Buffer &buffer);
//  Version getVersion()
};

}

#endif //GRAPHICLIBRARY_GLCONTEXT_H
