/*
We learn to design inheritance hierarchy given feature matrix.
                Product A        Product B    Product C
feature 1       	y              y           y
feature 2         	y              n           n
feature 3           	y              y           n
 supermost parent class: A? B? C?
   A?     no.. because only A has all features, they must
	all be in;  and then you will be passing 
       them all down to other products, which don't have them
  B? feature 3 will be passed down to C... that's a problem
 C? yes, feature 1 is common to all

  class C is the supermost class
then what next?
	alternative 0: A is supermost class since it has all features!
			design issue: no! then all features will get passed
				on to all products!
	alternative 1: A & B as children of C
			C: f1
              A:f2,f3               B:f3
	design issue: f3 is repeated twice! can we avoid it?
        --------------------------------------------
		alt 2
			A: f2,f3
			B: -f2   disable f2! 
        --------------------------------------------
	alternative 3: best possible one here.. no negative feature
		and it exactly fits the feature table!
		C: f1
		B: f3
		A: f2
		This has no problem! 
	-------------------------------------------
*/
#include <iostream>
using namespace std;
class C {public: void f1() {cout << "feature 1\n";}};
class B: public C {public: void f3() {cout << "feature 3\n";}};
class A: public B {public: void f2() {cout << "feature 2\n";}};
int main () { A a; B b; C c; a.f1();a.f2();a.f3(); /*b.f2();*/}
