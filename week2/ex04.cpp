#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
	Point tl {100,100};
	Simple_window win (tl, 600, 400, "Canvas #XO");
	
	win.wait_for_button();
	
	Rectangle n1 {Point{0,0},100,100};
	
	n1.set_fill_color(Color::white);
	win.attach(n1);
	
	Rectangle n2 {Point{0,100},100,100};
	
	n2.set_fill_color(Color::red);
	win.attach(n2);
	
	Rectangle n3 {Point{0,200},100,100};
	
	n3.set_fill_color(Color::white);
	win.attach(n3);
	
	Rectangle n4 {Point{100,0},100,100};
	
	n4.set_fill_color(Color::red);
	win.attach(n4);
	
	Rectangle n5 {Point{200,0},100,100};
	
	n5.set_fill_color(Color::white);
	win.attach(n5);
	
	Rectangle n6 {Point{100,100},100,100};
	
	n6.set_fill_color(Color::white);
	win.attach(n6);
	
	Rectangle n7 {Point{200,100},100,100};
	
	n7.set_fill_color(Color::red);
	win.attach(n7);
	
	Rectangle n8 {Point{100,200},100,100};
	
	n8.set_fill_color(Color::red);
	win.attach(n8);
	
	Rectangle n9 {Point{200,200},100,100};
	
	n9.set_fill_color(Color::white);
	win.attach(n9);
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
