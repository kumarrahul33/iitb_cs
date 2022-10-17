#include <bits/stdc++.h>
#include "BST.cpp"

using namespace std;

vector<string> parse;
void split (string str, char seperator)  
{  
    parse.clear();
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= str.length())  
    {  
        if (str[i] == seperator || i == str.length())  
        {  
            endIndex = i;
            parse.push_back(str.substr(startIndex,endIndex-startIndex));
            startIndex = endIndex + 1;  
        }  
        i++;  
        }     
}  

int main(int argc, char* argv[]){
	ifstream inputFile;
	ofstream outFile;

	inputFile.open("test.txt");
	outFile.open("output.txt");
	//outFile << "hello" <<endl;

    BST *b = new BST();
    string s;
	//cout << "int the file";
    while(getline(inputFile,s)){
		//cout << "in the file" << endl;
        split(s,' ');
        if(parse[0]=="ADD"){
				if(b->insert(stoi(parse[1]),stoi(parse[2]))){
					outFile<<"SUCCESSFULLY INSERTED!"<<endl;
				}else{
					outFile<<"INSERTION FAILED!"<<endl;
				}
			}else if(parse[0]=="DEL"){
				if(b->remove(stoi(parse[1]),stoi(parse[2]))){
					outFile<<"SUCCESSFULLY DELETED!"<<endl;
				}else{
					outFile<<"JOURNEY NOT FOUND!"<<endl;
				}
			}else if(parse[0]=="FIND"){
				if(b->find(stoi(parse[1]),stoi(parse[2]))){
					outFile<<"JOURNEY FOUND!"<<endl;
				}else{
					outFile<<"JOURNEY NOT FOUND!"<<endl;
				}
			}else if(parse[0]=="TRAVERSE"){
				if(parse[1]!="PRE" && parse[1]!="POST" && parse[1]!="IN"){
					outFile<<"INVALID REQUEST!"<<endl;
				}
				int x = (parse[1]=="PRE")?0 : ((parse[1]=="POST")?1:2);
				b->traverse(x);
			}else if(parse[0]=="GETMIN"){
				outFile<<b->getMinimum()<<endl;
			}else if(parse[0]=="PRINT"){
				b->printBST("");
			}else{
				outFile<<"INVALID REQUEST"<<endl;
			}
    }
	

}
