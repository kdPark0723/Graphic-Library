//
// Created by siyualbak on 19. 5. 31.
//

#include "program.h"

gl::Program::Program(const gl::Initializer::Version &version)
  : version{version},
    loaderInitializer{std::make_unique<GLLoaderInitializerImp>(version)},
    factory{std::make_shared<FactoryImp>(version, *loaderInitializer)} {
}
gl::Program::~Program() {
}

std::shared_ptr<gl::Factory> gl::Program::getFactory() {
  return factory;
}
