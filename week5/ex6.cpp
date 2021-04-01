#include "../lib_files/std_lib_facilities.h"
#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main()
try {
    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int r_min = 0;
    const int r_max = 20;

    const int x_scale = 20;
    const int y_scale = 20;

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Bar_chart test");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(x_orig,y_orig),xlength,xlength/x_scale,"1 egység = 15 pixel");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 egység = 15 pixel");
    y.set_color(Color::red);
    win.attach(y);

    Bar_graph bg(Point(x_orig+5,y_orig),y_scale,15,10);
    bg.addvalue(double(-15));
    bg.addvalue(double(15));
    bg.addvalue(double(5));
    bg.addvalue(double(6));
    win.attach(bg);
    win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
   cerr << "exception: " << '\n';
}
