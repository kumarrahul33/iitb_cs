#include<iostream>
using namespace std;

class ATM{
    private:
        int Balance;
        int pin;
        bool verified;
    public:
        ATM(int _Balance, int _pin)
        {
            Balance = _Balance;
            pin = _pin;
            verified = false;
        }

        bool EnterPin(int _pin)
        {
            if(pin == _pin)
            {
                verified = true;
                cout << "You have been verified carry on with your banking" << endl;
                return verified;
            }

            else
            {
                cout << "incorrect pin" << endl;
                return verified;
            }
        }

        int CheckBalance()
        {
            if(!verified) 
            {
                cout << "Please enter the pin first" << endl;
                return -1;
            }
            cout << "Your Balance is: " << Balance << endl; 
            return Balance;
        }

        void Withdraw(int amount)
        {
            if(!verified) 
            {
                cout << "Please enter the pin first" << endl;
                return;
            }

            if(Balance >= amount)
            {
                Balance -= amount;
                cout << "Withdraw Successful!! Available balance: " << Balance << endl; 
                //return Balance;
            }

            else
            {
                cout << "Insufficient Balance" << endl;
                //return Balance;
            }
        }

};

int main(int argc, const char** argv) {
    ATM A1(1000, 208011);
    A1.CheckBalance();
    A1.EnterPin(208011);
    A1.CheckBalance();
    A1.Withdraw(500);
    A1.CheckBalance();
    return 0;
}