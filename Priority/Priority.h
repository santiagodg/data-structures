#include <vector>

using namespace std;

class Priority {
  public:
    Priority();
    Priority(bool priorityIsGreater);
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
  private:
    vector<int> heap;
    bool priorityIsGreater;
};

Priority::Priority() {
  heap.push_back(-1);
  priorityIsGreater = true;
}

Priority::Priority(bool priorityIsGreater) {
  heap.push_back(-1);
  this->priorityIsGreater = priorityIsGreater;
}

void Priority::push(int data) {
  heap.push_back(data);
  int index = size(), temp;
  while (index != 1) {
    if (priorityIsGreater) {
      if (data > heap[index / 2]) {
        temp = heap[index / 2];
        heap[index / 2] = data;
        heap[index] = temp;
        index /= 2;
      } else {
        break;
      }
    } else {
      if (data < heap[index / 2]) {
        temp = heap[index / 2];
        heap[index / 2] = data;
        heap[index] = temp;
        index /= 2;
      } else {
        break;
      }
    }
  }
}

void Priority::pop() {
  int result = heap[1], currIndex = 1, temp;
  heap[1] = heap[size()];
  heap.pop_back();
  if (priorityIsGreater) {
    while (currIndex <= size() / 2) {
      if (heap[currIndex * 2] >= heap[currIndex * 2 + 1]) {
        if (heap[currIndex] < heap[currIndex * 2]) {
          temp = heap[currIndex];
          heap[currIndex] = heap[currIndex * 2];
          heap[currIndex * 2] = temp;
          currIndex = currIndex * 2;
        } else {
          break;
        }
      } else {
        if (heap[currIndex] < heap[currIndex * 2 + 1]) {
          temp = heap[currIndex];
          heap[currIndex] = heap[currIndex * 2 + 1];
          heap[currIndex * 2 + 1] = temp;
          currIndex = currIndex * 2 + 1;
        } else {
          break;
        }
      }
    }
  } else {
    while (currIndex <= size() / 2) {
      if (heap[currIndex * 2] <= heap[currIndex * 2 + 1]) {
        if (heap[currIndex] > heap[currIndex * 2]) {
          temp = heap[currIndex];
          heap[currIndex] = heap[currIndex * 2];
          heap[currIndex * 2] = temp;
          currIndex = currIndex * 2;
        } else {
          break;
        }
      } else {
        if (heap[currIndex] > heap[currIndex * 2 + 1]) {
          temp = heap[currIndex];
          heap[currIndex] = heap[currIndex * 2 + 1];
          heap[currIndex * 2 + 1] = temp;
          currIndex = currIndex * 2 + 1;
        } else {
          break;
        }
      }
    }
  }
}

int Priority::top() {
  return heap[1];
}

int Priority::size() {
  return heap.size() - 1;
}

bool Priority::empty() {
  return heap.size() == 1;
}
