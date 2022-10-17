#include<iostream>
using namespace std;

int binarySearch(int* list, int n, int element, int i=0){
    if (list[i+n/2] == element)
        return i+n/2;

    else if (n == 0)
        return -1;
    

    else if (list[i + n/2] > element)    
        return binarySearch(list, n/2, element, i);
    
   else if (list[i + n/2] < element)
        return binarySearch(list, n- (n/2) -1, element, n/2 + 1);

   return -2;
    
}

int main(){
    int list[] = {56,445,3342,68679,3344556,223311223};
    int element = 68679;

    cout << "hello world" << endl;
    cout << binarySearch(list,6,element) << endl;
}