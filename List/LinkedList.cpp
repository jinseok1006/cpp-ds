#include <iostream>

using namespace std;
class Node {
private:
  int data;
  Node *link;

public:
  Node(int data) : data(data) { link = nullptr; }
  Node *getLink() { return link; }
  void setLink(Node *p) { link = p; }
  int getData() { return data; }
};

class LinkedList {
private:
  Node *head; // head는 Node가 아니라 Node를 가르키는 포인터 일뿐...
  int length;

public:
  LinkedList() {
    head = nullptr;
    length = 0;
  };
  bool empty() { return head == nullptr; }

  // 인덱스가 0일 때와 1 이상일 때를 구분하여야 함.
  void insert(int pos, Node *item) {
    Node *p = head;

    if (pos < 0 || pos > length)
      throw std::runtime_error(
          "error: out of index"); // throw의 목적: 반환형태를 지키지 않고도
                                  // 함수를 종료할 수 있다.

    if (pos == 0) {
      // setLink는 내가 가르키는 노드의 다음 노드를 설정
      item->setLink(head); // item -> 다음 연결
      // head가 가르킬 노드를 설정
      head = item;
    } else {
      // pos-1에 해당하는 노드를 찾기
      for (int i = 0; i < pos - 1; i++)
        p = p->getLink();

      // p가 pos-1를 가르키고 있음
      item->setLink(p->getLink());
      p->setLink(item);
    }
    length++;
  }

  void remove(int pos) {
    if (empty())
      throw runtime_error("error: list is empty");

    if (pos < 0 || pos >= length)
      throw runtime_error("error: out of index");

    if (pos == 0) {
      head = head->getLink();
    } else {
      Node *p = head;
      for (int i = 0; i < pos - 1; i++)
        p = p->getLink();
      // p는 pos-1을 가르키고 있다.
      Node *r = p->getLink();
      p->setLink(r->getLink());
      delete r;
    }
    length--;
  }
  void display() {
    for (Node *p = head; p != nullptr; p = p->getLink()) {
      cout << p->getData() << ' ';
    }
  }

  int get(int pos) {
    Node *p = head;
    for (int i = 0; i < pos; i++) {
      p = p->getLink();
    }
    return p->getData();
  }

  // pos-1에 접근하여 pos와 item의 링크를 조작
  void replace(int pos, Node *item) {
    if (pos < 0 || pos >= length)
      throw runtime_error("error: out of index");
    if (pos == 0) {
      item->setLink(head);
      head = item;
    } else {
      Node *p = head;
      for (int i = 0; i < pos - 1; i++)
        p = p->getLink();

      Node *r = p->getLink();
      item->setLink(r->getLink());
      p->setLink(item);
      delete r;
    }
  }
};

int main() {
  LinkedList list;

  for (int i = 0; i < 10; i++) {
    list.insert(0, new Node(i));
  }

  // list.insert(8, new Node(12));
  try {

    list.insert(10, new Node(15));
  } catch (runtime_error &e) {
    cout << e.what() << endl;
  }

  list.display();

  return 0;
}