#include <iostream>
#include "../lib_files/std_lib_facilities.h"
#include "../lib_files/Graph.h"
#include "../lib_files/Simple_window.h"

int fac(int n);

double one(double){return 1;}

int main(){
try {
//1.feladat:
	int szam=0;
	while(szam<20){
		cout << "A " <<szam<< "-ik faktoriális értéke: " << fac(szam) << '\n';
		szam++;
	}
	
//2.feladat
Point tl(100,100);

constexpr int xmax= 600;
constexpr int ymax= 600;

Simple_window win (tl,xmax,ymax, "ex2");

constexpr int x_orig= ymax/2;
constexpr int y_orig= xmax/2;
const Point orig(x_orig, y_orig);

constexpr int x_scale= 20;
constexpr int y_scale= 20;

constexpr int min_range= -10;
constexpr int max_range= 11;
constexpr int n_points= 400;

Funct f1 (one,min_range,max_range,orig,n_points,x_scale, y_scale);
win.attach(f1);
win.wait_for_button();
f1.resetFct(cos);
win.attach(f1);
win.wait_for_button();
f1.resetPrecision(10);
win.attach(f1);
win.wait_for_button();
}

catch(exception& e) {
cerr << e.what() << '\n';
}
catch(...){
cerr << "egyeb hiba" << '\n';
}
}

int fac(int n) { return n>1 ? n*fac(n-1):1; }
