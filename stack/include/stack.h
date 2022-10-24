#include <cstring>
#include <cstddef>
#include <iostream>
#include <string.h>

namespace stack {

template <typename Type>
class Stack_t {
public:
    Stack_t() : size_ {0}, capacity_ {10}
    {
        arr_ = new Type[10];
    };
    Stack_t(const Stack_t &);
    Stack_t(const Stack_t &&);

    ~Stack_t();

    void push(const Type &);
    Type pop();
    size_t get_size() const;
    size_t get_capacity() const;
    bool is_empty() const;
    bool is_full() const;

    Stack_t operator=(const Stack_t &);
    Stack_t operator=(Stack_t &&);

private:
    size_t size_;
    size_t capacity_;
    Type *arr_;
};

template <typename Type>
Stack_t<Type>::Stack_t(const Stack_t &stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}
{
    arr_ = new Type[capacity_];
    std::memcpy(arr_, stack2.arr_, stack2.size_ * sizeof(Type));
}

template <typename Type>
Stack_t<Type>::Stack_t(const Stack_t &&stack2) : size_ {stack2.size_}, capacity_ {stack2.capacity_}, arr_ {stack2.arr_}
{
    stack2.arr_ = nullptr;
}

template <typename Type>
Stack_t<Type>::~Stack_t()
{
    if (capacity_ != 0)
        delete[] arr_;
}

template <typename Type>
void Stack_t<Type>::push(const Type &new_elem)
{
    if (capacity_ == 0) {
        arr_ = new Type[10];
    } else if (size_ == capacity_) {
        Type *new_arr = new Type[capacity_ * 2];
        std::memcpy(new_arr, arr_, size_ * sizeof(Type));
        delete[] arr_;
        arr_ = new_arr;
        capacity_ *= 2;
    }

    arr_[size_] = new_elem;
    size_++;
}

template <typename Type>
Type Stack_t<Type>::pop()
{
    if (size_ == 0) {
        return -1;
    }
    if (size_ < (capacity_ / 2) && (capacity_ / 2) > 5) {
        Type *new_arr = new Type[capacity_ / 2];
        std::memcpy(new_arr, arr_, size_ * sizeof(Type));
        delete[] arr_;
        arr_ = new_arr;
        capacity_ /= 2;
    }

    size_--;
    return arr_[size_];
}

template <typename Type>
size_t Stack_t<Type>::get_size() const
{
    return size_;
}

template <typename Type>
size_t Stack_t<Type>::get_capacity() const
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
    if (capacity_ != 0)
        delete[] arr_;

    arr_ = new Type[stack2.capacity_];
    std::memcpy(arr_, stack2.arr_, stack2.size_ * sizeof(Type));
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

template <typename Type>
Stack_t<Type> Stack_t<Type>::operator=(Stack_t &&stack2)
{
    if (capacity_ != 0)
        delete[] arr_;

    arr_ = stack2.arr_;
    stack2.arr_ = nullptr;
    size_ = stack2.size_;
    capacity_ = stack2.capacity_;

    return *this;
}

};  //  namespace stack