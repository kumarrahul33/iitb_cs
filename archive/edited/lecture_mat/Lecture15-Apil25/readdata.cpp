#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {

ifstream f;
int d;

	f.open(argv[1]);
	while (!f.eof()) {
		f >> d;
		cout << d; 
	}

	f.close();
}
// 5 is printed twice  
