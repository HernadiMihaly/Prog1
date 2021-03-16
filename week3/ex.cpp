#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"
#include "../lib_files/std_lib_facilities.h"

int main() 
{

using namespace Graph_lib;

try{
//1.

Simple_window win (Point(100,100),1200,1000, "Exes");

Arc a(Point(200,200),100,50,45,175);

a.set_major(140);
a.set_minor(90);
a.set_angle1(50);
a.set_angle2(200);

a.set_color(Color::dark_blue);
a.set_fill_color(Color::blue);
//a.set_angles(200,199);

win.attach(a);

//2.

/*Box b(Point(400,300), 200, 100);

b.set_height(150);
b.set_width(b.height());
b.set_color(Color::white);
b.set_fill_color(Color::blue);
win.attach(b); */

//Box b2(Point(300,260), Point(330,280), 45);
Box b2(Point(290,230), Point(330,280), 15);
b2.set_radius(19);
b2.set_color(Color::white);
b2.set_fill_color(Color::blue);
win.attach(b2);
//3.
Arrow arr(Point(240,312),Point(220,312));
win.attach(arr);

win.wait_for_button();

win.detach(arr);
win.detach(b2);
win.detach(a);

//6.

	//alsó dobozok
Vector_ref<BoxText> bb;

	int tavolsag= 150;
	int x1= 50;
	int x2= 150;
	int y1= 420;
	int y2= 450;
string k[7]= {"Line","Lines","Polygon","Axis","Rectangle","Text","Image"};

for (int i=0; i<7; ++i){

	bb.push_back(new BoxText(Point(x1,y1), Point(x2,y2), 15, k[i]));

	bb[bb.size()-1].set_fill_color(Color::green);

	win.attach(bb[bb.size()-1]);
	
	x1 +=tavolsag;
	x2 +=tavolsag;	
}

	//legfelső dobozok
	
Vector_ref<BoxText> bb2;

	int tavolsag2= 225;
	int x11= 200;
	int x22= 350;
	int y11= 100;
	int y22= 130;
string k2[3]= {"Window","Line_style","Color"};

for (int i=0; i<3; ++i){

	bb2.push_back(new BoxText(Point(x11,y11), Point(x22,y22), 15, k2[i]));

	bb2[bb2.size()-1].set_fill_color(Color::green);

	win.attach(bb2[bb2.size()-1]);
	
	x11 +=tavolsag2;
	x22 +=tavolsag2;
}

	//középső kettő doboz
Vector_ref<BoxText> bb3;

	int tavolsag3= 375;
	int x31= 200;
	int x32= 400;
	int y31= 250;
	int y32= 280;
string k3[2]= {"Simple_Window","Point"};

for (int i=0; i<2; ++i){

	bb3.push_back(new BoxText(Point(x31,y31), Point(x32,y32), 15, k3[i]));

	bb3[bb3.size()-1].set_fill_color(Color::green);

	win.attach(bb3[bb3.size()-1]);
	
	x31 +=tavolsag3;
	x32 +=tavolsag3;
}

//shape doboza
BoxText shape(Point(440,230),105,30,15,"Shape");
shape.set_fill_color(Color::green);
win.attach(shape);

//simple_window nyila
Arrow a1 (Point(300,250),Point(300,130));
win.attach(a1);
win.wait_for_button();

//a Shape doboza 105 hosszú, így 15-önként (t) kell növelni az Arrow végpontok távolságát 7*15=105, a Shape alja y=440-nél van, így a végpont 425-től kezdődik majd a ciklusban (vp=440-15=425)
//az alsó dobozok középpontjai közti távolság: 150(nyiltav), és x=100 tól kezdődnek
//a kp(kezdőpont) azért lesz -50, mert -50+nyiltav(ami 100) = 100, tehát a kezdőpont, a ciklusban így erre az értékre van szükség
int kp= -50;
int vp= 425;
int t=15;
int nyiltav=150;

Vector_ref<Arrow> ar1;

for (int i=0; i<7; ++i){
	ar1.push_back(new Arrow(Point(kp+nyiltav,420),Point(vp+t,260)));

	win.attach(ar1[ar1.size()-1]);
	vp +=t;
	kp +=nyiltav;
}
win.wait_for_button();
Simple_window win2 (Point(100,100),1200,1000, "Exes");
Vector_ref<Graph_lib::Rectangle> rects;
 for (int i1 = 0; i1<4; ++i1) {
        for (int i2 = 0; i2<4; ++i2) {
            for (int j = 0; j<20; ++j) {
                for (int k = 0; k<20; ++k) {
                    rects.push_back(new Graph_lib::Rectangle(Point(20*10*i1+10*k,20*10*i2+10*j),10,10)); 
                    //10*k és 10*j határozza meg melyik kis négyzetet rajzolom épp, 20*10*20*10= 200*200-as egy nagy négyzet
                    rects[rects.size()-1].set_fill_color(fl_rgb_color(15*(4*i1+i2),13*j,13*k));
                    rects[rects.size()-1].set_color(Color(Color::black,Color::invisible));
                    win2.attach(rects[rects.size()-1]);
                }
            }
        }
    }
    win2.wait_for_button();

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
