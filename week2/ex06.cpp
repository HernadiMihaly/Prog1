#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
	//shape ami nem fer bele a windowba
	Simple_window win {Point{100,100},600,400,"Canvas"};

	win.wait_for_button();
	
	Rectangle r {Point{10,10},700,500};
	
	r.set_fill_color(Color::red);
	win.attach(r);
	win.wait_for_button();
	
	//window ami nem fer bele a screenbe
	Simple_window win2 {Point{100,100},3*x_max(),3*y_max(),"Canvas"};
	win2.wait_for_button();
	//lathatoan itt mar teljesen mutatni fogja azt a rectangle-t amit elobb nem teljesen
	Rectangle r2 {Point{10,10},700,500};
	win2.attach(r2);
	r2.set_fill_color(Color::blue);
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
