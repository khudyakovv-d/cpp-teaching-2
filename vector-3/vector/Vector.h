//
// Created by d-khudyakov on 15.09.23.
//

#ifndef VECTOR_2_VECTOR_H
#define VECTOR_2_VECTOR_H

#include <iostream>

class Vector {
private:
    int * arr_;
    int size_;
public:
    Vector();
    Vector(int size);
    Vector(const Vector &vec) ;
    Vector(Vector &&vec) noexcept;
    ~Vector();
    int size() const;
    int &operator[](int i);
    int const &operator[](int i) const;
    Vector &operator=(const Vector &vec);
    Vector &operator=(Vector &&vec);
};

Vector operator+(const Vector &vec1, const Vector &vec2);

#endif //VECTOR_2_VECTOR_H
