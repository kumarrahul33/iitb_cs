#include "sort.h"
#include <iostream>

// Code up the functions defined in sort.cpp
void copy_arr(Journey* arr, Journey* arrCpy,int start, int finish) {
    for (int i = start; i <= finish ; i++)
    {
        arr[i] = arrCpy[i-start];
    }
}

SorterTree::SorterTree(int choice , int l) {
    array = new Journey[10];
    
    for (int i = 0; i < 10; i++)
    {
        Journey* temp = new Journey(rand()%50,rand()%50);
        array[i] = *temp;
    }

    tree = nullptr;
    l = 10;
    comparisons = 0;    
}

bool SorterTree::Quicksort(int start, int finish)
{
    if (finish == start)
    {
        return 1;
    }
    
    // Call appropriate pivot function based on choice
    // Split into 2 parts based on pivot choice
    //Recursively keep sorting
    Journey* pivot = choose_one(array,start , finish);
    Journey sorted_array[finish-start + 1];


    int left_count = 0;
    int right_count = finish-start;


    for (int i = start; i <= finish; i++)
    {
        if(array[i] < *pivot){
           sorted_array[left_count] = array[i];
           left_count++;
        } 

        else{
            sorted_array[right_count] = array[i];  
            right_count--;
        }  
    }



    copy_arr(array,sorted_array,start,finish);

    Quicksort(start,left_count);
    Quicksort(left_count+1,finish);

    return 1;


}

bool SorterTree::QuicksortWithBSTInsert(int start, int finish)
{
    // Call appropriate pivot function based on choice
    // Split into 2 parts based on pivot choice
    // Recursively keep sorting
    // Insert chosen pivot into the tree appropriately
}

bool SorterTree::printArray()
{
    for (int i = 0; i < l; i++)
    {
        std::cout<<"Journey code: "<<array[i].getJourneyCode()<<"\tJourney Price:"<<array[i].getPrice()<<std::endl;
    }
}

int main() {
    SorterTree* s = new SorterTree(10,10);

    s->printArray();


}