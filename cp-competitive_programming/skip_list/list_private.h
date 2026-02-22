#ifndef _CP_LIST_INCLUDED_
#define _CP_LIST_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP { 

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
      private:
        node *prev;
        node *next;
        node *nextnext;
      public:
        node() :
          data( T() ), prev( this ), next( this ), nextnext( nullptr ) { }

        node(const T& data, node* prev, node* next, node* nextnext) :
          data ( T(data) ), prev( prev ), next( next ), nextnext( nextnext ) { }

        node* get_prev() {
          return prev;
        }
        
        void set_prev(node* p) {
          prev = p;
        }

        node* get_next() {
          return next;
        }

        void set_next(node* n) {
          next = n;
        }

        node* get_nextnext() {
          return nextnext;
        }


        void set_next(node* n) {
          next = n;
        }

        node* get_nextnext() {
          return nextnext;
        }

        void set_nextnext(node* nn) {
          nextnext = nn;
        }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() { 
          ptr = ptr->next; 
          return (*this);
        }

        list_iterator& operator--() { 
          ptr = ptr->prev; 
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;
        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node *mHeader; // pointer to a header node
    size_t mSize;

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(const list<T>& a ) :
      mHeader( new node() ), mSize( 0 ) {
      for (auto &x : *this) {
        push_back(x);
      }
    }
  
    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) { }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element);

    iterator erase(iterator it);

    T at(size_t k);

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      std::cout << "Size = " << mSize << std::endl;
      for (iterator it = begin(); it != end(); it++) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
      for (iterator it = begin(); it != end(); it++) {
        std::cout << "cur data: " << *it << " ";
        std::cout << "prev data: "<< it.ptr->prev->data << " ";
        std::cout << "next data: " << it.ptr->next->data << std::endl;
      }
      std::cout << "-----------------" << std::endl;
    }

    void print_with_nextnext() {
      std::cout << "Size = " << mSize << std::endl;
      for (iterator it = begin(); it != end(); it++) {
        std::cout << *it << " ";
      }
      std::cout << std::endl;
      for (iterator it = begin(); it != end(); it++) {
        std::cout << "cur data: " << *it << " ";
        std::cout << "prev data: "<< it.ptr->prev->data << " ";
        std::cout << "next data: " << it.ptr->next->data << " ";
        std::cout << "nextnext data: ";
        if (it.ptr->nextnext == nullptr) {
          std::cout << "nullptr";
        } else {
          std::cout << it.ptr->nextnext->data;
        }
        std::cout << std::endl;
      }
      std::cout << "-----------------" << std::endl;
    }
};

}

#endif