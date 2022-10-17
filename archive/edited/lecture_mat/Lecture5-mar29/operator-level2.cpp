#include <iostream>
using namespace std;

class Pair {
	int x, y;
  public:
	Pair (int i, int j) {x=i;y=j;}
	int  & operator [] (int i) {
		if (i==0) return x;
		else return y;
	}
	// exercise: define <<  >> operators and make << work in cascaded mode!
	// p1 << 10 << 20 << 30
	// p1 >> x; 
};

int main () {

Pair a(10,20);
int b[20];

	// 10 = 10; invalid lvalue! can't use 10 which is a constant
	// to assign another value to it, no matter if it's 10 itself!

	cout << a[0] << endl ; // we are able to use the operatr on a

	cout << b[0] << endl ; // btw b is not initialized
	cout << a[0] << endl ; // we are able to use the operatr on a
				// a[0] is rvalue
	int x = a[0]; // a[0] as rvalue is fine!
	a[0] = 200;  // does not work since a[0] is not an lvalue!
	a[1] = 300;  // does not work since a[0] is not an lvalue!
	cout << a[0] << " " << a[1] << endl ; // we are able to use the operatr on a
};


