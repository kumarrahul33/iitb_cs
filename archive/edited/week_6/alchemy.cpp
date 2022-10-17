#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

/* This game lets you create the world around you using the four elements of archemedes - Air, Fire, Water and Earth. You can combine two of the known elements and create a new element. This goes on till all elements have been created. The elements are a structure, having five attributes, namely -
Name, Baap1 and Baap2 (the creator elements) and status (whether it has been created or not). The user has several options -
To Combine and Create
To Look up the database of created elements
To look up all the information (which has been explored by the user) of a certain element
To Look up the list of possible elements
To exit the program if the user gets infy bored
*/

struct element
{
	string name;
	string baap1, baap2;
	string status;

};

/* Functions -
	Create
	this has three input parameters- string1 and string2 and the array of all elements,'thing'.
	status of both strings is checked. if they have been created, function moves further. elese, function terminates.
	if the baap1 and baap2 match with the given strings, the element is created i.e. its status is set to created. The element is then copied into
	another file.

	Look -
	this function has one parameter - array 'thing'.
	all elements with status 'created' are printed.

	Lookinfo -
	this has two parameters - search string and 'thing'.
	the function looks for all elements of array where the search string is found either in baaps or name. if the status is 'created' then the 		element is shown to user.

	Lookall -
	this function has one parameter - the array 'thing'.
	all names are printed. only names. no other info.

*/
int create(string a, string b, element *arr)
{
	int blh=-1;
	for(int x=0;x<364;x++)
	{
		if(arr[x].name == a)
		{
			if(arr[x].status != "created")
			{
				cout<<"\nERROR!!\n. Element used not created.\n";
				return (blh);
			}
		}
		if(arr[x].name == b)
		{
			if(arr[x].status != "created")
			{
				cout<<"\nERROR!!\n. Element used not created.\n";
				return (blh);
			}
		}
	}
	for(int i=0;i<364;i++)
	{
		if(arr[i].baap1 == a && arr[i].baap2 == b && arr[i].status!= "created")
		{
			cout<<"\nCONGRATULATIONS!!!! \nNEW ELEMENT CREATED! - ";
			cout<<arr[i].name;
			arr[i].status = "created";
            
			return (i);
		}
		if(arr[i].baap2 == a && arr[i].baap1 == b && arr[i].status!= "created")
		{
			cout<<"\nCONGRATULATIONS!!!! \nNEW ELEMENT CREATED! - ";
			cout<<arr[i].name;
			arr[i].status = "created";
		
			return (i);
		}
	}

	cout<<"\nSORRY!\n No new Created.\n";
	return (blh);
}

void look(element arr[])
{
	int x=1;
	for(int i=0;i<364;i++)
	{
		if(arr[i].status == "created")
		{
			cout<<"\n"<<x<<"."<<" "<<arr[i].name;//" = "<<arr[i].baap1<<" + "<<arr[i].baap2<<".\n";
            x++;
		}
	}
}

void lookinfo(string a, element arr[])
{
	int x=1;
	for(int i=0;i<364;i++)
	if((arr[i].name == a || arr[i].baap1 == a || arr[i].baap2== a) && arr[i].status == "created")
	{
		cout<<"\n"<<x<<"."<<" "<<arr[i].name<<" = "<<arr[i].baap1<<" + "<<arr[i].baap2<<".\n";
		x++;
	}
}

void lookall(element arr[])
{
	for(int i=0;i<364;i++)
		cout<<arr[i].name<<"\n";
}

class UserMgmt{
	private:
		string newUser,savedUser, ans;
		int newa;
		ifstream userList;
		ofstream newo;


		void validateUser(){
			int baba=0;
			while(baba==0)
			{
				cout<<"\nPlease enter your name : ";
				cin>>newUser;
				userList.open("user.c");
				while(!userList.eof() && baba==0)
				{
					userList>>savedUser;
					if(savedUser==newUser)
					{
						cout<<"\nPleasure to meet you again, "<<newUser<<endl;
						baba=1;
					}
				}
				if(baba==0)
				cout<<"\nSOrry! User Name Does not exist\n";
				userList.close();
			}
		}

		void addNewUser(){
			do
			{
				newa=0;
				cout<<"Please enter your name : ";
				cin>>newUser;
				userList.open("user.c");
				userList>>savedUser;
				while(!userList.eof())
					{
						if(savedUser==newUser)
						{
							cout<<"\nSorry, user already exists.\n";
							newa=1;
							break;
						}
						userList>>savedUser;
					}
				userList.close();
			}while(newa==1);

			newo.open("user.c",ios::app );
			newo<<"userListser"<<" "<<newUser<<endl<<newUser<<" "<<endl<<" ";
			newo.close();
			cout<<"outofIfLoop";
		}

	public:
		UserMgmt(){
			newa = 0;
		}

		string getUser(){
			cout<<"\n_________________________________________________________________________________________________________________________________-\nAre you a new user?Enter 'yes' if you are. If you are not a new user then enter no. \n";
			cin>>ans;
			int newa=0;
			if(ans=="yes")
			{
				addNewUser();	
			}

	// Confirming User Existence.

			else
			{
				validateUser();
			}

			return newUser;
		}
};

element* getThings(string newUser, element* thing){
	ifstream f,e,oo;
	ofstream o;
	string g;
	f.open("data.c" );
	o.open("user.c",ios::app  ); // This File Saves User Profiles.
	oo.open("user.c");

	for(int i=0;i<364;i++){
		//Reading The Name, Baap1 and Baap2 of the Thing.
		f>>thing[i].name;
		f>>thing[i].baap1;
		f>>thing[i].baap2;
		//As Fire, Earth, Air and Water are elemental, their Status is being set to "Created".
		if(thing[i].name == "fire" || thing[i].name == "water" || thing[i].name == "air" || thing[i].name == "earth")
		{
			thing[i].status = "created";
			thing[i].baap1 = "elemental";
			thing[i].baap2 = "elemental";
		}

		// If in case the user has already unlocked certain elements, their status is being set to Created.

		e.open("user.c");
		e>>g;
			while(!e.eof())
			{
					while(g!=newUser && !e.eof())
					{
						e>>g;
					}

					e>>g;


					while(g!=newUser && !e.eof() )
					{
						if(thing[i].name == g)
						{
								thing[i].status ="created";
						}
					e>>g;
					}
			}
		e.close();
		}
	f.close();
	return thing;
}

void startGame(element* thing, string newUser){
	int l=-1,tabo=0;
	string a,b,c;
	int i=0;
	string g;
	ifstream e;
	ofstream o;
	o.open("user.c",ios::app); 

	while (i==0)
	{
		if(l!=-1)
		{

	// Writing the Created Element's Information in the User Profile.        	
			
				o<<newUser<<endl<<thing[l].name<<" = "<<thing[l].baap1<<" + "<<thing[l].baap2<<endl<<newUser<<endl;

		}
		l=-1;
		cout<<"\n\n------------------------------------------------------------------------------------------------------------\n\nEnter your choice\n1. Combine and Create\n2.Look up all created elements\n3.Look up info of one element\n4.Look up all possible elements\n5. Exit\n :";
		int ab;
		cin>>ab;
		
		switch (ab)
		{
			case 1 :
			{
				cout<<"\nEnter the Elemtns you want to combine : ";

				cin>>a>>b;
				l=create(a,b,thing);
				break;
			}
			case 2 :
			{	
						cout<<"\n\n-----------------------------------You have the following Elements--------------------------------------\n\n--Fire, Earth, Air and Water are elemental. \n";
						e.open("user.c");
						e>>g;
						while(!e.eof())
						{
							e>>g;
							if(g==newUser)
							{
									e>>g;
									while(g!=newUser)
									{
										cout<<"--";
										for(int ii =0;ii<5;ii++)
										{
											cout<<g<<" ";
												e>>g;
										}
										cout<<endl;
									}
							}
						}
						e.close();
				break;
			}
			case 3 :
			{
				cout<<"\nEnter the element whose info you want : ";
				cin>>c;
				lookinfo(c,thing);
				break;
			}
			case 4 :
			{
				lookall(thing);
				break;
			}
			case 5 :
			{
						o<<endl<<" "<<newUser<<" "<<newUser<<" ";
						return ;
				}
		}
	}
}

int main()
{
	cout<<"\n\n*******************************************************************************************************************\n This game lets you create the world around you using the four elements of archemedes - Air, Fire, Water and Earth.\n You can combine two of the known elements and create a new element. This goes on till all elements have been created.\n\n\n**Please do not use Capital Letters. \n\n\n**Enter all data in small case.Like password, this program is case sensitive";

	
	string newUser;

//Asking the User whether they have played the Game Before. Much like Load/Save Profile.

	
	UserMgmt UserMgmt1;
	newUser = UserMgmt1.getUser();

	element* thing = new element[364] ; // This is the array of elements that will read the data from the file - data.c
/* To read the elements into the array 'thing', one by one, from the opened file.*/
	thing = getThings(newUser,thing);
/* Provide the user with the Choices in the form of a menu.*/
	
	

	startGame(thing, newUser);
/* Begin Infy loop. that is, Menu*/



return 0;
}
