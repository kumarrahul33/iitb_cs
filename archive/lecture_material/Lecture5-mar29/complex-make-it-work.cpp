


int main () {

 Complex c1(10,20), c2(30,40);


 Complex c3(0,0);


 c3 = c1+c2;

 c3 = c1*c2;


 cout << c3.real() << endl;
 cout << c3.imag() << endl;


}
