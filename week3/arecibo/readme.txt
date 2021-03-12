parancsok:

1.qmake -project
2.qmake

3.miután létrejött a .pro project fájl bele helyezzük a következő sorokat:

QT += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

4.make
5. ./arecibo
