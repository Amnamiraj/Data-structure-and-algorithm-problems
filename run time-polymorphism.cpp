#include <iostream>
using namespace std;
// Parent class: Animal
class Animal {
public:
	// Virtual function means its overridden in derived classes
	virtual void makesound() {
		cout << "This is base class animal sound!!" << endl;
	}
};
// child class: Dog
class Dog :public Animal {
public:
	void makesound() {
		cout << "This is the dog's sound!!" << endl;
	}
};
// child class: Cat
class Cat :public Animal {
public:
	void makesound() {
		cout << "This is the cat's sound!!" << endl;
	}
};
// child class: Cow
class Cow :public Animal {
public:
	void makesound() {
		cout << "This is the cow's sound!!" << endl;
	}
};
int main(){
	// Base class pointers 
	Animal* bp;
	Animal* bp1;
	Animal* bp2;
	// Derived class objects
	Dog d;
	Cat c1;
	Cow c;
	// Base class pointers to derived class objects
	bp1 = &d;
	bp2 = &c1;
	bp = &c;
	// Calling of functions through base class pointers
	bp1->makesound();
	bp2->makesound();
	bp->makesound();
	return 0;
}
