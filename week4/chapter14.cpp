#include <iostream>

using namespace std;

struct A {
	virtual void pvf() const =0;
};

class B : public A {
public:
	virtual void f() const {cout << "B::f" << '\n'; print_message(8.5);}
	void g() const {cout << "B::g" << '\n';}
	void print_message(int a) const
		{cout << "Message: " << a << '\n';}
	void pvf() const {cout << "B::pvf" << '\n';}
};

class D : public B {
public:
	void f() const override {cout << "D::f" << '\n'; print_message(8.5);}
	void g() {cout << "D::g" << '\n';}
	void print_message(double a) const
		{cout << "Message: " << a << '\n';}
	void pvf() const {cout << "D::pvf" << '\n';}
};

struct DD : B {
	void f() {cout << "DD::f" << '\n';}
	void g() const {cout << "DD::g" << '\n';}
	void pvf() const {cout << "DD::pvf" << '\n';}
};

void call(const B& b){
	b.f();
	b.g();
	b.pvf();
}


int main(){
	//A a; absztrakt
	B b;
	D d;
	DD dd;
	call(b);
	call(d);
	call(dd);
	
	cout << "Call end" << '\n';
	
	b.f();
	b.g();
	b.pvf();
	d.f();
	d.g();
	d.pvf();
	dd.f();
	dd.g();
	dd.pvf();
return 0;
}
