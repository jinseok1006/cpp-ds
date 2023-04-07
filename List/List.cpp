// List.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <iostream>
using namespace std;

struct Student {
  string name;
  int age;
};

template <typename T> class ArrayList {
private:
  static const int MAX_LIST_SIZE = 100;
  int length;
  T data[MAX_LIST_SIZE] = {
      0,
  };

public:
  ArrayList(T seed) : length(0) {
    for (int i = 0; i < MAX_LIST_SIZE; i++) {
      data[i] = seed;
    }
  }
  // insert, remove, get, find, replace
  // empty, full, size
  void insert(int pos, T item);
  void remove(int pos);
  void insertRear(T item) { data[length++] = item; }
  void removeRear(int pos) { length--; }

  int find(T item) {
    for (int i = 0; i < length; i++) {
      if (data[i] == item)
        return i;
    }
    // 또는 예외처리
    throw std::runtime_error("error: cannot find item");
    // return -1;
  }

  void replace(int pos, T item) {
    if (pos < 0 || pos >= length)
      throw runtime_error("error: out of index");
    data[pos] = item;
  }

  T get(int pos) {
    if (pos >= 0 && pos < length)
      return data[pos];
    else
      throw std::runtime_error("error: out of index");
  }
  bool empty() { return length == 0; }
  bool full() { return length == MAX_LIST_SIZE; }
  int size() { return size; }

  void display() {
    for (int i = 0; i < length; i++) {
      cout << data[i] << ' ';
    }
    cout << endl;
  }
};

// 원하는 위치에 넣기 위해 뒤에값을 전부 한칸씩 밀어버리기
template <typename T> void ArrayList<T>::insert(int pos, T item) {
  if (full())
    throw std::runtime_error("error: list is full");

  // pos가 유효한 범위인지 검증
  if (pos < 0 || pos > length)
    throw std::runtime_error("error: out of index");

  for (int i = length; i > pos; i--) {
    data[i] = data[i - 1];
  }
  data[pos] = item;
  length++;
}

// 원하는 위치로 전부다 땡겨옴..
template <typename T> void ArrayList<T>::remove(int pos) {
  if (empty())
    throw std::runtime_error("error: list is empty");

  if (pos < 0 || pos >= length)
    throw std::out_of_range("error: out of index");

  for (int i = pos; i < length - 1; i++)
    data[i] = data[i + 1];

  length--;
}

int main() {
  ArrayList<int> list(0);
  for (int i = 0; i < 10; i++) {
    list.insertRear(i + 10);
  }
  list.insertRear(20);

  try {
    list.remove(3);
    list.display();
    cout << list.find(20) << '\n';
  } catch (std::runtime_error &e) {
    cout << e.what() << '\n';
  }

  /*list.display();

  list.remove(1);
  list.display();
  list.remove(0);
  list.display();*/

  ArrayList<Student> list2({"", 0});
  list2.insertRear({"jinseok", 10});
  list2.find({"jinseok", 10});
}
