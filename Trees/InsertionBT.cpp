#include<iostream>
using namespace std;

struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};

Node* Insertion(Node *t , int key){
  Node *r = nullptr , *p;

  if(t == nullptr){
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    return p ;
  }

  while(t != nullptr){
    r = t;
    if(key == t->data) return t;
    else if(key < t->data) t = t->lchild;
    else t = t->rchild;
  }
  p = new Node;
  p->data = key;
  p->lchild = p->rchild = nullptr;
  if(p->data < r->data) r->lchild = p;
  else r->rchild = p;

  return r;
}

void Inorder(Node *t){
  if(t != nullptr){
    Inorder(t->lchild);
    cout << t->data << " ";
    Inorder(t->rchild);
  }
}

Node *createSampleTree(){
  Node *root = new Node{nullptr , 30 , nullptr};
  root->lchild = new Node{nullptr , 20 , nullptr};
  root->rchild = new Node{nullptr , 40 , nullptr};
  root->lchild->lchild = new Node{nullptr , 10 , nullptr};
  root->lchild->rchild = new Node{nullptr , 25 , nullptr};
  root->rchild->lchild = new Node{nullptr , 35 , nullptr};
  root->rchild->rchild = new Node{nullptr , 50 , nullptr};
  return root;
}

int main(){
  Node *root = createSampleTree();
  int key = 38;

  cout << "Before insertion Inorder" << endl;
  Inorder(root);
  cout << endl;

  Insertion(root,key);

  cout << "After insertion inorder" << endl;
  Inorder(root);
  cout << endl;

  return 0;
}