#include<bits/stdc++.h>
using namespace std;
class Probablity
{
private:
    int n;
    int k;
public:
    Probablity(int _n, int _k){
        n = _n;
        k = _k;
    }

    void PrintProb(){
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if(((rand() % 6) +1) == k) count++;
        }

        cout << k << " " << ((double)count)/((double)n) << endl;
    
}
    
};




int main(){

    int n;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        Probablity p{n, i+1};
        p.PrintProb();
    }    

}