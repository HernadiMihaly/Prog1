#include <QApplication>
#include "frakablak.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    FrakAblak win;
    /*win2(.14388310361318304, .14388310362702217,
       .6523089200729396, .6523089200854384, 600, 38655)*/
    win.show();
    //win2.show();
    
    return a.exec();
}
