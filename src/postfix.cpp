// Copyright 2021 by alexgiving
#include "MyStack.h"
#include "postfix.h"


int get_priority(char s) {
    switch (s) {
        case '(':
            return 0;
        case ')':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return -1;
    }
}


//  void add_to_postfix(std::string &string, char element) {
//      string = string + element;
//      string = string + ' ';
//  }

std::string add_to_postfix(std::string string, char element) {
  string.push_back(element);
  string.push_back(' ');
  return string;
}

bool is_symbol(char element) {
    return element != '.' && !isdigit(element);
}

std::string infix2postfix(std::string infix) {
    std::string postfix;
    MyStack<char> stack(infix.length());
    for (char i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ')
            continue;

        if (infix[i] == '(') {
            stack.push(infix[i]);
            continue;
        }

        if (infix[i] == ')') {
            while (get_priority(stack.get()) != 0)
              postfix = add_to_postfix(postfix, stack.pop());
            stack.pop();
            continue;
        }

        // If + - * /
        if (get_priority(infix[i]) > 1) {
            if (get_priority(infix[i]) > get_priority(stack.get())
            || stack.isEmpty()) {
                stack.push(infix[i]);
            } else {
                while (get_priority(infix[i]) <= get_priority(stack.get()))
                  postfix = add_to_postfix(postfix, stack.pop());
                stack.push(infix[i]);
            }
            continue;
        }

        if (isdigit(infix[i]) && is_symbol(infix[i + 1]))
          postfix = add_to_postfix(postfix, infix[i]);
        else
            postfix.push_back(infix[i]);
    }
    while (!stack.isEmpty())
      postfix = add_to_postfix(postfix, stack.pop());

    postfix.pop_back();
    return postfix;
}
