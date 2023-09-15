//
// Created by d-khudyakov on 15.09.23.
//

#include "Vector.h"
#include <iostream>

Vector::Vector() {
    this->arr_ = new int[]{};
    this->size_ = 0;
}

Vector::Vector(int size) : arr_(new int[size]), size_(10){
    for (int i = 0; i < size; ++i) {
        arr_[i] = 0;
    }
    std::cout << "Construct vector" << "\n";
}

int Vector::size() const {
    return size_;
}

Vector::~Vector() {
    delete[] arr_;
}

int &Vector::operator[](int i) {
    return arr_[i];
}
