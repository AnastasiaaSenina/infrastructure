#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#define NIL &NILNODE // сторожевой узел (дл€ листа)
template < typename T>
struct rbnode {
  T value;
  rbnode* left, right, parent;
  int color;// 0 -black, 1 - red;
};
rbnode<int> NILNODE = { 0, 0, 0, 0, 0 };

template <typename T>
class RBTree {
 private:
  rbnode<T>* root;
  void RotateRight(rbnode<T> *x); //поворот на право
  void Rotateleft(rbnode<T> *x); // поворот на лево
  void InsertFixup(rbnode<T> *x); //восстановление баланса после вставки
  void DeleteFixup(rbnode<T> *x); // восстановление баланса после удалени€
public:
  RBTree(rbnode<T> rt = NIL); // коснтруктор просто
  ~RBTree(void);  // деструктор
  RBTree Insert(const T& v); // вставка узла по значению
  RBTree Delete(const T& v); // удаление узла по значению
  RBTree Delete(rbnode<T>* v); //  удаление узла по адресу
  rbnode<T>* Find(cost T& v);  //поиск узла по значению
};

////////////////////////////поворот на право
template < typename T>
void RotateRight(rbnode<T> *x) {
  RBTreeNode<T> *y = x->left;
  // ‘ормирование левое поддерево дл€ x
  x->left = y->right;
  if( y->right != NIL )
    y->right->parent = x;  
  if (y != NIL)
    y->parent = x->parent;
  if (x->parent != NULL) {
    if (x == x->parent->right)
      x->parent->right = y;
    else x->parent->left = y;
  }
  else root = y;
  // —в€зывание x и y
    y->right = x;
    if( x != NIL )
    x->parent = y; 
 }
////////////////////////////поворот на лево
template <typename T>
void RotateRight(rbnode<T> *x) {
  RBTreeNode<T> *y = x->right;
  x->right = y->left;
  if( y->left != NIL )
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
  if( x != NIL )
    x->parent = y; 
}

/////////////////////балансировка после вставки
template < typename T>
void InsertFixup(rbnode <T> *x) {
  while( x != root && x->parent->color == 1 ) {
    if( x->parent == x->parent->parent->left ) {
    RBTreeNode<T> *uncle = x->parent->parent->right;  
    if (uncle->color == 1) {
      x->parent->color = uncle->color = 0;
      x->parent->parent->color = 1;  
      x = x->parent->parent;
    } else {
       if( x == x->parent->right ) {
         x = x->parent;
         RotateLeft( x );
       }
    x->parent->color = 0;
    x->parent->parent->color = 1;
    RotateRight( x->parent->parent );
    } else {
      RBTreeNode<T> *uncle = x->parent->parent->left;
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
      RotateLeft(x->parent->parent);
    }
  }
}
root->color = 0;
}

//////////////////////балансировка после удалени€
template < typename T >
void DeleteFixup(rbnode <T> x) {
  while (x != root && x->color == 0) {
    if (x == x->parent->left)    {  // ”дал€емый элемент Ц корень левого поддерева
    RBTreeNode<T> *brother = x->parent->right;  
      if (brother->color == 1) {
        brother->color = 0;
        x->parent->color = 1;
        RotateLeft(x->parent);
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
          RotateLeft(x->parent);
          x = root; }
    }
    else {  // ”дал€емый элемент Ц корень правого поддерева
      RBTreeNode<T> *brother = x->parent->left;
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
           RotateLeft(brother);
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
////////////////////////////////////вставка
template < typename T >
RBTree Insert(const T& v) {
 rbnode<T> *current = root;
 rbnode<T> *parent = NULL;
 rbnode<T> *newnode; 
  while (current != NIL) {
      if (v == current->value)
        return current;
      parent = current;
      if (v < current->value)
        current = current->left;
      else
        сurrent = current->right;
    }
    newnode = new rbnode<T>(v,parent, NIL, NIL, 1);
    if (parent == NULL) {
      root = newnode;
    } else {
      if( newnode->value < parent->value ) {
       parent->left = newnode;
      } else {
        parent->right = newnode;
      }
    InsertFixup( newnode );  // балансировка
    return newnode;
 }

template < typeneme T >
RBTree Delete(const T& v) {
  rbnode<T> *x = FindNode(v);
  Delete(x);
}

rbnode<T>* Find(const T& v)  {
  rbnode<T> *current = root;
  for (;;) {
    if (current == NIL) return NULL;
    if (current->value == v)
      return current;
    if (v < current->value)
      сurrent = current->left;
    else
      current = current->right;
  }
}

void Delete( rbnode<T> *v ) {
  rbnode<T> *x, *y;
  if( v == NULL || v == NIL )
    return;

  if( v->left == NIL || v->right == NIL ) {
    y = v;
  } else {
    y = v->right;
    while( y->left != NIL ) {
      y = y->left;
    }
   }
  if( y->left != NIL )
    x = y->left;
  else
    x = y->right;
  x->parent = y->parent;
  if( y->parent != NULL ){
    if( y == y->parent->left )
      y->parent->left = x;
    else
    y->parent->right = x;
  } else
  root = x;
  if( y != v ) {
    v->value =y->value;}  
  if( y->color == 0 ) {
    DeleteFixup(x);
  }
  delete y;
  } 

#endif  // INCLUDE_ADD_H_
