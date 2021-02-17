
#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
Point tl {100,100};
Simple_window win (tl, 600, 400, "Canvas");


Image gombi {Point{140,100},"gomboc.jpg"};
win.set_label("Gombi kutyus, azaz Gomboc");
win.attach(gombi);

Text t {Point{100,50}, "Gomboc, a baratnom kutyaja, egy igazi elbuvolo Shih-tzu holgy"};
win.attach(t);
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
