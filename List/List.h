 /*
- a list is composed of double linked nodes
- contains a pointer to head and a pointer to tail
- it starts as single node, and grows
- when you add an elem a new Node is created
- xxx iterate should allow to through data to data
- XXX CONST methods??
- reverse iterators
- stl iterators

Node;
- the user does not need to see this
- no such thing as empty node
*/

#include <iostream>

#ifndef LIST_H
#define LIST_H


//XXX make stl iterator
template <class N> class NodeIterator {
    public:
        NodeIterator(){ itr = nullptr; }

        NodeIterator(N* rhs){ itr = rhs; }

        const bool operator==(NodeIterator<N>& rhs){
            return compare(rhs);
        }

        const bool operator!=(NodeIterator<N>& rhs){
            return !compare(rhs);
        }       

        N& operator*(){ return this->content(); }

        NodeIterator& operator++(){ 
            if (this->next == nullptr)
                return nullptr;
            return this->next.iterator(); 
        }

        NodeIterator& operator--(){ 
            if (this->prev == nullptr)
                return nullptr;
            return this->prev.iterator();  
        }

    private:
        N* itr;

        const bool compare(NodeIterator<N>& rhs);
};

template <class T> class Node{
    public:
        Node<T>* next;
        Node<T>* prev;
        //size_type?
        typedef NodeIterator iterator;
        typedef T value_type;
        
        //typedef const T* const_iterator;

        Node(const T& data, Node<T>* p_prev, Node<T>* p_next) { 
            create(data, p_prev, p_next); 
        }

        ~Node(){ uncreate(); }

        /*
        Node& next() { return next; }

        const Node& next() const { return next; }

        Node& prev() { return prev; }

        const Node& prev() const { return prev; }
        */

        //assignment
        //copy control
        //iterator ops

        //XXX everything as valuetype?
        T* content();

        const T* content() const;

        //XXX move outside
        iterator iterator(){ return new NodeIterator<Node>&(this); }

        /*
        iterator operator++(){
            if (next != nullptr)
                return next->content();
            return nullptr;
        }

        iterator operator--(){
            if (prev != nullptr)
                return prev->content();
            return nullptr;
        }

        //const T* operator*() const { return this->content(); }

        T* operator*(){
            return this->content();
        }

        bool operator!=(iterator rhs){
            //std::cout << "compare" << std::endl;
            return !compare(rhs);
        }

        bool operator==(iterator rhs){
            //std::cout << "compare" << std::endl;
            return compare(rhs);
        }
        */

    private:
        T data;
        //constructors node
        void create(const T& val, Node<T>* p_prev, Node<T>* p_next);

        //XXX is it even needed?
        //bool compare(Node<T>& rhs);

        void uncreate();
};

template <class T> class List{
    public:
        //XXX could alias
        typedef typename Node<T>::iterator iterator;
        //XXX const_iterator
        //typedef const typename Node<T>::iterator const_iterator;
        typedef T value_type;
        typedef size_t size_type;

        List() { create(); }

        //XXX at most list starts with one val
        explicit List(T& elem) { create(elem); }

        size_type size() { return int_size; }

        T& operator[](size_type i) { return *elementAt(i); }

        //XXX does this requires a different elementAt?
        //const T& operator[]( size_t i) const { return elementAt(i); }

        iterator begin() { 
            if (first == nullptr)
                return nullptr;
            return first->iterator(); 
        }

        iterator end() { 
            return nullptr;
        }

        /*
        const_iterator begin() const { 
            if (first == nullptr)
                return nullptr;
            return first->content(); 
        }

        const_iterator end() const { 
            return nullptr;
        }*/

        //assignment
        /*T& operator=(const List<T>& rhs){
            if ( rhs != this ){
                uncreate();
            }
            //XXX a constructor for a list is needed...
            create(rhs);
        }*/

        void push_back(T& elem) {
            insert_at(elem, int_size);
        }


        ~List() { uncreate(); }

    private:
        size_t int_size;
        Node<T>* first;
        Node<T>* last;

        void create();

        void create(T& elem);

        void uncreate();

        /*
         * elementAt: Helper method, returns element at position i
         *
         */
        T* elementAt(size_type i);

        //XXX
        //const T& elementAt(size_t i);

        /*
         * Insert_at: Helper method, inserts element new_val in position pos
         * 
         * Returns True if everything went fine, False otherwise
         */
        bool insert_at(T& new_val, size_type pos); 


        //XXX copy and move control
};


#endif