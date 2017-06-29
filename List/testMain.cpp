#include <iostream>
#include <iomanip>
#include "testClass.h"

Test<int>* foo(int val){
	return new Test<int>(val); 
}

Bar* abar(){
	return new Bar;
}

int main(){
	Test<int>* test = foo(4);
	Bar* bar = new Bar;
	delete bar;
	delete test;
	//test->data = 3;
	std::ios state(NULL);
	state.copyfmt(std::cout);
	std::cout << "0x" << std::setbase(16) << test->getData() << std::endl;
	std::cout.copyfmt(state);
}