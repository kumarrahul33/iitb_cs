#include <iostream>
using namespace std;

class Counter {
 protected: 
 	int c;
 public: 
	Counter() {c=0;}
	void incr() { c++; }
	void dec() {c--;}
	void reset() { c=0;}  
	void show() { cout<<c<<endl;}
};


int main () {

	Counter *cp; // instance is dynamically created (at runtime)
	Counter c;  // instance is statically created

		cp = new Counter(); // at this time when running the
				// program, the instance is created

		cp->incr(); cp->incr(); cp->incr(); cp->incr();
		cp->dec(); 
		cp->show();

		c.incr();
		c.show();

}


