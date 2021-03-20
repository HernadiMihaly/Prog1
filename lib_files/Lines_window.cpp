#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    menu_button{Point{x_max()-80,50}, 80, 20, "Color Menu", cb_colormenu},
    color_menu{Point{x_max()-70,50},70,20,Menu::vertical,"color"},
    lsmenu_button{Point{x_max()-160,50},80,20,"Ls Menu", cb_lsmenu},
    ls_menu{Point{x_max()-160,50},80,20,Menu::vertical, "style"},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    color_menu.attach(new Button(Point{0,0},0,0,"red",cb_red));
    color_menu.attach(new Button(Point{0,0},0,0,"blue",cb_blue));
    color_menu.attach(new Button(Point{0,0},0,0,"green",cb_green));
    color_menu.attach(new Button(Point{0,0},0,0,"black",cb_black));
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    
    ls_menu.attach(new Button(Point{0,0},0,0,"dot",cb_dot));
    ls_menu.attach(new Button(Point{0,0},0,0,"dash",cb_dash));
    ls_menu.attach(new Button(Point{0,0},0,0,"solid",cb_solid));
    ls_menu.attach(new Button(Point{0,0},0,0,"dashdot",cb_dashdot));
    ls_menu.attach(new Button(Point{0,0},0,0,"dashdotdot",cb_dashdotdot));
    attach(ls_menu);
    ls_menu.hide();
    attach(lsmenu_button);
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::cb_red(Address, Address pw){
	reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw){
	reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_green(Address, Address pw){
	reference_to<Lines_window>(pw).green_pressed();
}
void Lines_window::cb_black(Address, Address pw){
	reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_colormenu(Address, Address pw){
	reference_to<Lines_window>(pw).cmenu_pressed();
}

//ls-re vonatkozók:
void Lines_window::cb_dot(Address, Address pw){
	reference_to<Lines_window>(pw).dot_pressed();
}
void Lines_window::cb_dashdot(Address, Address pw){
	reference_to<Lines_window>(pw).dashdot_pressed();
}
void Lines_window::cb_dashdotdot(Address, Address pw){
	reference_to<Lines_window>(pw).dashdotdot_pressed();
}
void Lines_window::cb_solid(Address, Address pw){
	reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dash(Address, Address pw){
	reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_lsmenu(Address, Address pw){
	reference_to<Lines_window>(pw).lsmenu_pressed();
}

