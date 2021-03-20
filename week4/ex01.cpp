#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
//1.

Simple_window win (Point(100,100),1000,800, "ex01");

Smiley s(Point(100,100), 30);
win.attach(s);

s.set_fill_color(Color::yellow);

Frowny s2(Point(200,200), 30);

s2.set_fill_color(Color::red);

win.attach(s2);

Binary_tree tre(Point(300,300),3);

win.attach(tre);
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
