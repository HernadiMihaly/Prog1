#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
//1.

Simple_window win (Point(100,100),1000,800, "Drill #2");
//2.
int x_size=800;
int y_size=800;
int x_grid=100;
int y_grid=100;

Lines grid;

for (int i=x_grid; i<x_size; i+=x_grid){
grid.add(Point(i,0), Point(i,y_size));
}
for (int y=y_grid; y<y_size; y+=y_grid){
grid.add(Point(0,y),Point(x_size,y));
}
win.attach(grid);

//3.

Vector_ref<Rectangle> vr;

for (int i=0; i<8; ++i){
vr.push_back(new Rectangle(Point(i*100,i*100),100,100));
vr[vr.size()-1].set_fill_color(Color::red);
win.attach(vr[vr.size()-1]);
}
//4.

 Image kep1(Point(300,0),"kep.jpg");
    kep1.set_mask(Point(0,0),200,200);
    win.attach(kep1);
    Image kep2(Point(500,200),"kep.jpg");
    kep2.set_mask(Point(0,0),200,200);
    win.attach(kep2);
    Image kep3(Point(0,300),"kep.jpg");
    kep3.set_mask(Point(0,0),200,200);
    win.attach(kep3);
   win.wait_for_button();
   
//5.

int k=0;
for (int j=0; j<8; j++)
	{
	
	   for (int i=0; i<800; i+=100){
	   Image kep4(Point(i,k),"image.jpg");
	    win.attach(kep4);
	    win.wait_for_button();
	    }
	    k+=100;
    }
    
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
