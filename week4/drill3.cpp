#include "../lib_files/std_lib_facilities.h"

class B1 {

public:
	virtual void vf(){ cout << "B1::vf()" << '\n';}
	void f(){cout << "B1::f()" << '\n';}
	virtual void pvf() =0;
};

class D1 : public B1 {

public:

	void vf() {cout << "D1::vf()" << '\n';}
	void f() {cout << "D1::f()" << '\n';};
};

class D2 : public D1 {
public:
    void pvf() override { cout << "D2::pvf()" << endl; }
};

class B2 {
public:

	virtual void pvf()=0;

};

class D21 : public B2 {
public:
string s;
void pvf() override {cout << "a string: " <<s << '\n';}
void input() {
cout << "adj meg egy stringet:" << '\n';
getline(cin,s);}
};

class D22 : public B2 {
public:
void pvf() override {cout <<"a szam: " << a << '\n';}
void ip() {
cout << "adj meg egy egesz szamot: " << '\n';
cin>>a;
}
int a;

};

void f(B2& b2){
b2.pvf();
}

int main() 
{
/*D1 dr;
dr.vf();
dr.f();

B1& ref= dr;
ref.vf();
ref.f();
*/

D2 d2;
d2.f();
d2.vf();
d2.pvf();

D21 d21;
d21.input();
d21.pvf();

D22 d22;
d22.ip();
d22.pvf();

cout << "Megegyszer kiirva: " << '\n';
f(d21);
f(d22);
}
