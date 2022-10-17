#include<iostream>
using namespace std;

int main(){
	int *p;

	p = new int;  //here we allocated a some memory
	*p = 10;
	p = new int; //here we allocated a new memory 
	//this is a memory leak as the previous memory is used
	//but no variable is pointin to it and it is wasted
	//we should use 'delete p;' to avoid this situation

	cout << p << endl << *p << endl << &p << endl;
}
