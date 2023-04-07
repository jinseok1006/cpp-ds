#pragma once
#include <iostream>
using namespace std;
template <typename T> class ArrayStack {
private:
  static const int STACK_MAX_SIZE = 300;
  T data[STACK_MAX_SIZE] = {};
  int top = -1;

public:
  ArrayStack() { top = -1; }
  ~ArrayStack() {}
  void push(T d) { data[++top] = d; }
  T pop() {
    if (empty())
      throw runtime_error("stack is empty");
    return data[top--];
  }
  bool empty() { return top == -1; }
  T peek() {
    if (empty())
      throw runtime_error("stack is empty");
    return data[top];
  }
  int size() { return top + 1; }
  // only for debug
  void print() {
    cout << "stack: ";
    for (int i = 0; i < size(); i++) {
      cout << data[i] << ' ';
    }
    cout << '\n';
  }
};