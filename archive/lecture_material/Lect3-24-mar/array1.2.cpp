// level 1 abstraction -- all gloabls, accessed by all procedures
// level 1+  adding error code to handle in main/calling environment
//what if the error code value is a valid value?
//we can't use the return value to indicate error.. 
//1) return a structure of values (Set of values), or set a global error code variable, or return through pointer parameter`
//2) keep aside one value as error code and that is not a valid element value! 
//3) use a separate global variable errorcode, more power to express the actual type of error 
//4) use exceptions



#include <iostream>
#include <cassert>
using namespace std;



 int *a1; // array created dynamically, size is known at runtime, global variable
 int sz_of_a1;
 int errcode=0; // no error so far!


//int a2[10]; // array created statically, compiler knows the size!

void create(int sz) {
	a1 = new int [sz];
	sz_of_a1  = sz;

}

void insert(int i, int e) { // inserted elements will be non-negative only
        errorcode = 0; // any earlier errorcode has been handled gracefully-- assumption
 //     assert((i>=0)&&(i<sz_of_a1)); // safe programming, but exit is abrupt
     
	if (!((i>=0)&&(i<sz_of_a1)))  errorcode = 1; // 1 indicates index out of bound error

	a1[i]=e;
}

int fetch (int i) {
	return a1[i];
}
	

int main (int argc, char *argv[]) {


 int *arr;
 int n;
 int err;

 cout<< "size?";
 cin >> n;

 create(n);

 sz_of_a1=10000;

 err = insert(n+2,125);

 cout << "this point was reached with err code " << err << "\n";

 if (err==-1) cout << "index out of bound error was reported from the call\n";


 for (int i=0; i<n; i++) insert(i,i*i); 
 //a1[5]=5; -- accidental overwrites of the global variable by other code
 // it violates the abstraction -- create, insert, fetch

 for (int i=0; i<n+100000; i++) cout << fetch(i) << " "; 

 cout << endl;

}

