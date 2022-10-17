#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "similarity.h"
#include <cassert>

//#include "reusable.cpp"

class similarity : public myclass {
    
    public:
        similarity(string n1, string n2) : myclass(n1, n2){}

        int measureSimilarity(){

            double sim_percent = 0;
        
            for (int i = 0; i < file1.size(); i++)
            {
                double temp = 0;
                for (int j = 0; j < file2.size(); j++)
                {
                    temp += (checkSimilar(file1[i], file2[j]) > 0.4) ? checkSimilar(file1[i], file2[j]): 0 ;
                }

                temp = min(1.0,temp);
                sim_percent += temp;
                
            }

            sim_percent = (sim_percent/max(file1.size(),file2.size()))*100;
            assert(sim_percent<=100 && sim_percent>=0);
            return (int)sim_percent;
        }

};


// definition of the function: one variant


int checksimilarity (string n1, string n2) {
    similarity obj = similarity(n1, n2);
    return obj.measureSimilarity();
}

// int main(int argc, char const *argv[])
// {
//     checksimilarity("testfile.txt","rubbish.txt");
//     return 0;
// }


