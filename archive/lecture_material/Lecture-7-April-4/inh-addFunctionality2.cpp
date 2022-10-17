
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

class ExtendedCounter2 : public Counter { 
 public:
	ExtendedCounter2() { };
	void dec() {c--;}
};

int main () {


Counter c1;
ExtendedCounter1 c2;
ExtendedCounter2 c3;

	c1.incr(); c1.incr(); c1.incr(); c1.incr(); 
	//	c1.reset();  // wont compile ! no reset feature in Counter
	c1.show();

	c2.incr(); c2.incr(); c2.incr(); c2.incr(); 
	c2.reset();  
	c2.incr(); c2.incr(); c2.incr(); c2.incr(); 
	c2.show();
	// c2.dec(); // does not work, since dec() is in its sibling, not
			// in its parent
	// c3.reset(); // not accessible for the same reason
	c3.incr(); c3.incr(); c3.incr(); c3.incr(); 
	c3.dec();  
	c3.show();
}


