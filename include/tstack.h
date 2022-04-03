// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 public:
     T arr[100];
     int top;
     TStack() : top(-1) {}
     bool isEmpty() const {
         return top == -1;
     }
     bool isFull() const {
         return top == size - 1;
     }
     T get() {
         return arr[top];
     }
     void pop() {
         if (top >= 0)
             top--;
     }
     void push(T value) {
         if (top < size - 1)
             arr[++top] = value;
     }
};
#endif  // INCLUDE_TSTACK_H_
