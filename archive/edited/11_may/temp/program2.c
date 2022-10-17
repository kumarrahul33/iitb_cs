#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string fileName;
    cin >> fileName;
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    

    ifstream inFile;
    inFile.open(fileName);
    

    char x;

    while(inFile >> x)
    {
        x = tolower(x);
        int asciiX = x;
        if(asciiX >= 97 && asciiX <=122){
            arr[asciiX - 97] += 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            char c = 97 + i;
            cout << c << " - " << arr[i] << endl; 
        }
        
    }
    

    
    return 0;
}