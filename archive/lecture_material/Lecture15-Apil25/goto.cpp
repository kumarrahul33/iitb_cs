#include <iostream>
using namespace std;
int main ( ) {
int marks=81;
if (marks > 80) goto label1;
if (marks > 60) goto label2;
if (marks > 40) goto label3;
cout << "F"; goto Last;
label1: cout << "A"; goto Last;
label2: cout << "B"; goto Last;
label3: cout << "C";  goto Last;
Last: cout << "\n";
}
