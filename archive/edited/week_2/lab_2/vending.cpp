#include<iostream>
#include<vector>
using namespace std;

class DrinksVendingMachine
{
    private:
        vector<pair<string,int>> drinkList;

    public:
        DrinksVendingMachine(){
            //initiallising with some drinks
            drinkList = {
                {"thumbsUp",10},
                {"Pepsi", 10},
                {"CocaCola", 10},
                {"MountainDew", 10},
                {"RedBull", 10}
            };
        };

        void giveDrink(int drinkNumber, bool coin)
        {
            if(drinkNumber >= drinkList.size() || drinkNumber < 0)
            {
                cout << "Please enter a valid drink number" << endl;
            }

            else if (coin)
            {
                if(drinkList[drinkNumber].second > 0)
                {
                   drinkList[drinkNumber].second --;
                   cout << "Your drink has been given" << endl; 
                }

                else
                {
                    cout << "Your drink is not available" << endl;
                }
            }

            else cout << "Plese put the coin in" << endl;
            
        }

        void listDrinks(){
            cout << "DrinkName | AvailableQty" << endl;
            cout << "drinknumber  drinkName  AvailableQty" << endl;
            for (int i = 0; i < drinkList.size(); i++)
            {
                cout << i << "            " << drinkList[i].first << "  " << drinkList[i].second << endl; 
            }
            
        }

        void addStock(int drinkNumber, unsigned int stock){
            if(drinkNumber >= drinkList.size() || drinkNumber < 0)
            {
                cout << "Please enter a valid drink number" << endl;
            }

            else
            {
                drinkList[drinkNumber].second += stock;
                cout << "Stock added successfully" << endl;
                cout << drinkList[drinkNumber].first << " - " << drinkList[drinkNumber].second << endl;
            }
        }
};

int main(int argc, const char** argv) {
    DrinksVendingMachine d;
    d.listDrinks();
    d.giveDrink(4,true);
    d.giveDrink(0,true);
    d.listDrinks();
    d.addStock(3,12);
    d.listDrinks();

    return 0;
}

