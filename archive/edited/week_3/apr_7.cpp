#include<iostream>
using namespace std;

class Counter{
	protected:
		int c;
	public:
		Counter() { c = 0; }
		virtual void incr(){c++;}
		void dec(){c--;}
		void reset(){ c=0; }
		void show(){ cout << c << endl;}
};
class NewCounter : public Counter{
	public:
		void incr(){c+=2;}
		void foo(){c*=2;}
};

int main(){
	Counter *cp;
	NewCounter *ncp;
		//ncp = new Counter();  //this will give an error  as the 
		//customer of the new product will no accept the older version
		/*
		ncp->incr();
		ncp->incr();
		ncp->incr();
		ncp->show();
		*/

		//no error here 
		//as the customer of the old version will happily accept the new version
		cp = new NewCounter();
		//cp->foo();
		cp->incr(); cp->incr(); cp->incr(); cp->show();
return 0;
}


