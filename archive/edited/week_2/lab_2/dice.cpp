#include<iostream>
using namespace std;

class Dice{
    public:
        int Toss(){
            return 1 + (rand() % 6);
        }

};

int main(int argc, char const *argv[])
{
    Dice d;
    for (int i = 0; i < 10; i++)
    {
        cout << d.Toss() << endl;
    }
    
    return 0;
}
