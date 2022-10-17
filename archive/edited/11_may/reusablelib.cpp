#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include <cassert>
#include "similarity.h"


myclass::myclass(string n1, string n2){
            f1.open(n1); 
            f2.open(n2);

            string s;

            while (f1 >> s)
            {
                file1.push_back(s);
            }

            while (f2 >> s)
            {
                file2.push_back(s);
            }  

            if (file1.size() == 0)
            {
                throw exceptions(1);
            }

            if (file2.size() == 0)
            {
                throw(exceptions(2));
            }
            
            
            //cout << file1.size() << " " << file2.size() << endl;

            //std::cout << "ldjlkdjflfjslfj" << std::endl;
        }

double myclass::checkSimilar(string s1, string s2){
    string s3;
    string s4;
    double finalans = 0;

    if (s1.size() > s2.size())
    {
        s3 = s1;
        s4 = s2;
    }

    else
    {
        s3 = s2; 
        s4 = s1;
    }
    
    for (size_t i = 0; i < s4.size(); i++)
    {
        if(s3[i] == s4[i]){
            finalans += 1.0/s3.size();
        }
    }
    assert(finalans<=1 && finalans>=0);
    return finalans;
    
    
}

exceptions::exceptions(int e){
    errorCode = e;
}

void exceptions::msg(){
    switch (errorCode)
    {
    case 1:
        cout << "first file is empty" << endl << "the program will now terminate" << endl;
        break;
    case 2:
        cout << "second file is empty" << endl << "the program will now terminate" << endl;
    default:
        break;
    }
}

int myfunction () {
    return 0;
}
