#include <iostream>
using namespace std;

// A program which is not correct

class Collection {

int *S;
int cap, card;

  public:
	Collection(int s) {
		S = new int [s];
		card=0;
	}

	void push_back(int i) {
		S[card]=i;
		card++;
	}

	int pop_back() {

		card--;
		return S[card+1];
	}

};

int main () {




}

