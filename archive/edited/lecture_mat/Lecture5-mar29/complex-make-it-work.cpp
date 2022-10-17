#include<iostream>
using namespace std;
class Complex{
    private:
        int x;
        int y;
    
    public:
        Complex(int x, int y){
            this->x = x;
            this->y = y;
        }

        int getX(){return x;}

        int getY(){return y;}

        Complex & operator << (int val){
            this->x += val;
            return *this;
        }
};

int main () {

Complex c1(10,20), c2(30,40);


//  Complex c3(0,0);


//  c3 = c1+c2;

//  c3 = c1*c2;

c1 << 10 << 10 << 10;
cout << c1.getX();
//  cout << c3.real() << endl;
//  cout << c3.imag() << endl;


}
