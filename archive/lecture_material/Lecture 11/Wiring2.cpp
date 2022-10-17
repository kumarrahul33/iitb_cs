#include <iostream> 
using namespace std; 
class A { 
int x; 
	public: 
		A(int v) {x=v; } 
		void show () { cout << "A::show: " << x << "\n";}  
}; 
class B : public A {
int y;
	public:
		B(int v):A(v+1) {y=v;}
		virtual void show () { cout << "B::show: " << y << "\n";}  
};

class C  : public A{
int x;
	public:
		C(int v):A(v+1) {x=v;}
		virtual void show () { cout << "C::show: " << x << "\n";}  

};

class D : public C {
int x;
	public:
		D(int v):C(v+1) {x=v;}
		virtual void show () { cout << "D::show: " << x << "\n";}  
};

A *foo(int p) {   
	A *tmp;
	switch (p) {

		case 0: tmp = new A(10); break;
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

	ap->show(); // this statement is behaving differently everytime choice is different
		//the binding of the call and the exact method body happens at runtime!
} 


