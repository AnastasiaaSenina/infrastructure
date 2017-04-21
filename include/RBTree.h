#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_
#define NIL &NILNODE  //  сторожевой узел (для листа)
#include <stack>
using std::stack;
using std:: pair;
template < typename T>
struct rbnode {
  T value;
  rbnode* left, *right, *parent;
  int color;  //  0 -black, 1 - red;

  rbnode<T>(T val = 0, rbnode<T>* a = reinterpret_cast<rbnode<T>*>(NIL),
  rbnode<T>* b = reinterpret_cast<rbnode<T>*>(NIL),
  rbnode<T>* s = reinterpret_cast<rbnode<T>*>(NIL), int col = 0) {
    value = val;
    parent = a;
    left = b;
    right = s;
    color = col;
  }
};

extern rbnode< pair< int, int >> NILNODE;

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
  bool CHECKCORRECT();
  bool isempty() {
    if (root == reinterpret_cast<rbnode<T>*>(NIL) || root == NULL )
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
  if (root != NULL && root!= reinterpret_cast<rbnode<T>*>(NIL)) {
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
  bool flag = false;
  if (x == root)
    flag = true;
  rbnode<T> *y = x->left;
  x->left = y->right;
  if (y->right != reinterpret_cast<rbnode<T>*>(NIL)) {
    y->right->parent = x;
  }
  if (y != reinterpret_cast<rbnode<T>*>(NIL))
    y->parent = x->parent;
  if (x->parent != NULL) {
    if (x == x->parent->right) {
      x->parent->right = y;
    }
    else {
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
 bool flag = false;
  if ( x == root)
    flag = true;
  rbnode<T> *y = x->right;
  x->right = y->left;
  if (y->left != reinterpret_cast<rbnode<T>*>(NIL))
    y->left->parent = x;
  if (y != reinterpret_cast<rbnode<T>*>(NIL))
    y->parent = x->parent;
  if (x->parent != NULL) {
    if (x == x->parent->left)
      x->parent->left = y;
    else
      x->parent->right = y;
  }
  else root = y;
    y->left = x;
  if (x != reinterpret_cast<rbnode<T>*>(NIL))
    x->parent = y;
}
/////////////////////балансировка после вставки
template < typename T >
void RBTree<T>::InsertFixup(rbnode <T> *x) {
  while (x != root && x->parent->color == 1 && x->parent->parent != NULL) {
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


 //  балансировка после удаления
template < typename T >
void RBTree<T>::DeleteFixup(rbnode <T>* x) {
  while ( x!= reinterpret_cast<rbnode<T>*>(NIL) && x != root && x->color == 0) {
    if (x == x->parent->left)    {
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
    else {
      rbnode<T> *brother = x->parent->left;
      if (brother != NULL) {
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
  }
  x->color = 0;

}
template < typename T >
void RBTree<T>::Insert(T v) {
  if (root == nullptr) {
    root = new rbnode<T>(v, NULL, reinterpret_cast<rbnode<T>*>(NIL),
    reinterpret_cast<rbnode<T>*>(NIL), 0);
  }
  else {
    rbnode<T> *current = root;
    rbnode<T> *parent = NULL;
    rbnode<T> *newnode;
    while (current != reinterpret_cast<rbnode<T>*>(NIL)) {
      parent = current;
      if (v < current->value)
        current = current->left;
      else
        current = current->right;
    }
    newnode = new rbnode<T>(v, parent, reinterpret_cast<rbnode<T>*>(NIL),
    reinterpret_cast<rbnode<T>*>(NIL), 1);
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
      InsertFixup(newnode);
    }
  }
}

template < typename T >
void RBTree<T>::Delete(T v) {
  if (root != NULL) {
    rbnode<T> *x = Find(v);
    Delete(x);
  } else {
     throw 1;
   }
}
template < typename T >
rbnode<T>* RBTree<T>::Find(T v)  {
  if (root != NULL && root != reinterpret_cast<rbnode<T>*>(NIL)) {
    rbnode<T> *current = root;
    for (;;) {
      if (current == reinterpret_cast<rbnode<T>*>(NIL)) return nullptr;
      if (current->value == v)
        return current;
      if (v < current->value) {
        if ( current->left != NULL)
           current = current->left;
           }
      else {
        if (current->right != NULL)
          current = current->right;
        }
     }
    } else {
       throw 1;
    }
}
template < typename T >
void RBTree<T>::Delete(rbnode<T> *v) {
  if (root != NULL) {
  rbnode<T> *x, *y;
  if (v == NULL || v == reinterpret_cast<rbnode<T>*>(NIL))
    return;
  if (v->left == reinterpret_cast<rbnode<T>*>(NIL) || v->right == reinterpret_cast<rbnode<T>*>(NIL)) {
    y = v;
  }
  else {
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
  if (rootcopy != NULL) {
    while (rootcopy->left != reinterpret_cast<rbnode<T>*>(NIL))
      rootcopy= rootcopy->left;
    Delete(rootcopy);
  }
}
template < typename T >
T RBTree<T>::GetMin() {
  rbnode<T>* rootcopy = root;
  if (rootcopy != NULL) {
    while (rootcopy->left != reinterpret_cast<rbnode<T>*>(NIL))
      rootcopy = rootcopy->left;
    return rootcopy->value;
  }
}
/*
template < typename T >
bool RBTree<T>::CHECKCORRECT() { //проверка на "черную" высоту и...
  vector<int> BH;
  stack<rbnode<T>*> a;
  int Black_H = 0;
  int H = 0;

  if (root != 0) {
    bool flag1 = false;
    bool flag2  = false;
    a.push(root);
    while (!a.empty()) {
      rbnode<T> * current_node = a.top();
      a.pop();
      if (current_node->color == 0) {
        Black_H++;
        } else {
          if (current_node->parent->color != 0) 
            return false;
        }
      if (current_node->left == reinterpret_cast<rbnode<T>*>(NIL)) {
        BH.push_back(Black_H+1);
       
      } else {
        a.push(current_node->left);
        //flag1 = false;
        flag1 = true;
      }
      if (current_node->right == reinterpret_cast<rbnode<T>*>(NIL)) {
        BH.push_back(Black_H + 1);
        
      }
      else {
        a.push(current_node->right);
       // flag2 = false;
        flag2 = true;
      }
      if (flag1 != true && flag2 != true && current_node->color == 0 )
        Black_H--;
       flag1 = false;
       flag2 = false;
         }
  }

  for (int i = 0; i < BH.size(); ++i) {
    if (BH[i] != BH[0])
      return false;
  }
  return true;
   
}
*/
#endif  // INCLUDE_RBTREE_H_
