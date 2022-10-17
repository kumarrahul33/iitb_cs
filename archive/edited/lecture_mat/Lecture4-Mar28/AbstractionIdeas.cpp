#include<iostream>
using namespace std;
//  design objects (descriptions in classes)
// identify its interface first ===> public section of a class
// identify the internal circuitary=> private section of the class
// identify construction activity: how to intialize an object the moment you create it

class Fan {

 private:



  
 public:
	int rotateCW(); // int return value  gives rpm value
	int rotateCCw(); // 
	void switchOn();
	void switchOff()
	
};

class ATM { // the way the customer uses it 

  public:

	
	int checkBalance();
	bool checkValidityofAccount()??? 


};


int main (int argc, char *argv[]) { // user of the objects

Fan f1, f2, f3; // create the objects

	f1.changeSpeed();    // use them!


}
