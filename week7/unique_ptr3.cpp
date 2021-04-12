#include "../lib_files/std_lib_facilities.h"
#include <vector>
#include <memory>

vector<int>* suspicious(){
	
	
	for (int i; std:: cin>>i;)
	{
	if(i) v-> push_back(i);
	else throw exception();
	}
	
	return v.release();
}

int main(){
try{
	vector<int>* vi = suspicious();
	
	for(int i=0; i < vi-> size(); ++i)
		cout << vi -> at(i) << endl;
	
	delete vi;
	return 0;
	}
	
	catch(std::exception& e){
	std::cerr << "Error" << endl;
	}

}
