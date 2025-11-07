#include<iostream>
using namespace std;

struct Node{
  Node*lchild;
  int data;
  Node*rchild;
};

Node* root = nullptr;

void Insert(int key){
  Node *t = root;
  Node *r , *p;
  if(root == nullptr){
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    root = p;
    return;
  }
  while(t != nullptr){
    r = t;
    if(key < t->data) t = t->lchild;
    else if(key > t->data) t = t->rchild;
    else return;
  }
  p = new Node;
  p->data = key;
  p->lchild = p->rchild = nullptr;
  if(key < r->data) r->lchild = p;
  else r->rchild = p;
}

void Inorder(Node *t){
  if(t != nullptr){
    Inorder(t->lchild);
    cout << t->data << " ";
    Inorder(t->rchild);
  }
}

int main(){
  Insert(10);
  Insert(8);
  Insert(12);
  Insert(20);
  Insert(2);
  Inorder(root);
  return 0;
}