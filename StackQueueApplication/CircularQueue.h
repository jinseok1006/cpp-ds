#pragma once
#include<iostream>
using namespace std;

template <typename T> class CircularQueue {
protected:
  static const int MAX_QUEUE_SIZE = 30;
  int front;
  int rear;
  T data[MAX_QUEUE_SIZE];

public:
  CircularQueue(T seed) {
    cout << "CircularQueue(T seed) 호출\n";
    front = 0;
    rear = 0;

    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
      data[i] = seed;
    }
  }

  bool empty() { return front == rear; }

  bool full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

  // 리어에서 넣기
  void enqueue(T e) {
    if (full())
      throw runtime_error("queue is full");
    else {
      rear = (rear + 1) % MAX_QUEUE_SIZE;
      data[rear] = e;
    }
  }

  // 프론트에서 빼내기
  T dequeue() {
    if (empty())
      throw runtime_error("queue is empty");
    else {
      front = (front + 1) % MAX_QUEUE_SIZE;
      return data[front];
    }
  }

  T peek() {
    if (empty())
      throw runtime_error("queue is empty");
    else
      return data[(front + 1) % MAX_QUEUE_SIZE];
  }

  int size() { return (rear + MAX_QUEUE_SIZE - front) % MAX_QUEUE_SIZE; }

  void display() {
    int maxIndex = rear >= front ? rear : rear + MAX_QUEUE_SIZE;
    for (int i = front + 1; i <= maxIndex; i++) {
      cout << data[i % MAX_QUEUE_SIZE] << ' ';
    }
    cout << '\n';
  }
};
