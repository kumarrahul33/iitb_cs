/*
                Product A        Product B    Product C
feature 1       	y              y           n
feature 2         	y              n           y
feature 3           	y              y           n
*/

#include <iostream>
using namespace std;
// make intermediate assemblies which are not products
// you can assemble your products out of these intermediate
// assemblies

class F1 {public: void f1() {cout << "feature 1\n";}};
class F2 {public: void f2() {cout << "feature 2\n";}};
class F3 {public: void f3() {cout << "feature 3\n";}};
class F1F3: public F1, public F3 {};
class A : public F1, public F2, public F3{}; 
class B : public F1F3{}; 
class C : public F2{};

int main () { 
	A a; B b; C c; 
	a.f1();
	a.f2();
	a.f3();
	b.f1();
	//b.f2(); // not available on b
	b.f3();
	// c.f1(); // not available on c
	c.f2();
	//c.f3(); // not available on c
}
