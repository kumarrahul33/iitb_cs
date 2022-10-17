#include <FL/Fl.H> // header files
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include<FL/Fl_Int_Input.H>

using namespace std;

void readData(string fileName, string* arr){
    ifstream x;
    x.open(fileName);
    for( int i=0;i<118;i++) // input names of elements from file "elements" into an array
    x>>arr[i];
    x.close();
}

float angleElec(int n){
    switch (n)
    {
    case 1:
        return 7;
        break;

    case 3:
        return 6.28318/(float)2;
        break;

    case 11:
        return 6.28318/(float)8;
        break;

    case 19:
        return 6.28318/(float)8;
        break;
    
    case 37:
        return 6.28318/(float)18;
        break;
    
    case 55:
        return 6.28318/(float)18;
        break;
    
    case 87:
        return 6.28318/(float)32;
        break;
    
    default:
        return 0;
        break;
    }
}

void boxMaker(int a, int b, int c, int d, Fl_Color color){
    Fl_Box *b1;
    b1 = new Fl_Box(a,b,c,d,"");
    b1->box(FL_UP_BOX);
    b1->box(FL_FLAT_BOX);
    b1->color (color);


}

void drawAtom(Fl_Widget*w) {
    Fl_Window *window = new Fl_Window (1000,700);
    Fl_Int_Input *p=(Fl_Int_Input*)w;
    const char *o=p->value();
    int m=atoi(o);
    //m now has the value entered in the textbox

    int n,y=20,q;
    float x=-4,j,t;
    string a[118],b[118],c[118],d[118];

    readData("elements", a);
    readData("elements2", c);
    readData("elements3", b);
    readData("elements4", d);

    srand(time(NULL));

    q=(random()%4)+212;
    window->color (q); // set its color



    for(int n=1;n<=m;n++) {
        if(n==1||n==3||n==11||n==19||n==37||n==55||n==87) {

            j = angleElec(n);
            float t1=j;

            while(j<=6.28319) {

                for(int i=4;i>0;i-=0.05) {
                    for(x=-i;x<=i;x+=0.05) {
                        boxMaker(350+y*cos(j)+x,350+y*sin(j)+sqrt(i*i-x*x),1,1,FL_BLACK);
                        boxMaker(350+y*cos(j)+x,350+y*sin(j)-sqrt(i*i-x*x),1,1,FL_BLACK);
                    }
                }
                j+=t1;
            }

            y+=20;
            for(x=-y;x<=y;x+=0.1) {
                boxMaker(350-y,350,2,2,FL_GREEN);
                boxMaker(350+y,350,2,2,FL_GREEN);
                boxMaker(350+x,350+sqrt(y*y-x*x),2,2,FL_GREEN);
                boxMaker(350+x,350-sqrt(y*y-x*x),2,2,FL_GREEN);
            }
        }
    }

    if(m>86) j= 6.28318/(float)(m-86);
    else if(m>54) j= 6.28318/(float)(m-54);
         else if(m>36) j= 6.28318/(float)(m-36);
              else if(m>18) j= 6.28318/(float)(m-18); 
                   else if(m>10) j= 6.28318/(float)(m-10);
                        else if(m>2) j= 6.28318/(float)(m-2);
                             else if(m>0) j= 6.28318/(float)(m);
    t=j;

    while(j<=6.28319) {

        for(int i=4;i>0;i-=0.05) {
            for(x=-i;x<=i;x+=0.05) {
                boxMaker(350+y*cos(j)+x,350+y*sin(j)+sqrt(i*i-x*x),1,1,FL_BLACK); // It fills electrons in valence shell
                boxMaker(350+y*cos(j)+x,350+y*sin(j)-sqrt(i*i-x*x),1,1,FL_BLACK);
            }
        }

        j+=t;
    }

    for(y=5;y>0;y-=0.1) {
        for(x=-y;x<=y;x+=0.1) {
            boxMaker(350+x,350+sqrt(y*y-x*x),1,1,FL_RED); // It creates nucleus of atom
            boxMaker(350+x,350-sqrt(y*y-x*x),1,1,FL_RED);
        }
    }

    window->end();
    window->show();
}
int main (int argc, char *argv[]) {

    Fl_Window *window1 = new Fl_Window(500,500);
    Fl_Int_Input *inp = new Fl_Int_Input(0,0,500,100,"Enter atomic number here");
    inp->when(FL_WHEN_ENTER_KEY);
    inp->callback(drawAtom);
    window1->end();
    window1->show();


    return Fl::run();
} 
