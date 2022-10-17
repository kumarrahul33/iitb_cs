#include <iostream>
using namespace std;
class Counter {
 protected: 
 	int c;
 public: 
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

class NewCounter1 : public Counter {
	public:
	void incr() {c=c+2;} 
	void dec() {c=c-2;} 
};

class NewCounter2 : public Counter { // counts no. of inc,dec calls and reports in show
	int icount, dcount;
	public:
	NewCounter2(){icount=dcount=0;}
	void incr() {icount++;Counter::incr();} // we want to pass the call up.. to use
		// old body in addition to what we just added!
	void dec() {dcount++;Counter::dec();}
	void show() {cout << icount << " " << dcount <<endl;
			Counter::show(); }
};

int main () {

	Counter *cp;
	int choice;

		cout << "Which product? (counter(0), newcounter1(1)) newcounter2(2):";
		cin >> choice;

		switch (choice) {
			case 0: cp = new Counter; break;
			case 1: cp = new NewCounter1; break;
			case 2: cp = new NewCounter2; break;
		}	


		cp->incr(); cp->incr(); cp->incr(); cp->incr();
		cp->dec(); 
		cp->show();

	//		cp->foo(); // now permitted since contract offered
	// on cp is that of Counter (type used for variable cp)

		//cp->incr(10); // error.. because incr(int) is not in the contract 
		// of type used to declare cp.. Counter incr() which is not
		// the same as incr(int)

}


