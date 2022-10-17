#include <iostream>
using namespace std;
class Counter {
 protected: 
 	int c;
 public: // this interface is the contract 
	Counter();
	virtual void incr();		 
	virtual void dec();
	virtual void reset();
	virtual void show();
};

Counter::Counter() {c=0;}
void Counter::incr() { c++; }
void Counter::dec() {c--;}
void Counter::reset() { c=0;}  
void Counter::show() { cout<<c<<endl;}

class NewCounter : public Counter {
	public:
	void incr() {c=c+2;}
	void foo(int x) {c=c+x;} // jump
};

int main () {

	Counter *cp;
	int choice;

		cout << "Which product? (counter(0), newcounter(1)):";
		cin >> choice;

		switch (choice) {
			case 0: cp = new Counter; break;
			case 1: cp = new NewCounter; break;
		}	

		// following code is the same irrespective of choice
		// of class used to create an instance! 

		cp->incr(); cp->incr(); cp->incr(); cp->incr();
		cp->dec(); 
		cp->show();

	//		cp->foo(); // now permitted since contract offered
	// on cp is that of Counter (type used for variable cp)

}


