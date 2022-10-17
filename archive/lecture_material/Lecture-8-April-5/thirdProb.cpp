/*
                Product A        Product B    Product C  Product D
feature 1       	y              y           y		y
feature 2         	y              n              		y
feature 3           	y              y           n  
feature 4	 	y			   y	 	n
*/


#include <iostream>
using namespace std;
// make intermediate assemblies which are not products
// you can assemble your products out of these intermediate
// assemblies

class F1 { public: void f1() {cout << "f1()\n";} // not a product, but
					// a reusable superclass--most common

int main () { 
	A a; B b; C c; 
}
