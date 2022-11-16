#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string.h>

namespace stack {

template <typename Type>
class Stack_t {
public:
    Stack_t() : size_ {0}, capacity_ {BASE_CAPACITY}
    {
        arr_ = new Type[BASE_CAPACITY];
    };

    Stack_t(const Stack_t &);
    Stack_t(const Stack_t &&);

    ~Stack_t();

    void resize(const size_t);
    void push(const Type &);
    Type pop();
    Type top();
    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;
    bool is_empty() const;
    bool is_full() const;

    Stack_t operator=(const Stack_t &);
    Stack_t operator=(Stack_t &&);

private:
    const size_t BASE_CAPACITY = 10;

    size_t size_;
    size_t capacity_;
    Type *arr_;
};

/**
 * specilization of stack to type bool with 
 * changed methods
 */
template <>
class Stack_t<bool> {
public:
    Stack_t() : size_ {0}, capacity_ {INT_BIT}
    {
        arr_ = new int[BASE_CAPACITY];
    };
    Stack_t(const Stack_t &);
    Stack_t(Stack_t &&);

    ~Stack_t();

    void resize(const size_t);
    void push(const bool);
    bool pop();
    bool top();
    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;
    bool is_empty() const;
    bool is_full() const;

    Stack_t operator=(const Stack_t &);
    Stack_t operator=(Stack_t &&);

private:
    const size_t BASE_CAPACITY = 1;
    const size_t INT_BIT = 8 * sizeof(int);

    size_t size_;
    size_t capacity_;
    int *arr_;
};


template <typename Type>
Stack_t<Type>::Stack_t(const Stack_t &stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}
{
    arr_ = new Type[capacity_];
    std::copy(stack2.arr_, stack2.arr_ + stack2.size_, arr_);
}

template <typename Type>
Stack_t<Type>::Stack_t(const Stack_t &&stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}, arr_ {stack2.arr_}
{
    stack2.arr_ = nullptr;
}

template <typename Type>
Stack_t<Type>::~Stack_t()
{
    delete[] arr_;
}

template <typename Type>
void Stack_t<Type>::resize(const size_t new_capacity)
{
    Type *new_arr = new Type[new_capacity];
    std::copy(arr_, arr_ + std::min(size_, new_capacity), new_arr);
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = new_capacity;
}

template <typename Type>
void Stack_t<Type>::push(const Type &new_elem)
{
    if (size_ == capacity_)
        resize(capacity_ * 2);

    arr_[size_] = new_elem;
    size_++;
}

template <typename Type>
Type Stack_t<Type>::pop()
{
    if (size_ * 2 < capacity_ && capacity_ > BASE_CAPACITY)
        resize(capacity_ / 2);

    size_--;
    return arr_[size_];
}

template <typename Type>
Type Stack_t<Type>::top()
{
    return arr_[size_ - 1];
}

template <typename Type>
size_t Stack_t<Type>::get_size() const noexcept
{
    return size_;
}

template <typename Type>
size_t Stack_t<Type>::get_capacity() const noexcept
{
    return capacity_;
}

template <typename Type>
bool Stack_t<Type>::is_empty() const
{
    return size_ == 0;
}

template <typename Type>
bool Stack_t<Type>::is_full() const
{
    return size_ == capacity_;
}

template <typename Type>
Stack_t<Type> Stack_t<Type>::operator=(const Stack_t &stack2)
{
    if (&stack2 == this)
        return *this;

    delete[] arr_;

    arr_ = new Type[stack2.capacity_];
    std::copy(stack2.arr_, stack2.arr_ + stack2.size_, arr_);
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

template <typename Type>
Stack_t<Type> Stack_t<Type>::operator=(Stack_t &&stack2)
{
    delete[] arr_;

    arr_ = stack2.arr_;
    stack2.arr_ = nullptr;
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}


Stack_t<bool>::Stack_t(const Stack_t &stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}
{
    arr_ = new int[capacity_ / INT_BIT + 1];
    std::copy(stack2.arr_, stack2.arr_ + (size_ / INT_BIT + ((stack2.size_ % INT_BIT) != 0)), arr_);
}

Stack_t<bool>::Stack_t(Stack_t &&stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}, arr_ {stack2.arr_}
{
    stack2.arr_ = nullptr;
}

Stack_t<bool>::~Stack_t()
{
    delete[] arr_;
}

void Stack_t<bool>::resize(const size_t new_capacity)
{
    int *new_arr = new int[new_capacity / INT_BIT];
    std::copy(arr_, arr_ + (std::min(size_, new_capacity) / INT_BIT + ((size_ % INT_BIT) != 0)), new_arr);
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = new_capacity;
}

void Stack_t<bool>::push(const bool new_elem)
{
    
    if (size_ == capacity_) 
        resize(capacity_ * 2);

    if (new_elem == 1) {
        arr_[size_ / INT_BIT] = arr_[size_ / INT_BIT] | (1 << (size_ % INT_BIT));
    } else {
        arr_[size_ / INT_BIT] = arr_[size_ / INT_BIT] & (~(1 << (size_ % INT_BIT)));
    }

    size_++;
}

bool Stack_t<bool>::pop()
{
    if (size_ == 0) {
        return -1;
    }
    if (size_ < capacity_ / 2 && capacity_ / 2 > INT_BIT)
        resize(capacity_ / 2);

    size_--;
    return (arr_[size_ / INT_BIT] >> (size_ % INT_BIT)) & 1;
}

bool Stack_t<bool>::top()
{
    if (size_ == 0)
        return -1;

    return (arr_[(size_ + 1) / INT_BIT] >> ((size_ + 1) % INT_BIT)) & 1;
}

size_t Stack_t<bool>::get_size() const noexcept
{
    return size_;
}

size_t Stack_t<bool>::get_capacity() const noexcept
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

Stack_t<bool> Stack_t<bool>::operator=(const Stack_t &stack2)
{
    delete[] arr_;

    arr_ = new int[stack2.capacity_ / INT_BIT];
    std::copy(stack2.arr_, stack2.arr_ + (stack2.size_ / INT_BIT + ((stack2.size_ % INT_BIT) != 0)), arr_);
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

Stack_t<bool> Stack_t<bool>::operator=(Stack_t &&stack2)
{

    delete[] arr_;

    arr_ = stack2.arr_;
    stack2.arr_ = nullptr;
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

};  //  namespace stack