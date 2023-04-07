
#include <iostream>
using namespace std;
class MyClass {
public:
  int a;
  MyClass(int a) : a(a) {}
};
int main() {

  for (int i = 0; i < 10; i++) {
    cout << (new MyClass(2))->a << endl;
    cout << MyClass(3).a << endl;
  }
}