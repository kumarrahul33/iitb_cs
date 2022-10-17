#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int find(string str, string sub) {  
    assert(str.length() >= sub.length());
    assert(sub.length()!=0 && str.length()!=0);

    int i;
    for (i = 0; i < str.length() - sub.length() + 1; i++)
    {
        if(str.substr(i,sub.length()) == sub) return i;
    }

    assert(i>=0 && i < str.length() - sub.length() + 1); 
    return -1;
}

int main () {


    cout << find("rahulkumar","hello") << endl;

}
