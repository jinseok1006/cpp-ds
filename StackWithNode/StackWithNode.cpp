#include <iostream>

using namespace std;

class Student {
private:
  int id;
  string name;
  string dept;

public:
  Student(const int &id, const string &name, const string &dept)
      : id(id), name(name), dept(dept) {
    cout << "Student ������ ����!!" << endl;
  }
  void display() { cout << id << ' ' << name << ' ' << dept << endl; }
};

template <typename T> class Node {
private:
  T data;
  Node *link;

public:
  Node(const T &e) : data(e) { link = nullptr; }
  Node *getLink() { return link; }
  void setLink(Node *p) { link = p; } // ������ ����Ű�� ��ũ
  T getData() { return data; }
};

template <typename T> class LinkedStack {
private:
  Node<T> *top;

public:
  LinkedStack() { top = nullptr; }

  bool empty() { return top == nullptr; }

  void push(Node<T> *p) {
    if (empty())
      top = p;
    else {
      p->setLink(top);
      top = p;
    }
  }

  Node<T> *pop() {
    if (empty())
      return nullptr;
    Node<T> *p = top;
    top = top->getLink();
    return p;
  }

  Node<T> *peek() {
    if (empty())
      return nullptr;
    else
      return top;
  }
  
  void display() {
    for (Node<T>* p = top; p != nullptr; p = p->getLink()) 
      p->getData().display();
  }
};

int main() {
  LinkedStack<Student> stack;
  stack.push(new Node<Student>(Student(20151234, "ȫ�浿", "��ǻ�Ͱ��а�")));

 int k;
 cin>>k;
  for (int i = 0; i < k; i++) {
    int id = 20151234 + i;
    string name = "��?��";
    string dept = "����?�а�";
    // �Ҵ��ѰԾƴϰ� Student��ü ���ͷ��� ��򰡸� �����ٰ� ���°� ���� �ʳ�..?��
    stack.push(new Node<Student>(Student(id, name, dept)));
  }

  stack.display();

  /*Node<Student> a1({0, "jinseok", "csai"});

  Node<Student> a2({1, "js2", "csbb"});
  a1.setLink(&a2);

  Node<Student> a3({2, "sjdae", "ewjioa"});
  a2.setLink(&a3);

  Node<Student> *next = &a1;
  while (next != nullptr) {
    auto const &data = next->getData();
    auto &id = data.id;
    auto &name = data.name;
    auto &dept = data.dept;

    cout << id << ' ' << name << ' ' << dept << endl;
    next = next->getLink();
  }*/

  return 0;
}