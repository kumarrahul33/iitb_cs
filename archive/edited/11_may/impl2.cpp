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
        
            for (int i = 0; i < min(file1.size(), file2.size()); i++)
            {
                sim_percent += checkSimilar(file1[i], file2[i]);
            }

            sim_percent = (sim_percent/max(file1.size(),file2.size()))*100;
            assert(sim_percent<=100 && sim_percent>=0);
            return (int)sim_percent;
        }

};


int checksimilarity (string n1, string n2) {
    similarity obj = similarity(n1, n2);
    return obj.measureSimilarity();
}



