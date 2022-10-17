#include<iostream>
using namespace std;

class Fan{
	private:

		int FanSpeed;
		bool State;

	public:
		Fan(){
			FanSpeed = 0;
			State = 0;
		}

		int rotateClockwise()
		{
			if(FanSpeed <5)
			{
				FanSpeed++;
				return FanSpeed;
			}

			cout << "Cannot rotate further  " << endl;
			return FanSpeed;
		}

		int rotateAntiClockwise()
		{
			if(FanSpeed > 0)
			{
				FanSpeed--;
				return FanSpeed;
			}

			cout << "Cannot rotate further  " << endl;
			return FanSpeed;
		}

		bool Switch()
		{
			State = !State;
			return State;
		}

		string CurrState()
		{
			return State ? "ON" : "OFF";
		}

		int CurrSpeed()
		{
			if(!State)
			{
				cout << "Fan is off  ";
				return -1;
			}
			
			return FanSpeed;
			
		}

};

int main(){
	Fan f1;
	cout << f1.rotateAntiClockwise() << endl;
	cout << f1.rotateClockwise() <<endl;
	cout << f1.rotateClockwise() <<endl;
	cout << f1.rotateClockwise() <<endl;
	cout << f1.CurrSpeed() << endl;
	cout << f1.Switch() << endl;
	cout << f1.CurrSpeed() << endl;

	cout << f1.CurrState() << endl;

}
