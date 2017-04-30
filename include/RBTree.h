#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_
#include <stack>

using std::stack;
using std:: pair;

template < typename T>
  //  сторожевой узел (для листа)
struct rbnode {
  T value;
  rbnode* left, *right, *parent;
  int color;  //  0 -black, 1 - red;
  rbnode<T>(T val, rbnode<T>* a, rbnode<T>* b, rbnode<T>* s, int col) {
    value = val;
    parent = a;
    left = b;
    right = s;
    color = col;
  }
};
extern rbnode<pair<int, int>> NILNODE;
#define NIL &NILNODE

template <typename T>
class RBTree {
 private:
  void RotateRight(rbnode<T> *x);  //  поворот на право
  void Rotateleft(rbnode<T> *x);  //  поворот на лево
  void InsertFixup(rbnode<T> *x);  //  восстановление баланса после вставки
  void DeleteFixup(rbnode<T> *x);  //  восстановление баланса после удаления
 public:
  rbnode<T>* root;
  RBTree();  //  коснтруктор простo
  ~RBTree();  //  деструктор
  void Insert(T v);  //  вставка узла по значению
  void DeleteMin();
  void Delete(T v);  //  удаление узла по значению
  void Delete(rbnode<T>* v);  //  удаление узла по адресу
  rbnode<T>* Find(T v);  //  поиск узла по значению
  bool isempty() {
    if (root == reinterpret_cast<rbnode<T>*>(NIL) || root == nullptr )
      return true;
    else
      return false;
  }
  T GetMin();
};

template < typename T >
RBTree<T>::RBTree() {
  root = nullptr;
}
template < typename T >
RBTree<T>::~RBTree() {
  stack< rbnode <T>* > a;
  if (root != nullptr && root!= reinterpret_cast<rbnode<T>*>(NIL)) {
    a.push(root);
  } else {
    if (root!= reinterpret_cast<rbnode<T>*>(NIL))
      delete root;
  }
  while (!a.empty()) {
    rbnode<T>* node = a.top();
    a.pop();
    if (node->left != reinterpret_cast<rbnode<T>*>(NIL)) {
      a.push(node->left);
    }
    if (node->right != reinterpret_cast<rbnode<T>*>(NIL)) {
      a.push(node->right);
    }
    if (node != reinterpret_cast<rbnode<T>*>(NIL)) {
      delete node;
    }
  }
}

template < typename T >
void RBTree<T>::RotateRight(rbnode<T> *x) {
  rbnode<T> *y = x->left;
  x->left = y->right;
  if (y->right != reinterpret_cast<rbnode<T>*>(NIL)) {
    y->right->parent = x;
  }
  if (y != reinterpret_cast<rbnode<T>*>(NIL))
    y->parent = x->parent;
  if (x->parent != nullptr) {
    if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
  } else {
    root = y;
  }
  y->right = x;
  if (x != reinterpret_cast<rbnode<T>*>(NIL))
    x->parent = y;
}

////////////////////////////поворот на лево
template <typename T>
void RBTree<T>::Rotateleft(rbnode<T> *x) {
  rbnode<T> *y = x->right;
  x->right = y->left;
  if (y->left != reinterpret_cast<rbnode<T>*>(NIL))
    y->left->parent = x;
  if (y != reinterpret_cast<rbnode<T>*>(NIL))
    y->parent = x->parent;
  if (x->parent != nullptr) {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  } else {
    root = y;
  }
    y->left = x;
  if (x != reinterpret_cast<rbnode<T>*>(NIL))
    x->parent = y;
}
/////////////////////балансировка после вставки
template < typename T >
void RBTree<T>::InsertFixup(rbnode <T> *x) {
  while (x != root && x->parent->color == 1 && x->parent->parent != nullptr) {
    if (x->parent == x->parent->parent->left) {
      rbnode<T> *uncle = x->parent->parent->right;
      if (uncle->color == 1) {
        x->parent->color = uncle->color = 0;
        x->parent->parent->color = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->right) {
          x = x->parent;
          Rotateleft(x);
        }
        x->parent->color = 0;
        x->parent->parent->color = 1;
        RotateRight(x->parent->parent);
      }
    } else {
      rbnode<T> *uncle = x->parent->parent->left;
      if (uncle->color == 1) {
        x->parent->color = uncle->color = 0;
        x->parent->parent->color = 1;
        x = x->parent->parent;
      } else {
        if (x == x->parent->left) {
          x = x->parent;
          RotateRight(x);
        }
        x->parent->color = 0;
        x->parent->parent->color = 1;
        Rotateleft(x->parent->parent);
      }
    }
  }
  root->color = 0;
}


  //  балансировка после удаления
template < typename T >
void RBTree<T>::DeleteFixup(rbnode <T>* x) {
  while (x!= reinterpret_cast<rbnode<T>*>(NIL) && x != root && x->color == 0) {
    if (x == x->parent->left) {
      rbnode<T> *brother = x->parent->right;
      if (brother->color == 1) {
        brother->color = 0;
        x->parent->color = 1;
        Rotateleft(x->parent);
        brother = x->parent->right;
      }
      if (brother->left->color == 0 && brother->right->color == 0) {
        brother->color = 1;
        x = x->parent;
      } else {
        if (brother->right->color == 0) {
          brother->left->color = 0;
          brother->color = 1;
          RotateRight(brother);
          brother = x->parent->right;
        }
        brother->color = x->parent->color;
        x->parent->color = 0;
        brother->right->color = 0;
        Rotateleft(x->parent);
        x = root;
      }
    } else {
      rbnode<T> *brother = x->parent->left;
      if (brother != nullptr) {
        if (brother->color == 1) {
          brother->color = 0;
          x->parent->color = 1;
          RotateRight(x->parent);
          brother = x->parent->left;
        }
        if (brother->right->color == 0 && brother->left->color == 0) {
          brother->color = 1;
          x = x->parent;
        } else {
          if (brother->left->color == 0) {
            brother->right->color = 0;
            brother->color = 1;
            Rotateleft(brother);
            brother = x->parent->left;
          }
          brother->color = x->parent->color;
          x->parent->color = 0;
          brother->left->color = 1;
          RotateRight(x->parent);
          x = root;
        }
      }
    }
  }
  x->color = 0;
}
template < typename T >
void RBTree<T>::Insert(T v) {
  if (root == nullptr) {
    root = new rbnode<T>(v, nullptr, reinterpret_cast<rbnode<T>*>(NIL),
    reinterpret_cast<rbnode<T>*>(NIL), 0);
  } else {
    rbnode<T> *current = root;
    rbnode<T> *parent = nullptr;
    rbnode<T> *newnode;
    while (current != reinterpret_cast<rbnode<T>*>(NIL)) {
      parent = current;
      if (v < current->value) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    newnode = new rbnode<T>(v, parent, reinterpret_cast<rbnode<T>*>(NIL),
    reinterpret_cast<rbnode<T>*>(NIL), 1);
    if (parent == nullptr) {
      root = newnode;
    } else {
      if (newnode->value < parent->value) {
        parent->left = newnode;
      } else {
        parent->right = newnode;
      }
      InsertFixup(newnode);
    }
  }
}

template < typename T >
void RBTree<T>::Delete(T v) {
  if (root != nullptr) {
    rbnode<T> *x = Find(v);
    Delete(x);
  } else {
     throw 1;
  }
}
template < typename T >
rbnode<T>* RBTree<T>::Find(T v) {
  if (root != nullptr && root != reinterpret_cast<rbnode<T>*>(NIL)) {
    rbnode<T> *current = root;
    for (;;) {
      if (current == reinterpret_cast<rbnode<T>*>(NIL))
        return nullptr;
      if (current->value == v)
        return current;
      if (v < current->value) {
        if ( current->left != nullptr)
          current = current->left;
      } else {
        if (current->right != nullptr)
          current = current->right;
      }
    }
  } else {
    throw 1;
  }
}
template < typename T >
void RBTree<T>::Delete(rbnode<T> *v) {
  if (root != nullptr) {
  rbnode<T> *x, *y;
  if (v == nullptr || v == reinterpret_cast<rbnode<T>*>(NIL))
    return;
  if (v->left == reinterpret_cast<rbnode<T>*>(NIL) ||
  v->right == reinterpret_cast<rbnode<T>*>(NIL)) {
    y = v;
  } else {
    y = v->right;
    while (y->left != reinterpret_cast<rbnode<T>*>(NIL)) {
      y = y->left;
    }
  }
  if (y->left != reinterpret_cast<rbnode<T>*>(NIL))
    x = y->left;
  else
    x = y->right;
  x->parent = y->parent;
  if (y->parent != nullptr) {
    if (y == y->parent->left)
      y->parent->left = x;
    else
      y->parent->right = x;
  } else {
    root = x;
  }
  if (y != v) {
    v->value = y->value;
  }
  if (y->color == 0) {
    DeleteFixup(x);
  }
  if (y == root)
    root = nullptr;
  else
    delete y;
  } else {
    throw 1;
  }
}
template < typename T >
void RBTree<T>::DeleteMin() {
  rbnode<T>* rootcopy = root;
  if (rootcopy != nullptr) {
    while (rootcopy->left != reinterpret_cast<rbnode<T>*>(NIL))
      rootcopy = rootcopy->left;
    Delete(rootcopy);
  }
}
template < typename T >
T RBTree<T>::GetMin() {
  rbnode<T>* rootcopy = root;
  if (rootcopy != nullptr) {
    while (rootcopy->left != reinterpret_cast<rbnode<T>*>(NIL))
      rootcopy = rootcopy->left;
    return rootcopy->value;
  } else {
    throw 1;
  }
}
#endif  // INCLUDE_RBTREE_H_
