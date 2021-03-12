#ifndef FRAKABLAK_H
#define FRAKABLAK_H
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include "frakszal.h"

class FrakSzal;

class FrakAblak : public QMainWindow
{
	Q_OBJECT
public:

	FrakAblak(double a = -2.0, double b = 0.7, double c = -1.35,
              double d = 1.35, int szelesseg = 600,
              int iteraciosHatar = 255, QWidget *parent = 0 );
	~FrakAblak();
	
	void vissza(int magassag, int* sor, int meret);
	void vissza(void);
	double a,b,c,d; //a vizsgálat tartománya
	int szelesseg, magassag; //hálószélesség és magasság
	int iteraciosHatar; //vizsgalat maximum hatara
	
protected: 
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
private:
    QImage* fraktal;
    FrakSzal* mandelbrot;
    bool szamitasFut;
    // A nagyítandó kijelölt terület bal felsõ sarka.
    int x, y;
    // A nagyítandó kijelölt terület szélessége és magassága.
    int mx, my;

};

#endif
