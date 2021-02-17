#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{

	Simple_window win {Point{100,100},800,600,"Canvas"};
	win.wait_for_button();
	
	Rectangle rect {Point{10,10},x_max()*2/3,y_max()*3/4};
	rect.set_style(Line_style(Line_style::solid,15));
	rect.set_color(Color::red);
	win.attach(rect);
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
