//g++ first.cpp ../lib_files/Graph.cpp ../lib_files/Window.cpp ../lib_files/GUI.cpp ../lib_files/Simple_window.cpp -o first `fltk-config --ldflags --use-images`


#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
	
	//7.2
	
	Point tl {100,100};
	Simple_window win (tl, 600, 400, "Canvas");
	
	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	poly.set_color(Color::red);
	
	win.attach(poly);
	
	win.wait_for_button();
	
	//7.3
	
	Axis xt {Axis::x, Point{30,250}, 500, 8, "X tengely"};
	
	win.attach(xt);
	win.set_label("My window 2");
	win.wait_for_button();
	
	Axis yt {Axis::y, Point{30,250}, 200, 8, "Y tengely"};
	
	yt.set_color(Color::white);
	yt.label.set_color(Color::blue);
	win.attach(yt);
	win.set_label("My window 3");
	win.wait_for_button();
	
	//7.4
	
	Function sine {sin,0,99,Point{30,200},10000,50,50};
	
	win.attach(sine);
	win.set_label("My window 4");
	win.wait_for_button();
	
	
	//7.5
	
	sine.set_color(Color::red);
	
	Polygon haromszog;
	
	haromszog.add(Point{100,100});
	haromszog.add(Point{50,200});
	haromszog.add(Point{150,200});
	
	haromszog.set_color(Color::yellow);
	haromszog.set_style(Line_style::dot);
	win.attach(haromszog);
	win.set_label("My window 5");
	win.wait_for_button();
	
	//7.6 & 7.6.1
	
	Rectangle r {Point{100,50},100,50};
	
	win.attach(r);
	win.set_label("My window 6");
	win.wait_for_button();
	
	Closed_polyline notrect;
	notrect.add(Point{300,100});
	notrect.add(Point{400,100});
	notrect.add(Point{300,150});
	notrect.add(Point{400,150});
	
	win.attach(notrect);
	win.set_label("My window 6.1");
	win.wait_for_button();
	
	//7.7
	
	r.set_fill_color(Color::blue);
	haromszog.set_style(Line_style(Line_style::dot,3));
	notrect.set_style(Line_style(Line_style::dash,3));
	notrect.set_fill_color(Color::yellow);
	win.set_label("My window 7");
	win.wait_for_button();
	
	//7.8
	
	Text t {Point{40,300}, "Ez a legelso grafikus munkam"};
	
	win.attach(t);
	win.set_label("My window 8");
	win.wait_for_button();
	
	//7.8.1
	
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(16);
	win.set_label("My window 8.1");
	win.wait_for_button();
	
	//7.9 & 7.9.1
	
	Image kep {Point{200,200}, "kep.jpg"};
	win.attach(kep);
	win.set_label("My window 9");
	win.wait_for_button();
	
	kep.move(115,20);
	win.set_label("My window 9.1");
	win.wait_for_button();
	
	//7.10
	
	Circle kor {Point{60,60},20};
	Ellipse e {Point{60,60},30,10};
	
	e.set_color(Color::blue);
	Mark m {Point{60,60},'x'};
	
	ostringstream szov;
	szov << "Kepernyo merete: " << x_max() << "*" << y_max()
		<<"; Ablak merete: " << win.x_max() << "*" << win.y_max();
	Text meretek {Point{20,10}, szov.str()};
	
	Image garfield {Point{400,100}, "garfield.gif"};
	garfield.set_mask(Point{10,10},250,150);
	win.attach(kor);
	win.attach(m);
	win.attach(e);
	
	win.attach(meretek);
	win.attach(garfield);
	win.set_label("My window 10");
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
