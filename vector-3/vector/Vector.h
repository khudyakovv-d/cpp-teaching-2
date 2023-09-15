//
// Created by d-khudyakov on 15.09.23.
//

#ifndef VECTOR_2_VECTOR_H
#define VECTOR_2_VECTOR_H


class Vector {
private:
    int * arr_;
    int size_;
public:
    Vector();
    Vector(int size);
    int size() const;
    ~Vector();
    int &operator[](int i);
};


#endif //VECTOR_2_VECTOR_H
