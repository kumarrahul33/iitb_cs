
#include <iostream>
using namespace std;
//Diamonds-- are problems with multiple declarations/multiple
//copies coming inside the bottom tip of the diamond


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

class ExtendedCounter2 : public Counter { 
 public:
	ExtendedCounter2() { };
	void dec() {c--;}
};

class ExtendedCounter3: public ExtendedCounter1, ExtendedCounter2 {  
	// combiner of two siblings 
 public:
	ExtendedCounter3() { };
};

int main () {


Counter c1;
ExtendedCounter3 c3;

	c3.incr(); c3.incr(); c3.incr(); c3.incr(); 
	c3.reset();
	c3.dec();  
	c3.show();
}


