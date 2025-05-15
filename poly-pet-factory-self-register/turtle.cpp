#include "turtle.h"
#include <iostream>

using namespace std;

void Turtle::say() const { cout << "snap snap" << endl; }

TurtleFactory::TurtleFactory() { registerType("Turtle", this); }

Pet *TurtleFactory::makePet() const { return new Turtle(); }

// creating the object registers the type at run time
TurtleFactory anonymous_TurtleFactory;
