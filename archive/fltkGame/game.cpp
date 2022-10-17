#include<iostream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <unistd.h>
#include <chrono>
#include <FL/Fl_Timer.H>
void timeractions(void *p);

class MyRectangle : public Fl_Widget {
    protected:
	    int x, y, w, h;
    public:
        MyRectangle (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
        }
        virtual void draw() {
        fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
        }
};

class MyCircle : public Fl_Widget {
    protected:
	    int x, y, w, h;
    public:
        MyCircle (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
        }

        virtual void draw() {
            fl_color(fl_rgb_color(130));
            fl_pie (x,y,w,h,0,360);
        }
};

class batsman : public Fl_Widget {
    protected:
        int x, y, w, h;
    public:
        batsman (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
        }
        virtual void draw() {
            // new MyCircle(x,y,w,h);
            // new MyRectangle(x,y,w,h);
            fl_color(fl_rgb_color(130));
            fl_pie (x-w*.25,y-w*1.5,w*1.5,w*1.5,0,360);
            fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
        }


};


class Ball : public Fl_Widget {
    protected:
        int x, y, w, h;
        double speed, angle, gravity;
        Ball* ball2;
    public:

        Ball (int x,int y,int w, int h, double speed, double angle, double gravity) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
            this->speed = speed;
            this->angle = angle;
            this->gravity = gravity;
            ball2 = new Ball(x+speed,y,w,h);
        }
        Ball (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
            this->speed = -10;
            this->angle = 0;
            this->gravity = 0;
            ball2 = new Ball(x+speed,y,w,h,speed,angle,gravity);
        }
        friend void timeractions(void *p);
        
        virtual void wipe(){
            fl_draw_box(FL_FLAT_BOX,x,y,h,w,FL_WHITE);
        }
        virtual void draw(){
            fl_pie (x,y,w,h,0,360);
        }
        // virtual void move(){
        //     delete this;
        // }

       
        void changeTrajectory(double angle, double gravity){

        }

        ~Ball(){
            Fl::add_timeout(0.1,timeractions,ball2);
        }
    
};

void timeractions(void *p)
{ //this is the function that provides periodicity to the program
	delete ((Ball *)p);
}





int main(int argc, char const *argv[])
{
    Fl_Window *window;

    int window_width = 1200;
    int window_height = 600;
    int wicket_height = 150;

    window = new Fl_Window (window_width,window_height,"DEMO"); // outer window
    new MyRectangle(50,window_height-wicket_height,30,150);
    new batsman(150,400,30,200);
    Ball* ball1 = new Ball(500,50,600,600);
    window->color(FL_BLACK);
    window->end();
    window->show();
    // while (true) {
    //     ball1.move();
    //     Fl::check();
    // }
    Fl::add_timeout(0.1, timeractions,ball1) ;
   
    return(Fl::run());


    return 0;
}
