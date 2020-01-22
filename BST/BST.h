#include "NodeT.h"

class BST {
  public:
    BST();
    ~BST();

    bool search(int data);
    void add(int data);
    void remove(int data);

  private:
    NodeT *root;
    int howManyChildren(NoteT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);
};

BST::BST() {
  root = NULL;
}

bool BST::search(int data) {
  NodeT *curr = root;
  while (curr != NULL) {
    if (curr->getData() == data) {
      return true;
    }
    curr = curr->getData() > data ? curr-getLeft() : curr->getRight();
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
    curr = curr->getData() > data ? curr-><getLeft() : curr->getRight();
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
