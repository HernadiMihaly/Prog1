#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() {
using namespace Graph_lib;
try {
Simple_window win {Point{100,100},600,400,"Canvas"};
	
	win.wait_for_button();
	
	Rectangle rect {Point{250,150},100,30};
	
	win.attach(rect);
	win.set_label("Canvas 1");
	win.wait_for_button();
	
	Text t {Point{275,170},"Howdy"};
	
	win.attach(t);
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
