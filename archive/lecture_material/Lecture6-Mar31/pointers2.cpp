#include <iostream>
using namespace std;

int main () {

 int *p; 

 p = new int;
 cout << p << endl;
 cout << &p << endl;

 
 // earlier allocated memory has now become inaccessible .. but it's there in the program
 // hogging your space!! 

 p = new int(10);
 cout << p << endl;
 cout << &p << endl;

 delete p;

 p = new int[1000];
 cout << p << endl;
 cout << &p << endl;


// p = new int[9999999999];   not enough memory!!  All RAM memory



}
