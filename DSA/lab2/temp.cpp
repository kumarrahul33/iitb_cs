#include<iostream>
using namespace std;

struct journey
{
    string key;
    int* station;
    int value;

    bool operator == (journey j) {
        if(
            j.key == this->key &&
            j.station == this->station &&
            j.value == this->value
        ) return true;

        return false;
    }
};

int main() {
    int arr[] = {1,2,3,4,5};
    journey a = {"alhabibi",arr,69};   
    journey b = {"alhabiddbi",arr,69};   

    cout << (a == b);
}