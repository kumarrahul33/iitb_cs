#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <bits/stdc++.h>
#include <FL/fl_draw.H>
#include <FL/names.h>  

class Coordinates{
	double x;
	double y;
	double centerX;
	double centerY;
//_x is the radial distance and _y is the angle with x-axis
	public:
		Coordinates(){};
		Coordinates(double _x, double _y, double widthX, double widthY){
			_y = (_y/180)*M_PI;
			centerX = widthX/2;
			centerY = widthY/2;

			double newX = centerX + _x * cos(_y);
			double newY = centerY - _x * sin(_y);

			x = newX;
			y = newY;

			
		}
		Coordinates(double _x, double _y){
			_y = (_y/180)*M_PI;
			double centerX = 1250/2;
			double centerY = 1000/2;

			double newX = centerX + _x * cos(_y);
			double newY = centerY - _x * sin(_y);

			x = newX;
			y = newY;
		}

		double getX(){return x;}
		double getY(){return y;}

		
};


class CircleDesign : public Fl_Widget{
	int radius;
	double x;
	double y;
	int n;
	

  public:

	CircleDesign (int winx, int winy, int s1, int s2, int _radius, char *label=0) : Fl_Widget (winx, winy, s1,s2,label) {
			radius = _radius; 
			x = winx;
			y = winy;
			n = 20;
		}
	
	void wipe(){
		fl_draw_box (FL_FLAT_BOX,Coordinates(0,0,x,y).getX(),Coordinates(0,0,x,y).getY(),radius*2,radius*2,FL_BLACK);
	}

	void draw(){
		fl_color (FL_RED);
		fl_circle(Coordinates(0,0,x,y).getX(),Coordinates(0,0,x,y).getY(),radius*1.414);
		
		//int n = 15;
		for (int i = 0; i < n; i++)
		{
			fl_color (FL_RED);
			fl_circle(Coordinates(radius,360.0*i/n,x,y).getX(), Coordinates(radius,360*i/n,x,y).getY(),radius);
		}
		n = n/2;
		for (int i = 0; i < n; i++)
		{
			fl_color (FL_RED);
			fl_circle(Coordinates(radius/2,360.0*i/n,x,y).getX(), Coordinates(radius/2,360*i/n,x,y).getY(),radius/2);
		}

		n = n*2 + 1;
	}

	virtual int handle(int e){
		if(e==FL_PUSH){
			printf("Event was %s (%d)\n", fl_eventnames[e], e);
			n += 1;
			wipe();
			//redraw();			
		}

		return 1;
	}
};

class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h;
	public:
		Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
		}
		virtual void draw()=0;
		virtual void wipe()=0;
		virtual void refresh(int dx, int dy)=0;
		virtual int handle(int e) {
			if (e==FL_PUSH) {
				wipe();
				draw();
				refresh(40,10);
			}	
			return 1;
		}; 
};

class MyRectangle : public Shape {
 public:
   MyRectangle (int x,int y,int w, int h) : Shape (x,y,w,h) { }
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
   }

   virtual void refresh(int dx, int dy) {
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
   }

};


int main() {
  Fl_Window w(1300,1000,"window1");
  
//   triDesign t1(220,250+20,1000,1000,250);
//   triDesignInv t2(220+215,125+20,1000,1000,250);
//   triDesign t3(220*3-10,250+20,1000,1000,250);
//   triDesignInv t4(220*3-10+215,125+20,1000,1000,250);
//   triDesign t5(220*3-10+430,250+20,1000,1000,250);

//   triDesignInv t6(220,250+125+125+20,1000,1000,250);
//   triDesign t7(220+215,250*2+125+20,1000,1000,250);
//   triDesignInv t8(220*3-10,250+250+20,1000,1000,250);
//   triDesign t9(220*3-10+215,250*2+125+20,1000,1000,250);
//   triDesignInv t10(220*3-10+430,250*2+20,1000,1000,250);

  

 
  CircleDesign p(1300,1000,1300/2,1000/2,175);

  MyRectangle Rectangle1(100,100,100,100);
 

  w.color(FL_BLACK);
  w.show();
  return (Fl::run());
}
