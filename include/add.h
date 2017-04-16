#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#define NIL &NILNODE // ���������� ���� (��� �����)
#include <stack>
using std::stack;
template < typename T>
struct rbnode {
  T value;
  rbnode* left, *right, *parent;
  int color;// 0 -black, 1 - red;

  rbnode<T>(T val = 0, rbnode<T>* a = NIL, rbnode<T>* b = NIL, rbnode<T>* s = NIL, int col = 0) {
    value = val;
    parent = a;
    left = b;
    right = s;
    color = col;
  }
};

rbnode<int> NILNODE = { 0, NULL, NULL, NULL, 0 };

template <typename T>
class RBTree {
private:
  // rbnode<T>* root;
  void RotateRight(rbnode<T> *x); //������� �� �����
  void Rotateleft(rbnode<T> *x); // ������� �� ����
  void InsertFixup(rbnode<T> *x); //�������������� ������� ����� �������
  void DeleteFixup(rbnode<T> *x); // �������������� ������� ����� ��������
public:
  rbnode<T>* root;
  RBTree(); // ����������� ������
  ~RBTree();  // ����������
  void Insert(T v); // ������� ���� �� ��������
  void Delete(T v); // �������� ���� �� ��������
  void Delete(rbnode<T>* v); //  �������� ���� �� ������
  rbnode<T>* Find(T v);  //����� ���� �� ��������
};

template < typename T >
RBTree<T>::RBTree(){
  root = nullptr;
}
template < typename T >
RBTree<T>::~RBTree(){
  stack< rbnode <T>* > a;
  if (root != NULL) {
    a.push(root);
  }  else {
    delete root;
  }
  while (!a.empty()) {
    rbnode<T>* node = a.top();
    a.pop();
    if (node->left != NIL)
      a.push(node->left);
    if (node->right != NIL)
      a.push(node->right);
      delete node;
  }
}
////////////////////////////������� �� �����
template < typename T >
void RBTree<T>::RotateRight(rbnode<T> *x) {
  bool flag = false;
  if (x == root)
    flag = true;

  rbnode<T> *y = x->left;
  // ������������ ����� ��������� ��� x
  x->left = y->right;
  if (y->right != NIL)
    y->right->parent = x;
  if (y != NIL)
    y->parent = x->parent;
  if (x->parent != NULL) {
    if (x == x->parent->right)
      x->parent->right = y;
    else x->parent->left = y;
  }
  else root = y;
  // ���������� x � y
  y->right = x;
  if (x != NIL)
    x->parent = y;
  if (flag)
    root = root->parent;

}
////////////////////////////������� �� ����
template <typename T>
void RBTree<T>::Rotateleft(rbnode<T> *x) {
 bool flag = false;
  if ( x == root)
    flag = true;
  rbnode<T> *y = x->right;
 // root = x->parent;
  x->right = y->left;
  if (y->left != NIL)
    y->left->parent = x;
  if (y != NIL)
    y->parent = x->parent;
  if (x->parent != NULL) {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  }
  else root = y;
  y->left = x;
  if (x != NIL)
    x->parent = y;
  if ( flag )
    root = root->parent;
}

/////////////////////������������ ����� �������
template < typename T >
void RBTree<T>::InsertFixup(rbnode <T> *x) {
  while (x != root && x->parent->color == 1) {
    if (x->parent == x->parent->parent->left) {
      rbnode<T> *uncle = x->parent->parent->right;
      if (uncle->color == 1) {
        x->parent->color = uncle->color = 0;
        x->parent->parent->color = 1;
        x = x->parent->parent;
      }
      else {
        if (x == x->parent->right) {
          x = x->parent;
          Rotateleft(x);
        }
        x->parent->color = 0;
        x->parent->parent->color = 1;
        RotateRight(x->parent->parent);
      }
    }
    else {
      rbnode<T> *uncle = x->parent->parent->left;
      if (uncle->color == 1) {
        x->parent->color = uncle->color = 0;
        x->parent->parent->color = 1;
        x = x->parent->parent;
      }
      else {
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


//////////////////////������������ ����� ��������
template < typename T >
void RBTree<T>::DeleteFixup(rbnode <T>* x) {
  while (x != root && x->color == 0) {
    if (x == x->parent->left)    {  // ��������� ������� � ������ ������ ���������
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
      }
      else {
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
    }
    else {  // ��������� ������� � ������ ������� ���������
      rbnode<T> *brother = x->parent->left;
      if (brother->color == 1) {
        brother->color = 0;
        x->parent->color = 1;
        RotateRight(x->parent);
        brother = x->parent->left;
      }
      if (brother->right->color == 0 && brother->left->color == 0) {
        brother->color = 1;
        x = x->parent;
      }
      else {
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
  x->color = 0;
}
////////////////////////////////////�������
template < typename T >
void RBTree<T>::Insert(T v) {
  if (root == nullptr) {
    root = new rbnode<T>(v, NIL, NIL, NIL, 0);
  }
  else {
    rbnode<T> *current = root;
    rbnode<T> *parent = NULL;
    rbnode<T> *newnode;
    while (current != NIL) {
      parent = current;
      if (v < current->value)
        current = current->left;
      else
        current = current->right;
    }
    newnode = new rbnode<T>(v, parent, NIL, NIL, 1);
    if (parent == NULL) {
      root = newnode;
    }
    else {
      if (newnode->value < parent->value) {
        parent->left = newnode;
      }
      else {
        parent->right = newnode;
      }
      InsertFixup(newnode);  // ������������
    }
  }
}

template < typename T >
void RBTree<T>::Delete(T v) {
  rbnode<T> *x = Find(v);
  Delete(x);
}
/////////////////////////////// ����� �� ��������
template < typename T >
rbnode<T>* RBTree<T>::Find(T v)  {
  if (root != NULL) {
    rbnode<T> *current = root;
    for (;;) {
      if (current == NIL) return nullptr;
      if (current->value == v)
        return current;
      if (v < current->value)
        current = current->left;
      else
        current = current->right;
     }
    } else {
       throw 1;
    }
}


template < typename T >
void RBTree<T>::Delete(rbnode<T> *v) {
  rbnode<T> *x, *y;
  if (v == NULL || v == NIL)
    return;
  if (v->left == NIL || v->right == NIL) {
    y = v;
  }
  else {
    y = v->right;
    while (y->left != NIL) {
      y = y->left;
    }
  }
  if (y->left != NIL)
    x = y->left;
  else
    x = y->right;
  x->parent = y->parent;
  if (y->parent != NULL){
    if (y == y->parent->left)
      y->parent->left = x;
    else
      y->parent->right = x;
  }
  else
    root = x;
  if (y != v) {
    v->value = y->value;
  }
  if (y->color == 0) {
    DeleteFixup(x);
  }
  delete y;
}

#endif  // INCLUDE_ADD_H_