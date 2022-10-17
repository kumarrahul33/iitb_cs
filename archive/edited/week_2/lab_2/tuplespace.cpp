#include<iostream>
#include<vector>
using namespace std;

class TupleSpace
{
    private:
        vector<pair<int,string>> arr;
        
    public:
        TupleSpace(vector<pair<int,string>> _arr)
        {
            arr = _arr;
        };
        
        void insert(int key, string value)
        {
            arr.push_back(make_pair(key,value));
        }

        void find(string value)
        {
            for(auto x : arr)
            {
                if (x.second == value)
                {
                    cout << x.first << " -- " << x.second << endl;
                    return; 
                }
            }
            
            cout << "Not Found!!" << endl;
                   
        }

        void Delete(int key)
        {
            vector<pair<int,string>>::iterator it;
            for (it = arr.begin(); it != arr.end(); it++)
            {
                if (it->first == key)
                {
                    arr.erase(it);
                    return;
                }
                
            }
            
            
        }
        
};

int main(int argc, char const *argv[])
{
    vector<pair<int,string>> arr ={
        {1,"rahul"},
        {2,"python"},
        {3,"EdSheeran"},
        {4,"guitar"}
    };

    TupleSpace t(arr);
    t.find("EdSheeran");
    t.Delete(3);
    t.find("EdSheeran");
    t.find("Ubuntu");
    t.insert(5,"Ubuntu");
    t.find("Ubuntu");

    return 0;
}
