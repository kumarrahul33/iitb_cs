#include <iostream> 
using namespace std; 
class A {  // abstract class, since one member function is abstract, i.e. not impemented
		// and specified to be abstract '=0'
int x; 
	public: 
		A(int v) {x=v; } 
		virtual void f()=0; // abstract member function
		virtual void g() {cout << "A::g\n";}
		void h() {cout << "A::h\n";}
}; 
class B : public A {
int y;
	public:
		B(int v):A(v+1) {y=v;}
		void f() {cout << "B's f\n";}
		void g() {f();}
		void h() {cout << "B::h\n";}
};
class C  : public A{
int x;
	public:
		C(int v):A(v+1) {x=v;}
		void f() {cout << "C's f\n";}
		//void g() {f();}
		void h() {cout << "C::h\n";}
};

class D : public C {
int x;
	public:
		D(int v):C(v+1) {x=v;}
		void f() {cout << "D's f\n";}
		void g() {cout << "D::g\n";}
		void h() {cout << "D::h\n";}
};

int main () { 
	A *ap;
	B *bp = new B(100);
	C *cp = new C(200);
	D *dp = new D(300);
	bp->g(); cp->g(); dp->g(); 
	bp->h(); cp->h(); dp->h(); 
	ap=bp; ap->g(); ap->h();
	ap=cp; ap->g(); ap->h();
	ap=dp; ap->g(); ap->h();

	cp = dp; cp->f(); cp->g(); cp->h();
	ap = cp; ap->f(); ap->g(); cp->h();
} 
//Q1: when is an object pointer assignment correct?  p1 = p2
//Q2: which method body will be called when a call is made on a pointer p->f()

// A1: when class of p2 is inherited from class of p1, or they are the same
// A2: (a) if f is non virtual in class used to declare p (DCp) then  DCp::f() is called
//            what if it's not available there? - continue up the chain and pick the first
//		if there is ambiguity--error
//    (b) if f is virtual in DCp then start from classs used to create object that
// was assigned to p (CCp) and go up the chain to find first.
// in case of ambiguity (multi definitions)--> error
//same rules are applied to nested calls


