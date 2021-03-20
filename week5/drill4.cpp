#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

double one(double) {return 1;}

double slope(double x) {return x/2;}

double sloping_cos(double x) { return cos(x) + slope(x); }

int main() 
{

using namespace Graph_lib;

try{

//ablak beállításai
constexpr int xmax= 600;
constexpr int ymax= 600;
Point tl {100,100};

Simple_window win (tl,xmax,ymax, "Function graphs");

//tengelyek beállításai
constexpr int xlength= xmax-200;
constexpr int ylength= ymax-200;
constexpr int x_orig= ymax/2;
constexpr int y_orig= xmax/2;
const Point orig(x_orig, y_orig);

constexpr int x_scale= 20;
constexpr int y_scale= 20;

Axis x (Axis::x,Point(100,y_orig),xlength,xlength/x_scale ,"1 == 20 pixels" );
Axis y (Axis::y,Point(x_orig,500),ylength,ylength/y_scale ,"1 == 20 pixels" );

x.set_color(Color::red);
y.set_color(Color::red);

//függvények és beállításaik

constexpr int min_range= -10;
constexpr int max_range= 11;
constexpr int n_points= 400;


Function f1 (one,min_range,max_range,orig,n_points,x_scale, y_scale);
Function f2 (slope,min_range,max_range,orig,n_points,x_scale,y_scale);
Function f3 ([](double x) { return x * x; }, min_range, max_range, orig, n_points, x_scale, y_scale);
Function f4  (cos, min_range, max_range, orig, n_points, x_scale, y_scale);
Function f5  (sloping_cos, min_range, max_range, orig, n_points, x_scale, y_scale);

Text t (Point(100,y_orig+y_orig/4), "x/2");
f4.set_color(Color::blue);

win.attach(x);
win.attach(y);
win.attach(f1);
win.attach(f2);
win.attach(t);
win.attach(f3);
win.attach(f4);
win.attach(f5);

win.wait_for_button();
    
}
catch(exception& e){
cerr << "exception: " << e.what() << '\n';
return 1;
}
catch(...){
cerr << "Valami hiba tortent!" << '\n';
return 2;
}
}
