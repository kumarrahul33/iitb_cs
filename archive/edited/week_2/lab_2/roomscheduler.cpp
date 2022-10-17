#include<iostream>
#include<cstring>
using namespace std;

//this program accepts the booking for 6 days only and there are 6 rooms available for each day
//while booking a room we need to give only the day and the program will allot the room automatically
//for cancelling a booked room we need to provide the day and the room number of the booking
//day and room takes value from 0 to 5

class RoomScheduler{
    private:
        int roomSchedule[6][6];

    public:
        RoomScheduler(){
            memset(roomSchedule, 0, sizeof(roomSchedule));
        }

        void printSchedule()
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    cout << roomSchedule[i][j] << " ";
                }
                cout << endl;
            }
            
        }

        void book(int day){
            if(day > 5 || day < 0){
                cout << "Please enter a valid day between 0 and 5" << endl;
                return;
            } 

            for (int i = 0; i < 6; i++)
            {
                if(roomSchedule[day][i] == 0)
                {
                    roomSchedule[day][i] = 1;
                    cout << "booking successful!!! Your room number is: " << i << endl;
                    return;
                }
            }

            cout << "No room avaliable for the given day" << endl;
            
        }

        void cancel(int day, int room){
            if(day > 5 || day < 0 || room < 0 || room > 5)
            {
                cout << "please enter valid data.. room and date should be between 0 and 5" << endl;
            }

            else if(roomSchedule[day][room] != 1)
            {
                cout << "no booking found for the given data" << endl;
                return;
            }

            else{
                roomSchedule[day][room] = 0;
                cout << "booking cancelled successfully" << endl;
            }
        }



};

int main(int argc, char const *argv[])
{
    RoomScheduler r;
    
    r.book(3);
    r.printSchedule();
    r.book(2);
    r.book(2);
    r.book(2);
    r.book(2);
    r.book(2);
    r.book(2);

    r.cancel(3,1);
    r.cancel(3,0);
    r.printSchedule();

    
    return 0;
}
