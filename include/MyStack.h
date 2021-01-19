// Copyright 2021 by alexgiving
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_


template <typename T>
class MyStack {
 private:
    unsigned int stack_size {};
    unsigned int stack_head = 0;
    T *stack_values;

 public:
    // constructors
    explicit MyStack(unsigned int new_size) {
        stack_size = new_size;
        stack_head = 0;
        stack_values = new T[stack_size];
    }
    MyStack(const MyStack& copy) {
        stack_size = copy.stack_size;
        stack_head = copy.stack_head;
        stack_values = new T[stack_size];
        for (unsigned int i = 0; i < stack_head; ++i)
            stack_values[i] = copy.stack_values[i];
    }
    ~MyStack() {
        if (stack_head != 0)
            delete stack_values;
    }

    // functions
    [[nodiscard]] bool isFull() const {
        if (stack_head == stack_size)
            return true;
        else
            return false;
    }
    [[nodiscard]] bool isEmpty() const {
        if (stack_head == 0)
            return true;
        else
            return false;
    }
    T get() const {
        if (stack_head != 0)
            return stack_values[stack_head - 1];
    }
    T pop() {
        if (stack_head != 0)
          stack_head--;
          return stack_values[stack_head];
    }
    void push(T element) {
        if (!isFull())
          stack_values[stack_head] = element;
          stack_head++;
    }
};


// Warning message: -1 -> stack is empty but use function pop
// Warning message: -2 -> stack is full but use function push

#endif  // INCLUDE_MYSTACK_H_
