//
// Created by d-khudyakov on 15.09.23.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Vector.h"

TEST(vector_test, vector_creation) {
    Vector v = Vector(10);
    int size = v.size();
    ASSERT_EQ(size, 10);
}
