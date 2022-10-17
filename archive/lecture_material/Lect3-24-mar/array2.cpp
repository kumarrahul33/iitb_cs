// level 2 abstraction -- instead of using global access through function/procedure bodies,
// we still keep using globals, but now we add parameters to procedures
//--> parameterized procedures-- procedure not to access directly mutable global variables
// but they will be passed on through parametrs



#include <iostream>
#include <cassert>
using namespace std;


int *create(int sz) {
	return new int [sz];

}

void insert(int i, int e, int *p) { // inserted elements will be non-negative only

	p[i]=e;
}

int fetch (int i, int *p) {
	return p[i];
}
	

int main (int argc, char *argv[]) {


 int *A;
 int na;
 int *B;
 int nb;

 cout<< "size?";
 cin >> na;
 A  = create(na);
 for (int i=0; i<na; i++) insert(i,i*i,A); 
 for (int i=0; i<na; i++) cout << fetch(i,A) << " "; 
 cout << endl;

 cout<< "size?";
 cin >> nb;
 B = create(nb);
 for (int i=0; i<nb; i++) insert(i,i*i,B); 
 for (int i=0; i<nb; i++) cout << fetch(i,B) << " "; 
 cout << endl;
}

