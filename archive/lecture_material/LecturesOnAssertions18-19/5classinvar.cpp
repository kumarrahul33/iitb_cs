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
		assert(cap>0);
		assert(card<=cap);
	}

	int pop_back() {

		card--;
		return S[card+1];
		assert(cap>0);
		assert(card<=cap);
	}

};

int main () {


 Collection *c, *d;

	c = new Collection (20);
	d = new Collection (20);
	for (int i=0; i<20; i++)
		d->push_back(i);
	for (int i=0; i<20; i++)
		c->push_back(i);

	for (int i=0; i<20; i++)
		cout << c->pop_back() << " ";
	cout << endl;
	for (int i=0; i<20; i++)
		cout << d->pop_back() << " ";
	cout << endl;

	cout << c << " " << d << endl;

	cout << sizeof (*c) << endl;
}

