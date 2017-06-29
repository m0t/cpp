#include "List.h"
#include <stdexcept>

//NODE METHODS

//constructors node
template <class T> void Node<T>::create(const T& val, Node<T>* p_prev, Node<T>* p_next) {
    data = val;
    next = p_next;
    prev = p_prev;
}

template <class T> void Node<T>::uncreate(){
    delete &data;
}

template <class T> T* Node<T>::content() { 
    return &data; 
}

template <class T> const T* Node<T>::content() const {
    return &data;
}

/*
template <class T> bool Node<T>::compare(Node<T>& rhs){
    if (this == &rhs )
        return true;
    else
        return false;
}
*/

//ITERATOR METHODS
template <class T> bool NodeIterator<T>::compare(NodeIterator<T>& rhs){
    if (this == &rhs)
        return true;
    else
        return false;
}

//LIST METHODS
template <class T> void List<T>::create(){
    first = last = nullptr;
    int_size = 0;
}

template <class T> void List<T>::create(T& elem){
    first = new Node<T>(elem, nullptr, last);
    last = first;
    int_size = 1;
}

template <class T> void List<T>::uncreate(){
    Node<T>* iter = first;
    while (iter != last){
        delete iter;
        iter++;
    }
}

template <class T> T* List<T>::elementAt(size_type i){
    auto counter = 0;
    if (i > int_size){
        throw std::out_of_range("Insert Out of Range");
    }
    List<T>::iterator iter = this->begin();
    while ( counter < i){
        iter++;
        counter++;
    }
    return iter;
}

//return false if bad insert
//XXX rewrite with actual iterator? 
template <class T> bool List<T>::insert_at(T& new_val, List<T>::size_type pos) {
    if (pos > int_size){
        throw std::out_of_range("Insert Out of Range");
    }
    auto counter = 0;
    if (first != nullptr){
        Node<T>* tmp = first;
        while (counter < int_size){
            counter++;
            tmp = tmp->next;
        }
        Node<T>* new_node = new Node<T>(new_val, tmp->prev, tmp);
        tmp->prev = new_node;
        int_size++;
        return true;
    }
    else {
        first = last = new Node<T>(new_val, NULL, NULL);
        int_size++;
    }
}

template class Node<int>;
template class Node<std::string>;
template class List<int>;
template class List<std::string>;
