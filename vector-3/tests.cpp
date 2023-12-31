//
// Created by d-khudyakov on 15.09.23.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Vector.h"

int fooTest(Vector vector) {
    std::cout << vector[5] << "\n";
    return vector[5];
}

Vector sum(const Vector &v1, const Vector &v2, const Vector &v3) {
    return v1 + v2 + v3;
}

Vector foo() {
    return Vector(10);
}

TEST(vector_test, vector_creation) {
    Vector v = Vector(10);
    int size = v.size();
    ASSERT_EQ(size, 10);
}

TEST(vector_test, copy_construct) {
    Vector v1 = Vector(10);
    Vector v2 = v1;

    ASSERT_EQ(v1.size(), v2.size());
    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i], v2[i]);
    }
}

TEST(vector_test, copy_construct_in_func) {
    Vector v1 = Vector(10);
    v1[5] = 5;
    int res = fooTest(Vector(10));
    ASSERT_EQ(res, v1[5]);
}


TEST(vector_test, copy_operator) {
    Vector v1 = Vector(10);
    v1[5] = 5;

    Vector v2 = Vector(20);
    v2 = v1;
    //v2 = std::move(v1);

    ASSERT_EQ(v1.size(), v2.size());
    for (int i = 0; i < v1.size(); ++i) {
        ASSERT_EQ(v1[i], v2[i]);
    }
}


TEST(vector_test, move_operator) {
    Vector v = Vector(10);
    v = foo();

    std::cout << "test";
}


TEST(vector_test, move_constructor) {
    Vector v1 = Vector(2);
    v1[0] = 1;
    v1[1] = 2;

    Vector v2 = Vector(2);
    v2[0] = 3;
    v2[1] = 4;

    Vector v3 = Vector(2);
    v3[0] = 5;
    v3[1] = 6;

    Vector v;
    v = sum(v1, v2, v3);

    ASSERT_EQ(v[0], 9);
    ASSERT_EQ(v[1], 12);
}

//fixture
namespace {
    class VectorTest : public testing::Test {
    public:
        Vector *vector{};
    protected:
        void SetUp() override {
            vector = new Vector(10);
        }

        void TearDown() override {
            delete vector;
        }
    };
}

TEST_F(VectorTest, fixture_example) {
    std::cout << vector;
}

/*class Arg {
    int a;
    int b;
};*/

class VectorPTest : public ::testing::TestWithParam<Vector> {

};

INSTANTIATE_TEST_SUITE_P(vector_p_test, VectorPTest, ::testing::Values(
        Vector(10),
        Vector(),
        Vector(500)
));

TEST_P(VectorPTest, vector_p_test) {
    Vector v = GetParam();
    ASSERT_TRUE(v.size() > 100);
}

