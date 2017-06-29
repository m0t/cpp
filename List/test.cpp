#include <iostream>

class Test {
public:
	typedef Test* iterator;
	bool operator==(iterator rhs){
		std::cout << "compare iterator" << std::endl;
		if (this == rhs)
			return true;
		return false;
	}
	bool operator==(Test& rhs){
		std::cout << "compare" << std::endl;
		if (this == &rhs)
			return true;
		return false;
	}
private:

};

int main (){
	Test x,y;
	Test::iterator i,j;
	if ( i == i){
		std::cout << "i i equal" << std::endl;
	}
	if ( x == y){
		std::cout << "x y equal" << std::endl;
	}
	if ( x == x){
		std::cout << "x x equal" << std::endl;
	}
	return 0;
}