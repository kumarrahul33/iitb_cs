#include<iostream>
using namespace std;

class A{
	int x;

	public:
		A(int v) {x=v;}
		virtual void show(){ cout << "A::show " << x << endl;}
		~A(){cout << "oblect destroyed" << endl;}

};

A *foo(int p){
	A a1(p);
	A *ap1 = new A(p+2);
	return ap1;
}

int main(){
	A *ap = new A(10);
	ap->show();
	A a(25);
	a.show();
//expicitly created objects (using new) are to be explicitely deleted
//if you do not delete it then it creates garbage
	//delete(ap);
/*
	int *ptr = new int(100);
	for(int i=0; i<50; i++){
		(ptr[i]) = i;
	}

	for(int i = 0; i<50; i++){
		cout << (ptr[i]) << endl;
	}
*/

}
