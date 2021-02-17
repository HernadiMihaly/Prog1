#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
	Simple_window win {Point{100,100},600,400, "Canvas haziko"};
	win.wait_for_button();
	//haz alapja
	Rectangle haz {Point{200,200},200,200};
	
	haz.set_fill_color(Color::cyan);
	win.attach(haz);
	win.wait_for_button();
	//teteje
	Polygon teto;
	teto.add(Point{200,200});
	teto.add(Point{300,100});
	teto.add(Point{400,200});
	
	teto.set_fill_color(Color::red);
	win.attach(teto);
	win.wait_for_button();
	//ajto & kilincs
	Rectangle ajto {Point{290,340},20,60};
	ajto.set_fill_color(Color::black);
	win.attach(ajto);
	win.wait_for_button();
	
	Circle kilincs {Point{294,370},3};
	kilincs.set_color(Color::red);
	win.attach(kilincs);
	win.wait_for_button();
	//ablak
	
	Rectangle ablak {Point{235,260},40,40};
	Rectangle ablak2 {Point{325,260},40,40};
	
	ablak.set_fill_color(Color::white);
	ablak2.set_fill_color(Color::white);
	win.attach(ablak);
	win.attach(ablak2);
	win.wait_for_button();
	
	//ablak keret
	Open_polyline keret;
	keret.add(Point{235,280});
	keret.add(Point{275,280});
	win.attach(keret);
	
	Open_polyline keret1;
	keret1.add(Point{255,260});
	keret1.add(Point{255,300});
	win.attach(keret1);
	
	Open_polyline keret2;
	keret2.add(Point{325,280});
	keret2.add(Point{365,280});
	win.attach(keret2);
	
	Open_polyline keret3;
	keret3.add(Point{345,260});
	keret3.add(Point{345,300});
	win.attach(keret3);
	win.wait_for_button();
	
	//kemeny
	Closed_polyline kemeny;
	kemeny.add(Point{200,200});
	kemeny.add(Point{200,150});
	kemeny.add(Point{220,150});
	kemeny.add(Point{220,180});
	
	kemeny.set_fill_color(Color::black);
	win.attach(kemeny);
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
