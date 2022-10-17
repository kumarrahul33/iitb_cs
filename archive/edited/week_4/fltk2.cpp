#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <bits/stdc++.h>
#include <FL/fl_draw.H>

class Coordinates{
	double x;
	double y;
	double centerX;
	double centerY;

	public:
		Coordinates(){};
		Coordinates(double _x, double _y, double _centerX, double _centerY){
			_y = (_y/180)*M_PI;
			double centerX = 1250/2;
			double centerY = 1000/2;

			double newX = _centerX + _x * cos(_y);
			double newY = _centerY - _x * sin(_y);

			x = newX;
			y = newY;

			centerX = _centerX;
			centerY = _centerY;
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
	

  public:

	CircleDesign (int winx, int winy, int s1, int s2, int _radius, char *label=0) : Fl_Widget (winx, winy, s1,s2,label) {
		radius = _radius; 
		x = winx;
		y = winy;
		}

	void draw(){
		fl_color (FL_RED);
		fl_circle(Coordinates(0,0,x,y).getX(),Coordinates(0,0,x,y).getY(),radius*1.414);
		
		int n = 15;
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
	}
};

class triDesign : Fl_Widget{
	protected:
		int length;
		int x;
		int y;

	public:
		triDesign(int winx, int winy, int s1, int s2, int _length, char *label=0) : Fl_Widget (winx, winy, s1,s2,label) {
			length = _length;
			x = winx;
			y = winy;
		}

		virtual void draw(){
			fl_color ((int) random()%256);
			fl_polygon(x, y-length, x-(length*pow(3,.5))/2, y+length/2.0, x+(length*pow(3,.5))/2, y+length/2.0);
			fl_color ((int) random()%256);
			fl_polygon(x, y-length/1.5, x-(length*pow(3,.5))/(2*1.5), y+length/(1.5*2.0), x+(length*pow(3,.5))/(2*1.5), y+length/(1.5*2.0));
			fl_color ((int) random()%256);
			fl_polygon(x, y-length/3.0, x-(length*pow(3,.5))/(3.0*2), y+length/(3*2.0), x+(length*pow(3,.5))/(3*2.0), y+length/(3*2.0));
		}
};

class triDesignInv : triDesign{
	public:
		triDesignInv(int winx, int winy, int s1, int s2, int _length, char *label=0) : triDesign(winx, winy, s1, s2, _length){}
		virtual void draw(){
			fl_color ((int) random()%256);
			fl_polygon(x, y+length, x+(length*pow(3,.5))/2, y-length/2.0, x-(length*pow(3,.5))/2, y-length/2.0);
			fl_color ((int) random()%256);
			fl_polygon(x, y+length/1.5, x+(length*pow(3,.5))/(2*1.5), y-length/(1.5*2.0), x-(length*pow(3,.5))/(2*1.5), y-length/(1.5*2.0));
			fl_color ((int) random()%256);
			fl_polygon(x, y+length/3.0, x+(length*pow(3,.5))/(3.0*2), y-length/(3*2.0), x-(length*pow(3,.5))/(3*2.0), y-length/(3*2.0));
		}
};


int main() {
  Fl_Window w(1300,1000,"window1");
  
  triDesign t1(220,250+20,1000,1000,250);
  triDesignInv t2(220+215,125+20,1000,1000,250);
  triDesign t3(220*3-10,250+20,1000,1000,250);
  triDesignInv t4(220*3-10+215,125+20,1000,1000,250);
  triDesign t5(220*3-10+430,250+20,1000,1000,250);

  triDesignInv t6(220,250+125+125+20,1000,1000,250);
  triDesign t7(220+215,250*2+125+20,1000,1000,250);
  triDesignInv t8(220*3-10,250+250+20,1000,1000,250);
  triDesign t9(220*3-10+215,250*2+125+20,1000,1000,250);
  triDesignInv t10(220*3-10+430,250*2+20,1000,1000,250);

  

 
  CircleDesign p(650,400,1000,1000,175);
 

  w.color(56);
  w.show();
  return (Fl::run());
}
