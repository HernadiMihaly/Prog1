#include "../lib_files/std_lib_facilities.h"
#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int fac(int x){
	int r=1;
	while (x>1){
	r*=x;
	--x;
	}
	return r;
}

double term(int n){
	// kifejezés: 1 -1/3 +1/5 –1/7 +1/9 –1/11+ ... -> 1- 1/k + 1/k+2 + 1/k+4 ...stb
	double k= 2*n + 1;
	if (n%2==0){
		return 1.0 / k;
	}
	else {
		return 1.0 / (-1*k);
	}

}

double leibniz(int x){
	double osszeg= 0;
	for (int i=0; i<=x; i++){
		osszeg+= term(i);
	}
	return osszeg;
}

int main(){

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

for (int n = 0; n<50; ++n) {
	ostringstream ss;
	ss << "Approximation n== " << n ;
	win.set_label(ss.str());
	Function e ([n](double){return leibniz(n);}, min_range,max_range,orig,n_points,x_scale,y_scale);
	win.attach(e);
	win.wait_for_button();
	win.detach(e);

}
}
