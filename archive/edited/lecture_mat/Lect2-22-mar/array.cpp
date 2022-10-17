// level 1 abstraction -- all gloabls, accessed by procedures


#include <iostream>
#include <cassert>
using namespace std;


 int *a1; // array created dynamically, size is known at runtime, global variable
 int sz_of_a1;


//int a2[10]; // array created statically, compiler knows the size!

void create(int sz) {
	a1 = new int [sz];
	sz_of_a1  = sz;
}

void insert(int i, int e) {
 //     assert((i>=0)&&(i<sz_of_a1)); // safe programming, but exit is abrupt
     
	if (!((i>=0)&&(i<sz_of_a1)))  return; // do nothing, but continue

	a1[i]=e;
}

int fetch (int i) {
	return a1[i];
}
	

int main (int argc, char *argv[]) {


 int *arr;
 int n;

 cout<< "size?";
 cin >> n;

 create(n);

 sz_of_a1=10000;

 insert(n+2,125);

 cout << "this point was reached\n";


 for (int i=0; i<n; i++) insert(i,i*i); 
 //a1[5]=5; -- accidental overwrites of the global variable by other code
 // it violates the abstraction -- create, insert, fetch

 for (int i=0; i<n+100000; i++) cout << fetch(i) << " "; 

 cout << endl;

}

