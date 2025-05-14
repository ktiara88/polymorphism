
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fruit {
  // could do Friend class Apple, but you should avoid doing because we don't want the superclass to know 
  // anything about its derived classes
public:
  virtual ~Fruit() = default;
  virtual int eat() { return energy; };
  Fruit (int energy) { this->energy = energy; };
private:
  int energy{0};
};

class Apple : public Fruit {
public:
  Apple() : Fruit(10) { };
  int eat() override {
    cout << "Ate apple" << endl;
    Fruit::eat();
  }
};

class Banana : public Fruit {
public:
  Banana() : Fruit (20) { };
  int eat() override {
    cout << "Ate banana" << endl;
    Fruit::eat();
  }
};

class FruitFactory {
public:
  static Fruit *create(const string &name) {
    if (name == "apple")
      return new Apple();
    if (name == "banana")
      return new Banana();
    return nullptr;
  }
};

void FruitTest() {
  vector<Fruit *> eaten;
  string name;
  int totalEnergy{0};
  while (cin >> name && !name.empty()) {
    Fruit *f = FruitFactory::create(name);
    if (f != nullptr) {
      totalEnergy += f->eat();
    } else {
      cout << "Got " << name << ", not a valid fruit" << endl;
    }
  }
  cout << "Total Energy: " << totalEnergy << endl;
  for (const auto &f : eaten)
    delete f;
}

int main() {
  FruitTest();
  return 0;
}
