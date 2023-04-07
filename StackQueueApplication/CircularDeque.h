#pragma once
#include"CircularQueue.h"
using namespace std;

template <typename T> class CircularDeque : public CircularQueue<T> {
public:
  // �Ļ� Ŭ������ �θ� Ŭ���� �����ڸ� ������ ȣ���Ѵ�.
  // �Ǵ� ��� �ʱ�ȭ ����Ʈ�� �̿��Ͽ� �����ε�� �θ� Ŭ���� ������
  // �߿��� �ϳ��� ȣ���� �� �ִ�.
  CircularDeque<T>(int seed) : CircularQueue<T>(seed) {
    cout << "CircularDeque(T seed) ȣ��!\n";
  }

  // CircularQueue�� Ÿ���� �������� �ʾұ� ������ ��� this�����͸� ����Ͽ�
  // �����Ͽ��� �Ѵ�.
  void addRear(T e) { this->enqueue(e); }

  T deleteFront() { return this->dequeue(); }

  void addFront(T e) {
    if (this->full())
      throw runtime_error("deque is full");
    else {
      this->data[this->front] = e;
      this->front =
          (this->front + this->MAX_QUEUE_SIZE - 1) % this->MAX_QUEUE_SIZE;
    }
  }

  T deleteRear() {
    if (this->empty())
      throw runtime_error("deque is empty");
    else {
      T temp = this->data[this->rear];
      this->rear =
          (this->rear - 1 + this->MAX_QUEUE_SIZE) % this->MAX_QUEUE_SIZE;
      return temp;
    }
  }

  T getFront() { return this->peek(); }

  T getRear() {
    if (this->empty())
      throw runtime_error("deque is empty");
    else {
      return this->data[this->rear];
    }
  }
};