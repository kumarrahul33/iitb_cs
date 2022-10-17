#include<iostream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

void callback(void*) {
  puts("TICK");
  Fl::repeat_timeout(1.0, callback);
}
 
int main() {
  Fl::add_timeout(1.0, callback);
  return Fl::run();
}