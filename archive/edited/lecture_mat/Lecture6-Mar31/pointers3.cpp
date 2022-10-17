#include <iostream>
using namespace std;

int main () {

 int *p; 

 p = new int[1000];

 for (int i=0; i<1000; i++)
	p[i] = i*i*i;

  cout << *((&(p[1]))+1) << endl; // pointer arithmetic 
  cout << &p[1] << endl << &p[2] << endl;

//  cout << p << endl;
//  cout << p[1] << endl;
//  cout << p[2] << endl;
//  cout << &p << endl;

//  cout << "-----\n";
//  cout << &(p[1]) << endl;
//  cout << &((*(&p))[1]) << endl;
//  cout << "-----\n";

//  cout << &(p[2]) << endl;

}
