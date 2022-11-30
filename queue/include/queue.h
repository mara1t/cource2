#ifndef QUEUE_H
#define QUEUE_H

#include "../../stack/include/stack.h"
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string.h>

namespace queue {

template <typename Type>
class base_queue {
public:
    base_queue() {};
    virtual ~base_queue() {};

    virtual void insert(const Type &, const size_t);
    virtual void push(const Type &) = 0;
    virtual Type pop() = 0;
    virtual Type top() = 0;
    virtual size_t get_size() const noexcept = 0;
    virtual bool is_empty() const = 0;
};

template <typename Type>
struct node_t {
    Type value;
    node_t *next = nullptr;
};

//  Stack realization on list

template <typename Type>
class queue_t : public base_queue<Type> {
public:
    using list_node = node_t<Type>;

    queue_t() : base_queue<Type> {} {}
    queue_t(const queue_t &);
    queue_t(const queue_t &&);

    ~queue_t()
    {
        delete_nlist(head_);
    }

    void insert(const Type &, const size_t) override;
    void push(const Type &) override;
    Type pop() override;
    Type top() override
    {
        return head_->value;
    }
    size_t get_size() const noexcept override
    {
        return size_;
    }
    void delete_nlist(list_node *);
    bool is_empty() const override
    {
        return size_ == 0;
    }

    queue_t operator=(const queue_t &);
    queue_t operator=(const queue_t &&);

private:
    size_t size_ = 0;
    list_node *head_ = nullptr, *tail_ = nullptr;
};

//  Queue realization on 2 stacks

template <typename Type>
class queue_stck_t : public base_queue<Type> {
public:
    queue_stck_t() : base_queue<Type> {}, stack_push_ {}, stack_pop_ {} {}
    queue_stck_t(const queue_stck_t &queue2)
        : base_queue<Type> {}, size_ {queue2.size_}, stack_push_ {queue2.stack_push_}, stack_pop_ {queue2.stack_pop_}
    {
    }
    queue_stck_t(const queue_stck_t &&queue2)
        : base_queue<Type> {}, size_ {queue2.size_}, stack_push_ {queue2.stack_push_}, stack_pop_ {queue2.stack_pop_}
    {
    }

    ~queue_stck_t() {}

    void insert(const Type &, const size_t) override;
    void push(const Type &) override;
    Type pop() override;
    Type top() override;
    size_t get_size() const noexcept override
    {
        return size_;
    }
    bool is_empty() const override
    {
        return size_ == 0;
    }

    queue_stck_t operator=(const queue_stck_t &);
    queue_stck_t operator=(const queue_stck_t &&);

private:
    size_t size_ = 0;
    stack::Stack_t<Type> stack_push_;
    stack::Stack_t<Type> stack_pop_;
};

//  methods for stack queue

template <typename Type>
void queue_stck_t<Type>::insert(const Type &new_elem, const size_t pos)
{
    queue_stck_t tmp_queue{};
    size_t size = size_;
    for (size_t iter = 0; iter < pos && iter < size; iter++) {
        tmp_queue.push(pop());
    }
    tmp_queue.push(new_elem);
    for (size_t iter = std::min(size, pos); iter < size_; iter++) {
        tmp_queue.push(pop());
    }
    *this = tmp_queue;
}

template <typename Type>
void queue_stck_t<Type>::push(const Type &new_elem)
{
    stack_push_.push(new_elem);
    size_++;
}

template <typename Type>
Type queue_stck_t<Type>::pop()
{
    if (stack_pop_.is_empty()) {
        size_t n_iter = stack_push_.get_size();
        for (size_t push_stck_iter = 0; push_stck_iter < n_iter; push_stck_iter++)
            stack_pop_.push(stack_push_.pop());
    }
    size_--;
    return stack_pop_.pop();
}

template <typename Type>
Type queue_stck_t<Type>::top()
{
    if (stack_pop_.is_empty()) {
        size_t n_iter = stack_push_.get_size();
        for (size_t push_stck_iter = 0; push_stck_iter < n_iter; push_stck_iter++)
            stack_pop_.push(stack_push_.pop());
    }

    return stack_pop_.top();
}

template <typename Type>
queue_stck_t<Type> queue_stck_t<Type>::operator=(const queue_stck_t &queue2)
{
    if (&queue2 == this)
        return *this;

    size_ = queue2.size_;
    stack_push_ = queue2.stack_push_;
    stack_pop_ = queue2.stack_pop_;

    return *this;
}

template <typename Type>
queue_stck_t<Type> queue_stck_t<Type>::operator=(const queue_stck_t &&queue2)
{
    size_ = queue2.size_;
    stack_push_ = queue2.stack_push_;
    stack_pop_ = queue2.stack_pop_;

    return *this;
}

//  methods for list queue

template <typename Type>
queue_t<Type>::queue_t(const queue_t &queue2) : base_queue<Type> {}, size_ {queue2.size_}
{
    list_node *tmp_node2 = queue2.head_;
    list_node *tmp_new_next_node = nullptr, *tmp_new_prev_node = nullptr;
    for (int list_it = 0; list_it < size_; list_it++) {
        if (!list_it) {
            tmp_new_prev_node = new list_node;
            head_ = tmp_new_prev_node;
            head_->value = queue2.head_->value;
            tmp_node2 = queue2.head_->next;
            continue;
        }
        assert(tmp_node2 != nullptr);
        tmp_new_next_node = new list_node;
        tmp_new_next_node->value = tmp_node2->value;
        tmp_node2 = tmp_node2->next;
        tmp_new_prev_node->next = tmp_new_next_node;
        tmp_new_prev_node = tmp_new_prev_node->next;
    }
}

template <typename Type>
queue_t<Type>::queue_t(const queue_t &&queue2)
    : base_queue<Type> {}, size_ {queue2.size_}, head_ {queue2.head_}, tail_ {queue2.tail_}
{
    queue2.head_ = queue2.tail = nullptr;
}

template <typename Type>
void queue_t<Type>::insert(const Type &new_elem, const size_t pos)
{   
    if (pos == size_ - 1)
        push(new_elem);

    node_t<int> *prev_node = head_, *next_node, *new_node = new node_t<int> ;
    
    for (size_t iter = 0; iter < pos; iter++) {
        prev_node = prev_node->next;
    }
    next_node = prev_node->next;
    prev_node->next = new_node;
    new_node->next = next_node;
    size_++;
}

template <typename Type>
void queue_t<Type>::push(const Type &new_elem)
{
    size_++;
    list_node *new_list = new list_node;
    new_list->value = new_elem;
    if (tail_ == nullptr) {
        head_ = new_list;
        tail_ = new_list;
        tail_->next = nullptr;
        return;
    }
    tail_->next = new_list;
    tail_ = tail_->next;
}

template <typename Type>
Type queue_t<Type>::pop()
{
    assert(size_ > 0);
    size_--;
    Type ret_value = head_->value;
    list_node *old_head = head_;
    if (size_ == 0) {
        //delete old_head;
        head_ = tail_ = nullptr;
    }
    else {
        head_ = head_->next;
        old_head->next = nullptr;
        //delete old_head;
    }
    
    delete old_head;
    
    return ret_value;
}

template <typename Type>
void queue_t<Type>::delete_nlist(list_node *head)
{
    list_node *tmp_next_node = head;
    while (tmp_next_node != nullptr) {
        head = tmp_next_node;
        tmp_next_node = head->next;
        delete head;
    }
}

template <typename Type>
queue_t<Type> queue_t<Type>::operator=(const queue_t &queue2)
{
    if (&queue2 == this)
        return *this;

    delete_nlist(head_);
    size_ = queue2.size_;

    list_node *tmp_node2 = *queue2.head_;
    list_node *tmp_new_next_node = nullptr, *tmp_new_prev_node = nullptr;
    for (int list_it = 0; list_it < size_; list_it++) {
        if (!list_it) {
            tmp_new_prev_node = new list_node;
            head_ = tmp_new_prev_node;
            head_->value = queue2.head_->value;
            tmp_node2 = queue2.head_->next;
            continue;
        }
        assert(tmp_node2 != nullptr);
        tmp_new_next_node = new list_node;
        tmp_new_next_node->value = tmp_node2->value;
        tmp_node2 = tmp_node2->next;
        tmp_new_prev_node->next = tmp_new_next_node;
        tmp_new_prev_node = tmp_new_prev_node->next;
    }
    return *this;
}

template <typename Type>
queue_t<Type> queue_t<Type>::operator=(const queue_t &&queue2)
{
    size_ = queue2.size_;
    head_ = queue2.head_;
    tail_ = queue2.tail_;

    queue2.head_ = nullptr;
    queue2.tail_ = nullptr;

    return *this;
}

};  //  namespace queue

#endif