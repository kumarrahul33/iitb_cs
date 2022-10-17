#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    

    for (int i = 0; i < 6; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(((rand() % 6) +1) == i+1) count++;
        }
            cout << i+1 << "-" << ((double)count)/((double)n) <<endl;
    }

}