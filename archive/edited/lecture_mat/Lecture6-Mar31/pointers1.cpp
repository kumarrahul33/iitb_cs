#include <iostream>
using namespace std;

int main () {

 int p; // memory is allocated to p, and there is no value in it at the moment
	// p will hold integers

 int *q;  // q is a pointer... (pointing to a memory location)

      // *q gives us the value at that location

	// &p gives us the memory location (pointer) of the value p

	//memory is allocated to q, but there is no value in it at the moment
	// q will hold memory locations!! 

 q = new int; // assign a value to q! a new memory location which
	// has been just created.. memory of size 1 integer

 cout << "size of *q, int, p:" << sizeof(*q) << " " << sizeof(int) << " " << sizeof(p) << endl;

cout << "sizeof q:" << sizeof(q) << endl;

// q = (int *) malloc(sizeof(int)); // C style 

 p = 10;
 *q = 10010;

 cout << p << endl;
 cout << q << endl;


}
