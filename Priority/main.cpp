#include "Priority.h"
#include <iostream>

using namespace std;

int main() {

  Priority p1;
  Priority p2(false);

  p1.push(10);
  p1.push(20);
  p1.push(5);
  p1.push(2);
  p1.push(7);
  p1.push(15);
  p1.push(12);
  p1.push(17);

  p2.push(10);
  p2.push(20);
  p2.push(5);
  p2.push(2);
  p2.push(7);
  p2.push(15);
  p2.push(12);
  p2.push(17);

  cout << "p1.size(): " << p1.size() << endl;
  cout << "p1: ";
  while (!p1.empty()) {
    cout << p1.top() << " ";
    p1.pop();
  }
  cout << endl;
  cout << "p1.size(): " << p1.size() << endl;

  cout << "p2.size(): " << p2.size() << endl;
  cout << "p2: ";
  while (!p2.empty()) {
    cout << p2.top() << " ";
    p2.pop();
  }
  cout << endl;
  cout << "p2.size(): " << p2.size() << endl;

  return 0;
}
