
#include <iostream>
using namespace std;

class A {

 public:
	A() { }
	void f() { cout << "A::f\n";}
	void g() { cout << "A::g\n";}
};

class B : public A { // class B extends class A
A x;
 public:
	B() { };
	void h() { cout << "B::h\n";}
	void k() {
		x.f();
		x.g();
		// x.h(); // not accessible though instace is inside B
		// because x has type A, not B
	}
};


int main () {


A a1;
	a1.f();
	a1.g();

	//	a1.h(); // an error.. h not available on instances of A!

B b1;

	b1.f();	 // f,g work by virtue of inheritance, from parent class!
	b1.g();
	b1.h(); // added functionality to B

}


