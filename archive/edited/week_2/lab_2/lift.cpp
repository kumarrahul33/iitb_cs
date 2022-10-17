#include<iostream>
using namespace std;

class Lift
{
    private:
        int currFloor;
    public:
        Lift(){
            currFloor = 0;
        }
        void bringLift(int floor){
            if(floor > 1 || floor < 0){
                cout << "enter valid floor number" << endl;
                return;
            }

            currFloor = floor;
        }

        void setDestination(int initialFloor, int floor){
            if(floor > 1 || floor < 0 || initialFloor > 1 || initialFloor < 0){
                cout << "enter valid floor number" << endl;
                return;
            }

            if(initialFloor == currFloor){

                if(floor == currFloor)
                {
                    cout << "This is the current floor itself" << endl;
                    return;
                }

                else{
                    currFloor = floor;
                }
            }

            else{
                cout << "lift is on some other floor" << endl;
            }
        }

        int currentFloor(){
            return currFloor;
        }


};

int main(int argc, char const *argv[])
{
    Lift L;
    cout << L.currentFloor() << endl;

    L.bringLift(1);
    cout << L.currentFloor() << endl;

    L.setDestination(1,0);
    cout << L.currentFloor() << endl;


    return 0;
}
