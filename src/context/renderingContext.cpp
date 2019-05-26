//
// Created by siyualbak on 19. 5. 26.
//

#include "context/renderingContext.h"

#include "buffer/bindFrameBuffer.h"

std::unique_ptr<gl::FrameBuffer> gl::RenderingContext::getFrameBuffer(const FrameBuffer::Buffer &buffer) {
  return std::make_unique<BindFrameBuffer>(*this, buffer);
}
