#include <string>
#include "testClass.h"

template <class T> T Test<T>::getData(){
	return data;
}

template class Test<int>;
template class Test<std::string>;