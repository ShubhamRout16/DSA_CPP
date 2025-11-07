#include<iostream>
using namespace std;

struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};

Node *RInsertion(Node *p , int key){
  Node *t;
  if(p == nullptr){
    t = new Node;
    t->data = key;
    t->lchild = t->rchild = nullptr;
    return t;
  }
  if(key < p->data){
    p->lchild = RInsertion(p->lchild,key);
  }
  else if(key > p->data){
    p->rchild = RInsertion(p->rchild,key);
  }
  return p;
}

void Inorder(Node *t){
  if(t != nullptr){
    Inorder(t->lchild);
    cout << t->data << " ";
    Inorder(t->rchild);
  }
}

int main(){
  Node *root = nullptr;
  root = RInsertion(root,30);
  Inorder(root);
  cout << endl;
  root = RInsertion(root,20);
  Inorder(root);
  cout << endl;
  root = RInsertion(root,25);
  Inorder(root);
  cout << endl;
  return 0;
}