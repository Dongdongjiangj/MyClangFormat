//
// Created by Dong on 2021/1/31.
//

#ifndef CPPDATASTRUCTURE_VECTOR_H
#define CPPDATASTRUCTURE_VECTOR_H

#include <memory>
#include <iostream>
#include <ranges>
#include <initializer_list>

template <class T>
class Vector
{
private:
    std::unique_ptr<T> ptr_;
    size_t size_ = 0;
    size_t capacity_ = 0;
public:
    explicit Vector(size_t nums = 0)
        : ptr_(new T[nums]), size_(nums), capacity_(nums)
    {}
    ~Vector() = default;

    Vector(std::initializer_list<T> il)
        : ptr_(new T[il.size()]), size_(il.size()), capacity_(il.size())
    {
        std::copy(il.begin(), il.end(), this->begin());
    }

    T * begin() const noexcept {return &*ptr_;}
    T * end() const noexcept {return (&*ptr_) + size_;}
    Vector(size_t nums, T const& value) : Vector(nums)
    {
        std::fill(this->begin(), this->end(), value);
    }
    size_t size() const noexcept {return size_;}
    size_t capacity() const noexcept {return capacity_;}
    void traverse() const noexcept
    {
        if (size_ == 0) return;
        for (auto const& c : *this)
            std::cout << c << " ";
        endl(std::cout);
    }

    size_t unique()
    {
        size_t i = 0, j = 0, old_size = size_;
        while (++j < size_)
            if ((&*ptr_)[i] != (&*ptr_)[j]) (&*ptr_)[++i] = (&*ptr_)[j];
        size_ = ++i;
        return old_size - size_;
    }

    T * binary_search(T const& target)
    {
        size_t left = 0, right = size();
        while (left < right) {
            auto middle = (left + right) >> 1;
            if ((&*ptr_)[middle] == target) return ((&*ptr_) + middle);
            if ((&*ptr_)[middle] < target) left = middle + 1;
            if ((&*ptr_)[middle] > target) right = middle;
        }
        return nullptr;
    }
};

#endif //CPPDATASTRUCTURE_VECTOR_H
