// level 3 abstraction -- instead of  forcing the user to create all variables
// associated with a data structure (if it was array: size, pointer to int), everytime
// you have one instance of that data structure, we bundle them into a single
// declaration, and then use that bundled declaration (class) 
//procedures and the data that they share between them are put together in a class



#include <iostream>
#include <cassert>
using namespace std;

class Array {
 private:
 	int *p;
 	int n;
 public:
	Array (int sz) { // constructor
		p = new int [sz];
		n=sz;

	}

	void insert(int i, int e) { // inserted elements will be non-negative only

		p[i]=e;
	}

	int fetch (int i) {
		return p[i];
	}

	int size() { return n;}
};	

int main (int argc, char *argv[]) {

 int n;

 cout<< "size?";
 cin >> n;
 
 Array a1(n), a2(n);

 for (int i=0; i<a1.size(); i++) a1.insert(i,i*i);  // note the call to size on a1--> we don't want
 // to remember anything about an object outside the object-- no redundant tracking of variables 
 //inside the object-- one thing only at once place -- avoid multiple copy redundancy 


 for (int i=0; i<a1.size(); i++) cout << a1.fetch(i) << " "; 
 cout << endl;
 for (int i=0; i<a2.size(); i++) a2.insert(i,i*i); 
 for (int i=0; i<a2.size(); i++) cout << a2.fetch(i) << " "; 
 cout << endl;

}

