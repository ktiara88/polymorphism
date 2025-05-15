#ifndef TURTLE_H
#define TURTLE_H

#include "pet.h"

class Turtle : public Pet {
public:
  void say() const override;
};

class TurtleFactory : public PetFactory {
public:
  TurtleFactory();
  Pet *makePet() const override;
};

#endif // TURTLE_H