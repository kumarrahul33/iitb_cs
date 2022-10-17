//A CS 152 Lecture Program by rkj
#include <iostream>
#include <string>
#include <sstream>  // for string streams 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

using namespace std;

int X, Y;

int main(int argc, char *argv[]) {

   X = 400; Y=400;
   string s[4][4];
   ostringstream oss;
   int n;

   Fl_Window* w = new Fl_Window(X+100, Y+100);
   for (int i=0; i<4;i++)
   	for (int j=0; j<4;j++) {
		n = i*4+j;
		oss.str("");
		oss << n;
		s[i][j] = oss.str();
		cout << s[i][j] << endl;
   		new Fl_Button(50+i*100, 50+j*100, 100, 100,s[i][j].c_str());
	}

   w->end();
   w->show(argc, argv);
   return Fl::run();
}
