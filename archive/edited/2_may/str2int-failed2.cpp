#include<iostream>
#include <string>
#include <cassert>
using namespace std;

int toInteger(char a){
   switch (a)
   {
	case '1':
    	return 1;
    	break;
   
	case '2':
    	return 2;
    	break;
   
	case '3':
    	return 3;
    	break;
   
	case '4':
    	return 4;
    	break;

	case '5':
    	return 5;
    	break;

	case '6':
    	return 6;
    	break;

	case '7':
    	return 7;
    	break;
   
   case '8':
    	return 8;
    	break;

   case '9':
      	return 9;
      	break;
   
   case '0':
		return 0;
		break;

   
   default:
		return 0;
		break;
   }
}

bool checkString(string s){
	
	for(int var : s)
	{
		if (var < 48 || var > 57)
		{
			return false;
		}
		
	}

	return true;
	
}

bool checkMax(string s){
	if (s.length() > 10)	return false;
	
	else if (s.length() < 9)	return true;
	
	string maxInt = "2147483647";

	for (size_t i = 0; i < s.length(); i++)
	{
		if(s[i] > maxInt[i]) return false;

		else if (s[i] == maxInt[i])	continue;	

		else if (s[i] < maxInt[i])	return true;
	}
	
	return true;
	
}


int str2int (string s) {
	int v=0;
	int tPlace = 1;
 // define your other needed variables

    assert(checkString(s));
	assert(checkMax(s));


    // the logic, which does not check for any condition, can be buggy
	for (int i = s.length()-1; i >= 0; i--)
	{
			v += toInteger(s[i]) * tPlace;
			tPlace *= 10;
	}
	
	assert(v >= 0);

	return v;
};


int main() {
	int a = str2int("687673543434");
	cout << a << endl;
// develop main which catches errors through assertions
// report bugs


}

