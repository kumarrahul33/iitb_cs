
#include <iostream>
using namespace std;

class Counter {
	int p; // only Counter can access it, since this is private
 protected: // accessible by all its subclasses, main cannot access it
 	int c;
 public: // accessible by everyone! main can also access it
	Counter() {c=0;}
	void incr() { c++; }
	void show() { cout<<c<<endl;}
};

class ExtendedCounter1 : public Counter { 
 public:
	ExtendedCounter1() { };
	void reset() { c=0;}  // have access to c defined in parent class!
};


class ExtendedCounter2 : public ExtendedCounter1 {  
	// we got all features here, but...
	// lost indendent variant with only dec and no reset
 public:
	ExtendedCounter2() { };
	void dec() {c--;}
};

int main () {

ExtendedCounter2 c3;

	c3.incr(); c3.incr(); c3.incr(); c3.incr(); 
	c3.dec();  
	c3.show();
	c3.reset();
	c3.incr();
	c3.show();
}


