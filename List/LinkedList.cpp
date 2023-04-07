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
  Node *head; // head�� Node�� �ƴ϶� Node�� ����Ű�� ������ �ϻ�...
  int length;

public:
  LinkedList() {
    head = nullptr;
    length = 0;
  };
  bool empty() { return head == nullptr; }

  // �ε����� 0�� ���� 1 �̻��� ���� �����Ͽ��� ��.
  void insert(int pos, Node *item) {
    Node *p = head;

    if (pos < 0 || pos > length)
      throw std::runtime_error(
          "error: out of index"); // throw�� ����: ��ȯ���¸� ��Ű�� �ʰ�
                                  // �Լ��� ������ �� �ִ�.

    if (pos == 0) {
      // setLink�� ���� ����Ű�� ����� ���� ��带 ����
      item->setLink(head); // item -> ���� ����
      // head�� ����ų ��带 ����
      head = item;
    } else {
      // pos-1�� �ش��ϴ� ��带 ã��
      for (int i = 0; i < pos - 1; i++)
        p = p->getLink();

      // p�� pos-1�� ����Ű�� ����
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
      // p�� pos-1�� ����Ű�� �ִ�.
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

  // pos-1�� �����Ͽ� pos�� item�� ��ũ�� ����
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