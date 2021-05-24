#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
Point tl (Point(100,100));
Simple_window win (tl,1000,800, "ch13");
win.wait_for_button();

//Line és Point
Line h (Point(100,100), Point(200,100));
Line v (Point(150,50), Point(150,150));
win.attach(h);
win.attach(v);
win.wait_for_button();
win.detach(v);
win.detach(h);

//Lines
Lines grid;

int x_size=800;
int y_size=800;
int x_grid=100;
int y_grid=100;

for (int i=x_grid; i<x_size; i+=x_grid){
grid.add(Point(i,0), Point(i,y_size));
}
for (int y=y_grid; y<y_size; y+=y_grid){
grid.add(Point(0,y),Point(x_size,y));
}
win.attach(grid);
win.wait_for_button();

//Color, Line_style
grid.set_color(Color::red);
grid.set_style(Line_style(Line_style::dot,2));
win.wait_for_button();
win.detach(grid);

//Open_polyline
Open_polyline opl= { {100,100}, {150,200}, {300,200}};
win.attach(opl);
win.wait_for_button();
win.detach(opl);

//Closed_polyline
Closed_polyline cpl= { {300,300}, {350,400}, {500,300}};
win.attach(cpl);
win.wait_for_button();

//Polygon
Polygon poly= { {100,100}, {150,200}, {250,250}};
win.attach(poly);
win.wait_for_button();

//Rectangle
Rectangle r (Point(500,500), 50, 50);
win.wait_for_button();

Rectangle r2 (Point(10,10), Point(100,100));
r.set_fill_color(Color::yellow);
r2.set_fill_color(Color::blue);
win.attach(r);
win.attach(r2);
win.wait_for_button();

Simple_window win20 (tl, 800, 600, "SW");
Vector_ref<Rectangle> vr;
for (int i = 0; i<16; ++i)
for (int j = 0; j<16; ++j) {
vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
vr[vr.size()-1].set_fill_color(Color{i*16+j});
win20.attach(vr[vr.size()-1]);
}
win20.wait_for_button();

//Font és Text
Text t (Point(600,500), "Font_type átállítva");
t.set_font(Graph_lib::Font::helvetica);
win20.attach(t);
win20.wait_for_button();

//Circle és Ellipse
Circle kor (Point(400,400), 20);
Ellipse el (Point(400,250), 20, 10);
win20.attach(kor);
win20.attach(el);
win20.wait_for_button();

Simple_window win2 (tl, 800, 600, "SW");
//Marked polyline
Marked_polyline mpl {"1234"};
mpl.add(Point(100,100));
mpl.add(Point(150,200));
mpl.add(Point(250,250));
mpl.add(Point(300,200));
win2.attach(mpl);
win2.wait_for_button();
win2.detach(mpl);

//Marks és Mark
Marks pp {"x",{{100,100}, {150,200}, {250,250}, {300,200}}};
win2.attach(pp);
win2.wait_for_button();
win2.detach(pp);

Marks marks("O");
marks.add(Point(100,100));
marks.add(Point(150,200));
marks.add(Point(250,250));
marks.add(Point(300,200));
win2.attach(marks);
win2.wait_for_button();

Mark marko(Point(350,500),'X');
win2.attach(marko);
win2.wait_for_button();
win2.detach(marko);
win2.detach(marks);

//Image
Image kep (Point(200,200), "kep.jpg");
win2.attach(kep);
win2.wait_for_button();

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
