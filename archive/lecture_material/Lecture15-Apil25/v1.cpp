#include <cstdio>
using namespace std;


main ( ) { 
int marks=20; 
if (marks > 80) print(“A”); 
if (marks > 60 && marks<80) printf(“B”);
if (marks > 40 && marks<60) printf(“C”); 
if(marks<40) printf("F")
printf("\n");
}

// 6 inner conditions+2 outer (composite) conditions and 8 operators 
// conditions were repeated! 

================================================


int main () {
int marks=20;
if (marks > 80) cout<<"A"<<endl;
else if (marks > 60) cout<<"B"<<endl;
else if (marks > 40) cout<<"C"<<endl;
else cout<<"F"<<endl;
}

// 3 conditions, 3 operators, single if outer block broken into
// inner blocks (inner statements)

// LOC (lines of code is different from no. of statememts 
// in the code: statements are logical control flow units

===============================================

main () {

    int marks=20;

    if(marks>80) cout<<"A\n";

    else if(marks>60) cout<<"B\n";

    else if(marks>40) cout<<"C\n";

    else cout<<"F\n";

}
