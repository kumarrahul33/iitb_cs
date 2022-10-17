#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
	int *S;
	int cap, card;

	public:
		Collection(int sz) {
			assert(sz>0);
			S = new int [sz];
			card=0;
			cap = sz;
		}

		void push_back(int elem) {
			assert(card < cap);
			S[card] = elem;
			card += 1;
		}

		int pop_back() {
			assert(card > 0);
			card -= 1;
			return S[card];

		}
};
int main () {
	Collection a = Collection(100);
	
	for (int i = 0; i < 10000; i++)
	{
		a.push_back(i);
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << a.pop_back() << " ";
	}
	
	cout << endl;

	
}


