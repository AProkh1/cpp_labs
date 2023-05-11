//
//  RingBuffer.h
//  lab7
//
//  Created by Антон Прохоров on 11/05/2023.
//

#ifndef RingBuffer_h
#define RingBuffer_h

#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
class RingBuffer {
private:
    T* buffer_;
    int capacity_;
    int size_;
    int start_;
    
public:
    class Iterator {
    private:
        RingBuffer* buffer_;
        int index_;
        
    public:
        Iterator(RingBuffer* buffer, int index)
        : buffer_(buffer), index_(index) {}
        
        Iterator operator++() {
            index_++;
            if (index_ >= buffer_->size()) {
                index_ = 0;
            }
            return *this;
        }
        
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        
        bool operator==(const Iterator& other) const {
            return index_ == other.index_;
        }
        
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
        
        T& operator*() const {
            return buffer_->at(index_);
        }
    };
    
    RingBuffer(int capacity)
    : buffer_(new T[capacity]), capacity_(capacity), size_(0), start_(0) {}
    
    ~RingBuffer() {
        delete[] buffer_;
    }
    
    RingBuffer(const RingBuffer& other)
    : buffer_(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_), start_(other.start_) {
        std::copy(other.begin(), other.end(), begin());
    }
    
    RingBuffer& operator=(const RingBuffer& other) {
        if (this != &other) {
            delete[] buffer_;
            buffer_ = new T[other.capacity_];
            capacity_ = other.capacity_;
            size_ = other.size_;
            start_ = other.start_;
            std::copy(other.begin(), other.end(), begin());
        }
        return *this;
    }
    
    int size() const {
        return size_;
    }
    
    int capacity() const {
        return capacity_;
    }
    
    bool empty() const {
        return size_ == 0;
    }
    
    bool full() const {
        return size_ == capacity_;
    }
    
    T& at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return buffer_[(start_ + index) % capacity_];
    }
    
    T& front() const {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }
        return buffer_[start_];
    }
    
    T& back() const {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }
        return buffer_[(start_ + size_ - 1) % capacity_];
    }
    
    void push_back(const T& value) {
        if (full()) {
            throw std::out_of_range("Buffer is full");
        }
        buffer_[(start_ + size_) % capacity_] = value;
        size_++;
    }
    
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }
        size_--;
    }
    
    void push_front(const T& value) {
        if (full()) {
            throw std::out_of_range("Buffer is full");
        }
        start_ = (start_ + capacity_ - 1) % capacity_;
        buffer_[start_] = value;
        size_++;
    }
    
    void pop_front() {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }
        start_ = (start_ + 1) % capacity_;
        size_--;
    }
    
    void insert(const Iterator& it, const T& value) {
        if (full()) {
            throw std::out_of_range("Buffer is full");
        }
        int index = it.index_;
        if (index < 0 || index > size_) {
            throw std::out_of_range("Invalid iterator");
        }
        if (index == size_) {
            push_back(value);
            return;
        }
        if (index == 0) {
            push_front(value);
            return;
        }
        for (int i = size_; i > index; i--) {
            buffer_[(start_ + i) % capacity_] = buffer_[(start_ + i - 1) % capacity_];
        }
        buffer_[(start_ + index) % capacity_] = value;
        size_++;
    }
    
    void erase(const Iterator& it) {
        int index = it.index_;
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Invalid iterator");
        }
        for (int i = index; i < size_ - 1; i++) {
            buffer_[(start_ + i) % capacity_] = buffer_[(start_ + i + 1) % capacity_];
        }
        size_--;
    }
    
    Iterator begin() {
        return Iterator(this, 0);
    }
    
    Iterator end() {
        return Iterator(this, size_);
    }
    
    void reserve(int new_capacity) {
        if (new_capacity < size_) {
            throw std::out_of_range("New capacity is too small");
        }
        T* new_buffer = new T[new_capacity];
        for (int i = 0; i < size_; i++) {
            new_buffer[i] = buffer_[(start_ + i) % capacity_];
        }
        delete[] buffer_;
        buffer_ = new_buffer;
        capacity_ = new_capacity;
        start_ = 0;
    }
};

#endif /* RingBuffer_h */
