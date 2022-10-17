#include <iostream> 
using namespace std; 
class A { 
int x; 
	public: 
		A(int v) {x=v; } 
		virtual void show () { 
			cout << "A::show: " << x << "\n";} 
		~A() { cout << "object " << x << " destroyed\n";} 
}; 

A *foo(int p) {   // function/procedure which is not a member function
	A a1(p);  // gets destroyed automatically upon completion of the procedure
	A *ap1 = new A(p+2);  // will not be destroyed unless explicitly deleted
	return ap1;
} 

int main () { 
	A *ap = new A(10); 
	A *tmp;
	A a(20); 
		ap->show(); 
		a.show(); 
		delete(ap); 
		tmp = foo(2000); 
		tmp->show();
		delete(tmp);
} 

// a class, a main, main creates an object at runtime, a statically created object 
//  and uses them // class defines a virtual member function, and keeps a local state, 
// that local state is initialized in the constructor 
// the destructor gets called when object is destroyed 
// explicitly created objects (using new) are to be explicitely deleted 
// if you don't it creates garbage -- things that are never going to be used 
// statically created objects are automatically deleted 


