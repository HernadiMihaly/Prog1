#include "../lib_files/FL/Fl.H"
#include "../lib_files/FL/Fl_Box.H"
#include "../lib_files/FL/Fl_Window.H"
int main()
{
Fl_Window window(200, 200,"Window title");
Fl_Box Box(0,0,200,200,"Hey, I mean, Hello, World!");
window.show();
return Fl::run();
}

//g++ drill5_1.cpp -o drill5 `fltk-config --ldflags --use-images`
