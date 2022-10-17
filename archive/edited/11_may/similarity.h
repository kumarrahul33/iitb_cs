#include <vector>
#include <fstream>
class exceptions{
    protected:
        int errorCode;
    public:
        exceptions(int e);
        void msg();
};
int checksimilarity(string name1, string name2);
class myclass{
    protected:
        ifstream f1;
        ifstream f2;
        vector<string> file1;
        vector<string> file2;
    public:
        myclass(string n1, string n2);
        double checkSimilar(string s1, string s2);
};
// declaration of the function


