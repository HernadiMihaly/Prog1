#include <iostream>
#include <fstream>
#include <vector>
#include "../lib_files/Graph.h"
#include "../lib_files/Simple_window.h"

using namespace Graph_lib;

struct Distribution {
	Distribution(): year(0),young(0),mid(0),old(0){}
	int year,young,mid,old;
};

std::istream& operator>>(std::istream& is, Distribution& d){
	Distribution dd;
	char ch1,ch2,ch3;
	if  (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.mid >> dd.old >> ch3){
		if (ch1!= '(' || ch2!=':' || ch3!=')'){
			is.clear(std::ios_base::failbit);
			return is;
		}
	}
	else
		return is;
	d= dd;
	return is;
}

std::ostream& operator<< (std::ostream& os, Distribution& d){
	char space= ' ';
	char kettosp= ':';
	os << d.year << kettosp << d.young  << space << d.mid << space << d.old << space;
	return os;
}

class Scale { // data value to coordinate conversion
int cbase; // coordinate base
int vbase; // base of values
double scale;
public:
Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} { }
int operator()(int v) const { return cbase + (v-vbase)*scale; } 
};

int main() {
try {
	Distribution d;
	std::string file_name = "data.txt";
	std::ifstream ifs {file_name};
		if (!ifs) error ("can't open ",file_name);
	
	constexpr int xmax = 600; // window size
	constexpr int ymax = 400;
	constexpr int xoffset = 100; // distance from left-hand side of window to y axis
	constexpr int yoffset = 60; // distance from bottom of window to x axis
	constexpr int xspace = 40; // space beyond axis
	constexpr int yspace = 40;
	constexpr int xlength = xmax-xoffset-xspace; // length of axes
	constexpr int ylength = ymax-yoffset-yspace;

	constexpr int base_year = 1990;
	constexpr int end_year = 2020;
	constexpr double xscale = double(xlength)/(end_year-base_year);
	constexpr double yscale = double(ylength)/100;
	
	Scale xs {xoffset,base_year,xscale};
	Scale ys {ymax-yoffset,0,-yscale};
	
	Simple_window win {Point{100,100},xmax,ymax,"Aging Japan"};
	Axis xa {Axis::x, Point{xoffset,ymax-yoffset}, xlength,
	(end_year-base_year)/10,
	"year 1990                            2000                            2010                            2020 "};
	xa.label.move(-100,0);
	Axis y {Axis::y, Point{xoffset,ymax-yoffset}, ylength, 10,"% of population"};


	Open_polyline children;
	Open_polyline adults;
	Open_polyline aged;
	for (ifs; ifs>>d; ) {
	const int x = xs(d.year);
	children.add(Point{x,ys(d.young)});
	adults.add(Point{x,ys(d.mid)});
	aged.add(Point{x,ys(d.old)});
}
	Text children_label {Point{20,children.point(0).y},"age 0-14"};
	children.set_color(Color::red);
	children_label.set_color(Color::red);
	Text adults_label {Point{20,adults.point(0).y},"age 15-64"};
	adults.set_color(Color::blue);
	adults_label.set_color(Color::blue);
	Text aged_label {Point{20,aged.point(0).y},"age 65+"};
	aged.set_color(Color::dark_green);
	aged_label.set_color(Color::dark_green);
	
	win.attach(children_label);
	win.attach(adults_label);
	win.attach(aged_label);
	win.attach(children);
	win.attach(adults);
	win.attach(aged);
	
	win.attach(xa);
	win.attach(y);
	win.wait_for_button();

}
catch (std::exception& e) {
	std::cerr << e.what() << '\n';
}
catch (...) {
	std::cerr << "hiba" << '\n';
}

}
