#include <iostream> 
using namespace std; 
class A {  // abstract class, since one member function is abstract, i.e. not impemented
		// and specified to be abstract '=0'
int x; 
	public: 
		A(int v) {x=v; } 
		virtual void f()=0; // abstract member function
		virtual void g() {cout << "A::g\n";}
		void show () { cout << "A::show: " << x << "\n";}  
}; 
class B : public A {
int y;
	public:
		B(int v):A(v+1) {y=v;}
		void f() {cout << "B's f\n";}
		void g() {f();}
		virtual void show () { cout << "B::show: " << y << "\n";}  
};
class C  : public A{
int x;
	public:
		C(int v):A(v+1) {x=v;}
		void f() {cout << "C's f\n";}
		void g() {f();}
		virtual void show () { cout << "C::show: " << x << "\n";}  
};

class D : public C {
int x;
	public:
		D(int v):C(v+1) {x=v;}
		void f() {cout << "D's f\n";}
		void g() {cout << "D::g\n";}
		virtual void show () { cout << "D::show: " << x << "\n";}  
};

A *foo(int p) {   
	A *tmp=NULL;
	switch (p) {

		case 1: tmp = new B(20); break;
		case 2: tmp = new C(30); break;
		case 3: tmp = new D(40); break;
	}
	return tmp;
} 

int main () { 
	A *ap;
	int choice;
	cout << "choice?(0,1,2,3:A,B,C,D)\n";
	cin >> choice;

	ap = foo(choice);
	if (ap!=NULL)
	  ap->show(); // this statement is behaving differently everytime choice is different
		//the binding of the call and the exact method body happens at runtime!
	ap->g();
} 


