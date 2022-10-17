#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <chrono>

#include "queue.h"
#include "circularQueue.cpp"

using namespace std;
using namespace std::chrono;

void do_insert_delete(DynamicQueue<int>&, int, int&, int&);
int main() {
    DynamicQueue<int> myQueue;

    cout<<myQueue.isEmpty()<<endl;
    cout << myQueue.size() << endl;
    for(int i=0 ; i<9; i++) myQueue.QInsert(i);
   
    cout<<myQueue.size() << endl << myQueue.isFull() <<endl;

    myQueue.QInsert(69);
    cout<<myQueue.size() << endl << myQueue.isFull() <<endl;
  
}