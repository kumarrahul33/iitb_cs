#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

class myCircle: public Fl_Widget{
    protected:
        int r;
        int x;
        int y;
    
    public:
        myCircle(int x, int y):Fl_Widget (x,y,20,20){
            r = 10;
            this->x = x;
            this->y = y;
        }

        void draw(){
            fl_color(fl_rgb_color(130));
            fl_pie (x,y,r,r,0,360);
        }
};

int main(int argc, const char** argv) {
    Fl_Window *window;
    window = new Fl_Window (600,600,"DEMO");
    
    new myCircle(0,100);

    window->color(FL_WHITE);
    window->end();
    window->show();
    return(Fl::run()); 

    return 0;
}