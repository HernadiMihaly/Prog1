#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{

	Simple_window win {Point{100,100},600,400,"Canvas"};
	
	Circle c1 {Point{100,100},50};
	
	c1.set_color(Color::blue);
	c1.set_style(Line_style(Line_style::solid,10));
	win.attach(c1);
	
	Circle c2 {Point{160,150},50};
	
	c2.set_color(Color::yellow);
	c2.set_style(Line_style(Line_style::solid,10));
	win.attach(c2);
	
	Circle c3 {Point{220,100},50};
	
	c3.set_style(Line_style(Line_style::solid,10));
	win.attach(c3);
	
	Circle c4 {Point{280,150},50};
	
	c4.set_color(Color::dark_green);
	c4.set_style(Line_style(Line_style::solid,10));
	win.attach(c4);
	
	Circle c5 {Point{340,100},50};
	
	c5.set_color(Color::red);
	c5.set_style(Line_style(Line_style::solid,10));
	win.attach(c5);
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
