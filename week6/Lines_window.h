#include "GUI.h"

using namespace Graph_lib;

struct Lines_window: Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title);
	
private:
	
	Open_polyline lines;
	
	Button next_button;
	Button quit_button;
	Button menu_button;
	Button lsmenu_button; //linestyle gomb
	
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	
	Menu color_menu;
	Menu ls_menu;
	
	bool wait_for_button();
	
	void red_pressed() {change(Color::red); hide_menu();}
	void green_pressed() {change(Color::green); hide_menu();}
	void blue_pressed() {change(Color::blue); hide_menu();}
	void black_pressed() {change(Color::black); hide_menu();}
	void cmenu_pressed() {menu_button.hide(); color_menu.show();}
	
	
	void dot_pressed() {change_style(Line_style::dot),hide_lsmenu();};
	void dash_pressed() {change_style(Line_style::dash),hide_lsmenu();};
	void solid_pressed() {change_style(Line_style::solid),hide_lsmenu();};
	void dashdot_pressed() {change_style(Line_style::dashdot),hide_lsmenu();};
	void dashdotdot_pressed() {change_style(Line_style::dashdotdot),hide_lsmenu();};
	void lsmenu_pressed() {lsmenu_button.hide(); ls_menu.show();}
	
	static void cb_red(Address, Address);
	static void cb_green(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_colormenu(Address, Address);
	
	static void cb_solid(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_dashdot(Address, Address);
	static void cb_dashdotdot(Address, Address);
	static void cb_lsmenu(Address, Address);
	
	void change(Color c) {lines.set_color(c);}
	void change_style(Line_style ls) {lines.set_style(ls);}
	
	void hide_menu() {color_menu.hide(); menu_button.show(); }
	void hide_lsmenu() {ls_menu.hide(), lsmenu_button.show();}

	void next();
	void quit();
};
