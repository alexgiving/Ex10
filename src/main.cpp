// Copyright 2021 by alexgiving
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
    std::string s1("");
    std::string s2 = infix2postfix(s1);
    std::cout << s2 << "\n";
    s1 = "1 + 3.5 * (2 - 5 / ( 10 + 9) + 4) - 1.5";  // a harder example
    s2 = infix2postfix(s1);
    std::cout << s2;  // the right answer: 1 3.5 2 5 10 9 + / - 4 + * + 1.5 -
    return 0;
}
