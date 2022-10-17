#include <iostream>
#include <cassert>
using namespace std;

// adding class invariant

class Collection {

int *S;
int cap, card;

  public:
	Collection(int s) {
		S = new int [s];
		card=0;
		cap = s;

		assert(cap>0);
		assert(card==0);
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


 Collection *c;

	c = new Collection (20);

}

