#include<iostream>
int* getList(int count, int* a){

    for (int i = 0; i < count; i++)
    {
        a[i] = i*5;
    }

    return a;
    
}

int main(int argc, const char** argv) {

    int * list = new int[10];
    getList(10, list);

    for (int i = 0; i < 10; i++)
    {
        std::cout << list[i] << std::endl;
    }
    
    return 0;
}