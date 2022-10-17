//CS 152 Demo Code by Prof. R. K. Joshi, CSE, IIT Bombay
// It's about graceful handling of errors, logical, expression/mathematical/
// access boundaries, business-logic/algorithmic assertion conditions
// what is it to be graceful? --> program should know that there
// is an error/exception condition and it should have a path to
// handle it gracefully--> recover and continue or gracefully terminate
// graceful termination makes sure that data is consistent, operational
// consistency is regained and then the program terminates


#include <iostream>
using namespace std;

class account {
int bal;
public :
	account (int a) {bal = a;}
	void deposit (int a) {bal+=a;}
	void withdraw (int a) {
		if (bal < 100) throw (bal);
		bal -= a;
	};
	int balance () {return bal;}
};

int main () {

int m;
cout << "initial amount?";
cin >> m;

account * a = new account(m);

 while (1) {
	try {
		cout << "withdraw amount?";
		cin >> m;
		a->withdraw(m);
	}
	catch (int b) {
		cout << "Exception occured, balance is just Rs.  " << b << "\n";
	};
  };

}


