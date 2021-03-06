#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include "NodeT.h"

class BST {
  public:
    BST();
    BST(const BST &oldBST);
    ~BST();

    bool search(int data);
    void add(int data);
    void remove(int data);

    void print(int x);
    int count();
    int height();
    void ancestors(int data);
    int whatLevelamI(int data);
    int maxWidth();
    int nearstRelative(int data1, int data2); // named by teacher
    queue<int> toQueue();

    bool operator==(const BST &rhs);

  private:
    NodeT *root;

    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void converseInOrder(NodeT *r, queue<int> &qiu);

    void libera(NodeT *r);
    void printLeaves(NodeT *r);
    int count(NodeT *r);
    int height(NodeT *r);
    void nivelXnivel();
    bool search(int data, NodeT *r);
    bool isIdentical(NodeT *root1, NodeT *root2) const;
    int getWidth(NodeT *root, int level);
};

BST::BST() {
  root = NULL;
}

BST::BST(const BST &oldBST) {
  root = NULL;
  // Level traversal of passed BST pushing traversed NodeT*s into a
  // queue and add()ing queue's FIFO ordered data into this BST.
  queue<NodeT*> qiu;
  qiu.push(oldBST.root);
  while (!qiu.empty()) {
    if (qiu.front() != NULL) {
      add(qiu.front()->getData());
      qiu.push(qiu.front()->getLeft());
      qiu.push(qiu.front()->getRight());
    }
    qiu.pop();
  }
}

BST::~BST() {
  libera(root);
}

bool BST::search(int data) {
  NodeT *curr = root;
  while (curr != NULL) {
    if (curr->getData() == data) {
      return true;
    }
    curr = curr->getData() > data ? curr->getLeft() : curr->getRight();
  }
  return false;
}

void BST::add(int data) {
  NodeT *father = NULL;
  NodeT *curr = root;

  while (curr != NULL) {
    father = curr;
    if (curr->getData() == data) {
      return;
    }
    curr = curr->getData() > data ? curr->getLeft() : curr->getRight();
  }
  if (father == NULL) {
    root = new NodeT(data);
  } else {
    if (father->getData() > data) {
      father->setLeft(new NodeT(data));
    } else {
      father->setRight(new NodeT(data));
    }
  }
}

void BST::remove(int data) {
  NodeT *curr = root;
  NodeT *father = NULL;
  while (curr != NULL && curr->getData() != data) {
    father = curr;
    curr = curr->getData() > data ? curr->getLeft() : curr->getRight();
  }
  if (curr == NULL) {
    return;
  }
  int c = howManyChildren(curr);
  switch (c) {
    case 0:
      if (father == NULL) {
        root = NULL;
      } else {
        if (father->getData() > data) {
          father->setLeft(NULL);
        } else {
          father->setRight(NULL);
        }
      }
      delete curr;
      break;
    case 1:
      if (father == NULL) {
        if (curr->getLeft() != NULL) {
          root = curr->getLeft();
        } else {
          root = curr->getRight();
        }
        // root = curr->getLeft() != NULL ? curr->getLeft() : curr->getRight();
      } else {
        if (father->getData() > data) {
          // si es mi hijo izq
          if (curr->getLeft() != NULL) {
            father->setLeft(curr->getLeft());
          } else {
            father->setLeft(curr->getRight());
          }
        } else {
          // si es mi hijo derecho
          if (curr->getLeft() != NULL) {
            father->setRight(curr->getLeft());
          } else {
            father->setRight(curr->getRight());
          }
        }
      }
      delete curr;
      break;
    case 2:
      int x = succ(curr);
      remove(x);
      curr->setData(x);
      break;
  }
}

void BST::print(int x) {
  switch (x) {
    case 1: preOrder(root);
      break;
    case 2: inOrder(root);
      break;
    case 3: postOrder(root);
      break;
    case 4: printLeaves(root);
      break;
    case 5: nivelXnivel();
      break;
  }
  cout << endl;
}

int BST::count() {
  return count(root);
}

int BST::height() {
  return height(root);
}

void BST::ancestors(int data) {
  NodeT *curr = root;
  stack<int> stacc;
  while (curr->getData() != data) {
    stacc.push(curr->getData());
    curr = data > curr->getData() ? curr->getRight() : curr->getLeft();
  }
  while (!stacc.empty()) {
    cout << stacc.top() << " ";
    stacc.pop();
  }
  cout << endl;
}

int BST::whatLevelamI(int data) {
  NodeT *curr = root;
  int level = 0;
  while (curr != NULL) {
    if (curr->getData() == data) {
      return level;
    }
    curr = curr->getData() > data ? curr->getLeft() : curr->getRight();
    level++;
  }
  return -1;
}

int BST::maxWidth() {
  int maxWidth = 0, width;
  for (int i = 1; i < height(); i++) {
    width = getWidth(root, i);
    if (width > maxWidth) {
      maxWidth = width;
    }
  }
  return maxWidth;
}

int BST::nearstRelative(int n1, int n2) {
  if (n1 > n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
  }
  NodeT *curr = root;
  if (curr->getData() == n1 || curr->getData() == n2) {
    return -1;
  }
  while (curr != NULL) {
    if (n1 < curr->getData() && curr->getData() < n2) {
      // return curr->getData();
      // verify n1 and n2 exist
      if (search(n1, curr->getLeft()) && search(n2, curr->getRight())) {
        return curr->getData();
      } else {
        return -1;
      }
    } else if (curr->getLeft()->getData() == n1) {
      // return curr->getData();
      // verify n2 exists
      if (search(n2, curr->getLeft())) {
        return curr->getData();
      } else {
        return -1;
      }
    } else if (curr->getLeft()->getData() == n2) {
      // return curr->getData();
      // verify n1 exists
      if (search(n1, curr->getLeft())) {
        return curr->getData();
      } else {
        return -1;
      }
    } else if (curr->getRight()->getData() == n1) {
      // return curr->getData();
      // verify n2 exists
      if (search(n2, curr->getRight())) {
        return curr->getData();
      } else {
        return -1;
      }
    } else if (curr->getRight()->getData() == n2) {
      // return curr->getData();
      // verify n1 exists
      if (search(n1, curr->getRight())) {
        return curr->getData();
      } else {
        return -1;
      }
    } else if (n1 < curr->getData() && n2 < curr->getData()) {
      curr = curr->getLeft();
    } else if (n1 > curr->getData() && n2 > curr->getData()) {
      curr = curr->getRight();
    } else {
      return -1;
    }
  }
  return -1;
}

queue<int> BST::toQueue() {
  /**
  *  Returns a queue<int> where data is in descending order.
  */
  queue<int> qiu;
  // Converse inOrder traversal
  converseInOrder(root, qiu);
  return qiu;
}

bool BST::operator==(const BST &rhs) {
  // call recursive helper function to check for equality
  return isIdentical(this->root, rhs.root);
}

int BST::howManyChildren(NodeT *r) {
  int cont = 0;
  if (r->getLeft() != NULL) {
    cont++;
  }
  if (r->getRight() != NULL) {
    cont++;
  }
  return cont;
}

int BST::pred(NodeT *r) {
  NodeT *curr = r->getLeft();
  while (curr != NULL && curr->getRight() != NULL) {
    curr = curr->getRight();
  }
  return curr->getData();
}

int BST::succ(NodeT *r) {
  NodeT *curr = r->getRight();
  while (curr != NULL && curr->getLeft() != NULL) {
    curr = curr->getLeft();
  }
  return curr->getData();
}

void BST::preOrder(NodeT *r) {
  if (r != NULL) {
    cout << r->getData() << " ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
  }
}

void BST::inOrder(NodeT *r) {
  if (r != NULL) {
    inOrder(r->getLeft());
    cout << r->getData() << " ";
    inOrder(r->getRight());
  }
}

void BST::converseInOrder(NodeT *r, queue<int> &qiu) {
  /**
  * Pushes BST data into queue in converseInOrder traversal
  */
  if (r != NULL) {
    converseInOrder(r->getRight(), qiu);
    qiu.push(r->getData());
    converseInOrder(r->getLeft(), qiu);
  }
}

void BST::postOrder(NodeT *r) {
  if (r != NULL) {
    postOrder(r->getLeft());
    postOrder(r->getRight());
    cout << r->getData() << " ";
  }
}

void BST::libera(NodeT *r) {
  if (r != NULL) {
    libera(r->getLeft());
    libera(r->getRight());
    delete r;
  }
}

void BST::printLeaves(NodeT *r) {
  if (r != NULL)
  {
    if (r->getLeft() == NULL && r->getRight() == NULL)
    {
      cout << r->getData() << " ";
    }
    else
    {
      printLeaves(r->getLeft());
      printLeaves(r->getRight());
    }
  }
}

int BST::count(NodeT *r) {
  if (r != NULL)
  {
    return 1 + count(r->getLeft()) + count(r->getRight());
  }
  else
  {
    return 0;
  }
}

int BST::height(NodeT *r) {
  if (r != NULL) {
    int leftHeight = height(r->getLeft());
    int rightHeight = height(r->getRight());
    return 1 + ( leftHeight >= rightHeight ?  leftHeight : rightHeight );
  }
  return 0;
}

void BST::nivelXnivel() {
  queue<NodeT*> qiu;
  qiu.push(root);
  while (!qiu.empty()) {
    if (qiu.front()->getLeft() != NULL) {
      qiu.push(qiu.front()->getLeft());
    }
    if (qiu.front()->getRight() != NULL) {
      qiu.push(qiu.front()->getRight());
    }
    cout << qiu.front()->getData() << " ";
    qiu.pop();
  }
}

bool BST::search(int data, NodeT *r) {
  NodeT *curr = r;
  while (curr != NULL) {
    if (curr->getData() == data) {
      return true;
    }
    curr = curr->getData() > data ? curr->getLeft() : curr->getRight();
  }
  return false;
}

bool BST::isIdentical(NodeT *root1, NodeT *root2) const {
  // if both trees are empty then return true
  if (root1 == NULL && root2 == NULL) {
    return true;
  } else {
    // if one root is null but the other one is not, then return false
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL) return false;
    // if data on both nodes are identical, return equality of left and right
    if (root1->getData() == root2->getData()) {
      return isIdentical(root1->getLeft(), root2->getLeft()) && isIdentical(root1->getRight(), root2->getRight());
    } else {
      return false;
    }
  }
}

int BST::getWidth(NodeT *root, int level) {
  if (!root) return 0;
  if (level == 1) return 1;
  if (level > 1) {
    return getWidth(root->getLeft(), level - 1) +
      getWidth(root->getRight(), level - 1);
  }
  return -1;
}
