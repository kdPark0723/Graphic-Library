//
// Created by siyualbak on 19. 5. 23.
//

#ifndef GRAPHICLIBRARY_PROGRAM_H
#define GRAPHICLIBRARY_PROGRAM_H

#include <memory>

#include "initializer/initializer.h"
#include "initializer/glLoaderInitializer.h"
#include "initializer/glLoaderInitializerImp.h"
#include "factory/factory.h"
#include "factory/factoryImp.h"

namespace gl {

class Program {
 public:
  explicit Program(const Initializer::Version &version);
  ~Program();

  Factory* getFactory();
 private:
  const Initializer::Version version;
  ::std::shared_ptr<GLLoaderInitializer> loaderInitializer;
  ::std::shared_ptr<Factory> factory;
};

}

#endif //GRAPHICLIBRARY_PROGRAM_H
