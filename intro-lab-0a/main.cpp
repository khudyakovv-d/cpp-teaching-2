#include <iostream>
#include "module1.h"
#include "module2.h"

int main() {
    std::cout <<  "Hello world!" << "\n";

    std::cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";

    using namespace Module1;
    std::cout << getMyName() << "\n"; // (A)
    std::cout << Module2::getMyName() << "\n";

    //using namespace Module2; // (B)
    //std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D)

    return 0;
}
