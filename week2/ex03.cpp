#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() {
using namespace Graph_lib;
try {
	Simple_window win {Point{100,100},600,400,"Canvas"};
	
	win.wait_for_button();
	
	Closed_polyline letterh;
	
	letterh.add(Point{100,100});
	letterh.add(Point{100,175});
	letterh.add(Point{200,175});
	letterh.add(Point{200,100});
	letterh.add(Point{200,250});
	letterh.add(Point{200,175});
	letterh.add(Point{100,175});
	letterh.add(Point{100,250});
	
	letterh.set_style(Line_style(Line_style::solid,5));
	letterh.set_color(Color::blue);
	win.attach(letterh);
	win.set_label("Canvas 1");
	win.wait_for_button();
	
	Open_polyline letterm;
	
	letterm.add(Point{250,250});
	letterm.add(Point{250,100});
	letterm.add(Point{300,130});
	letterm.add(Point{350,100});
	letterm.add(Point{350,250});
	
	letterm.set_style(Line_style(Line_style::solid,5));
	letterm.set_color(Color::white);
	win.attach(letterm);
	win.set_label("Canvas 2");
	win.wait_for_button();	

}
catch(exception& e){
cerr << "Exception: " << e.what() << '\n';
}
catch(...){
cerr << "Hiba tortent" << '\n';
}

}
