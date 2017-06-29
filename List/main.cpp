#include <iostream>
#include <string>
#include "List.h"

int main(){
    List<int> list;
    List<int>::iterator iter;
    std::cout << "List<int> created" << std::endl;
    //List<std::string>* liststr = new List<std::string>;
    int x = 3;
    
    list.push_back(x);
    //std::cout << "elem pushed" << std::endl;
    //liststr->push_back(str);
    //std::cout << "Size is " << list->size() << std::endl;
    auto i = 0;
    for (iter = list.begin(); iter != list.end(); iter++ ){
        std::cout << "element at " << i << " is "<< *iter  << std::endl;
        ++i;
    }

    //delete list;

    List<std::string> list_str;
    std::cout << "List<std::string> created" << std::endl;
    std::string str = std::string("cacca");
    list_str.push_back(str);

    i = 0;
    for (auto x : list_str){
        std::cout << "element at " << i << " is " << *iter << std::endl;
        ++i;
    }

    return EXIT_SUCCESS;
    
}