#pragma once

#include <cstddef>
#include "stack.h"


namespace stack {

const unsigned int INT_BIT = 8 * sizeof(int);

template <>
class Stack_t <bool>{

public:

    Stack_t() : size_{0}, capacity_{INT_BIT} {arr_ = new int[1];};
    Stack_t(const Stack_t &);
    Stack_t(Stack_t &&);

    ~Stack_t();

    void push(const bool);
    bool pop();
    size_t get_size() const;
    size_t get_capacity() const;
    bool is_empty() const;
    bool is_full() const;

    Stack_t operator = (const Stack_t &);
    Stack_t operator = (Stack_t &&);

private:

    size_t size_;
    size_t capacity_ ;
    int *arr_;
};



Stack_t<bool>::Stack_t(const Stack_t & stack2) : size_{stack2.size_}, capacity_{stack2.capacity_}
{
    arr_ = new int [capacity_ / INT_BIT + 1];
    memcpy(arr_, stack2.arr_, (size_ / INT_BIT + 1) * sizeof(int));
}


Stack_t<bool>::Stack_t(Stack_t && stack2) : size_{stack2.size_}, capacity_{stack2.capacity_}, arr_{stack2.arr_}
{
    stack2.arr_ = nullptr;
}

Stack_t<bool>::~Stack_t()
{
    if (capacity_ != 0)
        delete [] arr_;
    
}


void Stack_t<bool>::push(const bool new_elem)
{
    if (capacity_ == 0) {
        arr_ = new int[1];
    }
    else if (size_ == capacity_) {
        int *new_arr = new int[capacity_ / INT_BIT * 2];
        memcpy(new_arr, arr_, (size_ / INT_BIT + 1) * sizeof(int));
        delete [] arr_;
        arr_ = new_arr;
        capacity_ *= 2;
    }

    if (new_elem == 1) {
        arr_[size_ / INT_BIT] = arr_[size_ / INT_BIT] | (1 << (size_ % INT_BIT));
    }
    else {
        arr_[size_ / INT_BIT] = arr_[size_ / INT_BIT] & (~(1 << (size_ % INT_BIT)));
    }
    
    size_++;
}


bool Stack_t<bool>::pop()
{
    if (size_ == 0) {
        return -1;
    }
    if (size_ < capacity_ / 2 && capacity_ / 2 > INT_BIT) {
        int *new_arr = new int[capacity_ / INT_BIT / 2];
        memcpy(new_arr, arr_, (size_ / INT_BIT + 1) * sizeof(int));
        delete [] arr_;
        arr_ = new_arr;
        capacity_ /=  2;
    }


    size_--;
    return (arr_[size_ / INT_BIT] >> (size_ % INT_BIT)) & 1;
}


size_t Stack_t<bool>::get_size() const{
    return size_;
}

size_t Stack_t<bool>::get_capacity() const
{
    return capacity_;
}


bool Stack_t<bool>::is_empty() const
{
    return size_ == 0;
}


bool Stack_t<bool>::is_full() const
{
    return size_ == capacity_;
}


Stack_t<bool> Stack_t<bool>::operator = (const Stack_t &stack2)
{
    if (capacity_ != 0)
        delete [] arr_;
    
    arr_ = new int[stack2.capacity_ / INT_BIT];
    memcpy(arr_, stack2.arr_, (stack2.size_ / INT_BIT + 1) * sizeof(int));
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}


Stack_t<bool> Stack_t<bool>::operator = (Stack_t &&stack2)
{
    if (capacity_ != 0)
        delete [] arr_;
    
    arr_ = stack2.arr_;
    stack2.arr_ = nullptr;
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

};  //  namesapce stack