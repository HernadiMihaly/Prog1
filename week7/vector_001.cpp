#include "../lib_files/std_lib_facilities.h"

class My_out_of_range{};
	
class My_vector {
	int sz, space;
	double* elem;
public:
	explicit My_vector(int s): sz(s), elem(new double[s]),space(s) {
		for (int i=0; i<s; ++i) {
		elem[i]=0;
		}
	}
	int size() const {return sz;}
	
	int get(int i) const {return elem[i];}
	void set(int i, double val) {elem[i]=val;}
	
	My_vector(initializer_list<double> lst): sz(lst.size()), elem(new double[sz]),space(lst.size()){
		copy(lst.begin(), lst.end(), elem);
	}
	
	My_vector(const My_vector& arg): 			//másoló konstruktor
		sz(arg.size()), elem(new double[sz]),space(sz){
			copy(arg.elem, arg.elem+arg.sz, elem);
		}
		
	My_vector& operator=(const My_vector& arg) { 			//copy assignment, másoló értékadás
	if(this == &arg) return *this; //v=v; self assignment
	if (arg.sz <= space){
		for (int i=0; i<arg.sz; ++i)
			elem[i]= arg.elem[i];
		sz = arg.sz;
		return *this;
	}
		double* p= new double[arg.size()];
		copy(arg.elem, arg.elem+arg.size(), p);
		delete[] elem;
		elem= p;
		sz= arg.size();
		return *this;					//this: egy pointer ami a példányra mutat
	}
	
	My_vector(My_vector&& arg): sz(arg.sz), elem(arg.elem), space(arg.sz)		//mozgató konstruktor
	{arg.sz= 0; arg.elem= nullptr;}
	
	My_vector& operator=(My_vector&& arg){		//mozgató értékadás, move assignment
		delete[] elem;
		space= arg.space;
		sz= arg.sz;
		elem= arg.elem;
		arg.sz= 0;
		arg.elem= nullptr;
		return *this;
	}
	double& operator[](int n) {return elem[n];}
	const double& operator[](int n) const {return elem[n];}
	
	double& at(int n){
		if (n<0 || n>= sz) throw My_out_of_range();
		return elem[n];
	}
	
	const double& at(int n) const{
		if (n<0 || n>= sz) throw My_out_of_range();
		return elem[n];
	}
	
	void reserve(int newalloc){
		if (newalloc <= space) return;
		double* p= new double[newalloc];
		for (int i=0; i<sz; ++i) p[i] = elem[i];
		delete[] elem;
		elem= p;
		space= newalloc;
	}
	
	void resize(int newsize){
		double* p= new double[newsize];
		for (int i=sz; i<newsize; ++i) elem[i] = 0;
		sz=newsize;
	}
	
	void push_back(double d){
		if(space==0)
			reserve(8);
		else if (sz==space)
			reserve(2*space);
		elem[sz] = d;
		++sz;
	}
	int capacity() const {return space;}
	
	~My_vector() {delete[] elem;}
	};
	
My_vector fill(){
	My_vector t { 10, 12 , 111, 1};
	return t;
}

int main(){
/* //még a [] operátor előtt használtam ezt
My_vector mv(10);
cout << "vector size= " << mv.size() << endl;
for (int i=0; i<mv.size(); ++i) {
		mv.set(i,i);
		}
for (int i=0; i<mv.size(); ++i) {
		cout << mv.get(i) << '\n';
		}
		
My_vector mv2 = mv;
	for (int i=0; i<mv2.size(); ++i) {
		cout << "mv2= " << mv2.get(i) << '\n';
		}

My_vector mv3 {0,1,2,3};
	for (int i=0; i<mv3.size(); ++i) {
		cout << "mv3= " << mv3.get(i) << '\n';
		}
		
My_vector mv1 {1,2,3,4};
		for (int i=0; i<mv1.size(); ++i) {
		cout << "Mv1= " << mv1.get(i) << '\n';
		}
		
mv3= mv1;
	for (int i=0; i<mv3.size(); ++i) {
		cout << "mv3.2= " << mv3.get(i) << '\n';
		}
	

My_vector mf = fill ();
for (int i=0; i<mf.size(); ++i) {
		cout << "mf= " << mf.get(i) << '\n';
		}

My_vector mf2 {10,15, 14, 11};
mf2= fill();
for (int i=0; i<mf2.size(); ++i) {
		cout << "mf2= " << mf2.get(i) << '\n';
		}
*/
My_vector m {10,1};
My_vector m2= m;

for (int i=0; i<m2.size(); ++i){
	cout << "m2 " << i << "-edik eleme: " << m2[i] << endl;
}
m2.push_back(8.5);
for (int i=0; i<m2.size(); ++i){
	cout << "new m2 " << i << "-edik eleme: " << m2[i] << endl;
}
}
