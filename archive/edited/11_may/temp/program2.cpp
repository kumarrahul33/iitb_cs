#include <iostream>
#include <fstream>
using namespace std;

class charFreq{
    private:
        string fileName;
        ifstream inFile;
        int arr[26];

    public:
        charFreq(string _fileName){
            fileName = _fileName;
            inFile.open(fileName);

            for (int i = 0; i < 26; i++)
            {
                arr[i] = 0;
            }
        }

        void printFreq(){
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
        }

};


int main(){
    string fileName;
    cin >> fileName;
    
    charFreq c = {fileName};

    c.printFreq();    
    return 0;
}