#pragma once
#include"CircularQueue.h"
using namespace std;

template <typename T> class CircularDeque : public CircularQueue<T> {
public:
  // 파생 클래스는 부모 클래스 생성자를 무조건 호출한다.
  // 또는 멤버 초기화 리스트를 이용하여 오버로드된 부모 클래스 생성자
  // 중에서 하나를 호출할 수 있다.
  CircularDeque<T>(int seed) : CircularQueue<T>(seed) {
    cout << "CircularDeque(T seed) 호출!\n";
  }

  // CircularQueue의 타입이 지정되지 않았기 때문에 모두 this포인터를 사용하여
  // 접근하여야 한다.
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