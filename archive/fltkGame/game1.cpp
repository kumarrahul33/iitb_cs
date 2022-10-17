#include <iostream>

#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <unistd.h>
#include <chrono>
#include <FL/Fl_Timer.H>

#include <random>
void timeractions(void *p);
void newGame(void *p);
int run[8] ={INT32_MIN,100,160,210,360,420,500,INT32_MAX};
long long int gametime = 0;
bool hitit = false;

int window_width = 1200;
int window_height = 600;
int wicket_height = 200;

//to make random intergers
std::random_device rd; 
std::mt19937 gen(rd()); 
std::uniform_int_distribution<> distr(25, 40);
std::uniform_int_distribution<> distrGravity(1,12);
std::uniform_int_distribution<> distrBallgravity(5,12);

class MyRectangle : public Fl_Widget {
    protected:
	    int x, y, w, h;
    public:
        MyRectangle (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
        }
        virtual void draw() {
            fl_color(std::rand() % ( 250 + 1 ));
            fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
        }
};

//batsman 
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

        virtual int handle(int e){
            if(e == FL_PUSH){
                if(gametime < 40 && gametime > 35) hitit = true;
            }

            return 1;
        }



};

class Ball : public Fl_Widget {
    protected:
        int x, y, w, h;
        double speed, gravity;
        Ball* ball2;
    public:

        Ball (int x,int y,int w, int h, double speed, double gravity) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
            this->speed = speed;
            //this->angle = angle;
            this->gravity = gravity;
        }
        Ball (int x,int y,int w, int h) : Fl_Widget (x,y,w,h){
            this->x=x; this->y=y;
            this->w=w; this->h=h;
            this->speed = -10;
            //this->angle = 0;
            this->gravity = 0;
        }

        friend void timeractions(void *p);
        friend void newGame(void *p);
        
        virtual void wipe(){
            //fl_draw_box(FL_FLAT_BOX,x,y,50,50,red);
            fl_color(FL_BLACK);
            fl_pie (x,y,15,15,0,360);
        }
        virtual void draw(){
            fl_color(FL_RED);
            fl_pie (x,y,15,15,0,360);
        }

        void checkScore(){
            for (int i = 0; i < 7; i++)
            {
                if(y > run[i] && y < run[i+1]){
                    fl_draw_box (FL_FLAT_BOX,550,0,100,60,FL_BLACK);
                    fl_color(FL_WHITE);
                    
                    switch (i)
                    {
                        case 0:
                            fl_draw("6 run",600,50);
                            break;
                        
                        case 1:
                            fl_draw("5 run",600,50);
                            break;
                        
                        case 2:
                            fl_draw("4 run",600,50);
                            break;

                        case 3:
                            fl_draw("3 run",600,50);
                            break;

                        case 4:
                            fl_draw("2 run",600,50);
                            break;

                        case 5:
                            fl_draw("1 run",600,50);
                            break;

                        case 6:
                            fl_draw("0 run",600,50);
                            break;

                        default:
                            break;
                    }
                }
            }
            
            
        }
       
        // void changeTrajectory(double gravity,speed){

        // }
        void gamePlay(){
            if ((y+gravity >=585) && gravity >=0 ) gravity = -gravity; 
            if (x < 184 && x>100 && hitit){
                speed =  distr(gen);
                gravity = -distrGravity(gen);
                hitit = false;
            }

            if(x>1100 && speed > 0){
                checkScore();

            }

            if(x<50 && y>600-wicket_height){
                fl_color(FL_WHITE);
                fl_draw("OUT",600,50);
                //wipe();
                newGame(this);
                gametime = 0;
                hitit = false;
            }

            if(x > 1200 || x<0){
                newGame(this);
                gametime = 0;
                hitit = false;
            }

            




            ball2 = new Ball(x+speed,y+gravity,w,h,speed,gravity);
            ball2->draw();
            ball2->color(FL_GREEN);
            this->wipe();
            Fl::add_timeout(0.05,timeractions,ball2);
        }

        ~Ball(){
            
        }

};
//used in moving the ball every frame
void timeractions(void *p)
{ 
    ((Ball *)p) -> gamePlay();
    delete ((Ball *)p);
    gametime++;
}



void makegameComponets(){
    new MyRectangle(50,window_height-wicket_height,30,wicket_height);

    for (int i = 0; i < 6; i++){
        new MyRectangle(1200-40,run[i],40,20);
    }
    new batsman(150,400,30,200);
}

void newGame(void *p){
    makegameComponets();
    delete ((Ball *)p);
    new Ball(1100,400,100,100,-25,distrBallgravity(gen));
}




int main(int argc, char const *argv[])
{
    Fl_Window *window;   

    window = new Fl_Window (window_width,window_height,"Cricket"); 
    makegameComponets();

    Ball* ball1 = new Ball(1100,400,400,600,-25,8);
    window->color(FL_BLACK);
    window->end();
    window->show();
    Fl::add_timeout(0.1,timeractions,ball1) ;
   
    return(Fl::run());


    return 0;
}
