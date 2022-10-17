#include<iostream>
using namespace std;

class mainProduct {
	public:
		mainProduct(){};

		void feature1(){
			cout << "i have got feature 1" << endl;
			}

};

class ProductB : public mainProduct {
	public:
		ProductB(){};

		void feature3(){
			cout << "i have got feature 3" << endl;
			}
};

class ProductA : public ProductB {
	public:
		ProductA(){};

		void feature2(){
			cout << "i have got feature 2" << endl;
			}
};

int main(){
	mainProduct product_C;
	ProductA product_A;
	ProductB product_B;

	cout << "product_A" << endl;
	product_A.feature1();
	product_A.feature2();
	product_A.feature3();

	cout << endl;
	
	cout << "product_B" << endl;
	product_B.feature1();
	product_B.feature3();
	
	cout << endl;
	
	cout << "product_C" << endl;
	product_C.feature1();

	return 0;
};
