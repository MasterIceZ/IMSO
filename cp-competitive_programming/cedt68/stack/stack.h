#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <vector>
//#pragma once

namespace CP { 

template <typename T>
class stack
{
  protected:
    // Addition stack
    std::vector<std::vector<T>> mData;
    size_t mSize;

  public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
        this->mData = a.mData;
        this->mSize = a.size();
    }

    // default constructor
    stack() {
        mSize = 0;
    }

    ~stack() {
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const;

    //----------------- modifier -------------
    void push(const T& element);
    void pop();
    
    //----------------- access -----------------
    const T& top() const;

    //----------------- util -----------------
    void print_value(){
      for(int i = 0; i<mData.size() ; i++){
          std::cout<<i+1<<' ';
          for(auto &x: mData[i]){
              std::cout<<x<<' ';
          }
          std::cout<<'\n';
      }
    }
};

}

#endif


