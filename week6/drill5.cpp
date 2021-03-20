#include "../lib_files/Lines_window.h"
#include "../lib_files/Graph.h"

int main()
{
using namespace Graph_lib;

Lines_window win{Point{100,100}, 1000, 800, "Vector_ref"};

return gui_main();
}
