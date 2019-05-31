//
// Created by siyualbak on 19. 5. 31.
//

#include "program.h"

gl::Program::Program(const gl::Initializer::Version &version)
  : version{version}, loaderInitializer{std::make_shared<GLLoaderInitializerImp>(version)}, factory{std::make_shared<FactoryImp>(version, *loaderInitializer)} {
}
gl::Program::~Program() {
}

gl::Factory *gl::Program::getFactory() {
  return factory.get();
}
