#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <cstdlib>
#include <FL/fl_draw.H>
class rangoli1 : public Fl_Widget{
    int radius;
    public:
        rangoli1(int winx, int winy, int s1, int s2, int _radius, char *label=0) : Fl_Widget (winx, winy, s1,s2,label) {}

        void draw(){
            fl_color(FL_GREEN);
            fl_circle(500,500,radius);
        }
};