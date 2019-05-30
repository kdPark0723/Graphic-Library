//
// Created by siyualbak on 19. 5. 26.
//

#include "buffer/bindFrameBuffer.h"

gl::BindFrameBuffer::BindFrameBuffer(RenderingContext &context, const gl::FrameBuffer::Buffer &buffer)
  : context{&context}, buffer{buffer} {
}

gl::BindFrameBuffer::~BindFrameBuffer() = default;

