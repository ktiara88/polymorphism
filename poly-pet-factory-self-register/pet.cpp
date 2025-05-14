//
// Created by Yusuf Pisan on 2/14/24
//

#include "pet.h"
#include <iostream>

// In this code, we hvae an abstract pet factory, and concrete CatFactory,
// DogFactory, etc. Each factory is now registered as being able to make that object
// So, creating a CatFactory object registers it.
// If you want to have a HorseFactory object, there is no need to change this code, we get to just add it to the compiling

using namespace std;

/**
 * Storage place for the concrete pet factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<string, PetFactory *> &PetFactory::getMap() {
  static map<string, PetFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void PetFactory::registerType(const string &type, PetFactory *factory) {
  getMap().emplace(type, factory);
}
// find the corresponding pet factory and get factory to create the object
Pet *PetFactory::create(const string &type) {
  if (!getMap().count(type)) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->makePet();
}
