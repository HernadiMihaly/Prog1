#include "../lib_files/std_lib_facilities.h"
#include <vector>
#include <memory>

vector<int>* sus(){
	unique_ptr<vector<int>> v {new vector<int>};
	
	for(int i; cin >> i;){
		if(i) {v -> push_back(i);}
		else throw exception();
	}
	
	
	return v.release();

}

int main(){

try{
	vector<int>* vec= sus();
	
	for (int i=0; i< vec -> size(); ++i){
	
		cout << vec-> at(i) << '\n';
	}
}
catch (exception &e){
cerr << "Hiba" << '\n';
}
}
