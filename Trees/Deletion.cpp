#include<iostream>
using namespace std;

struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};
Node *root = nullptr;
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

int Height(Node *p){
  int x , y;
  if(p == nullptr) return 0;
  Height(p->lchild);
  Height(p->rchild);
  return x>y ? x+1 : y+1;
}

Node * InPre(Node *p){
  while(p && p->rchild!= nullptr){
    p = p->rchild;
  }
  return p;
}

Node * InSucc(Node *p){
  while(p && p->lchild != nullptr){
    p = p->rchild;
  }
  return p;
}

Node * Delete(Node *p , int key){
  Node *q;
  if(p == nullptr) return nullptr;
  if(p->lchild == nullptr && p->rchild == nullptr){
    if(p == root) root = nullptr;
    delete p;
    return nullptr;
  }

  if(key < p->data) Delete(p->lchild , key);
  else if(key > p->data) Delete(p->rchild , key);
  else {
    if(Height(p->lchild) > Height(p->rchild)){
      q=InPre(p->lchild);
      p->data = q->data;
      p->lchild = Delete(p->lchild,q->data);
    }
    else{
      q=InSucc(p->rchild);
      p->data = q->data;
      p->rchild = Delete(p->rchild,q->data);
    }
  }
  return p;
}

int main(){
  root = RInsertion(root,50);
  Inorder(root);
  cout << endl;
  root = RInsertion(root,10);
  Inorder(root);
  cout << endl;
  root = RInsertion(root,40);
  Inorder(root);
  cout << endl;
  root = RInsertion(root,20);
  root = RInsertion(root,30);
  Delete(root,50);
  Inorder(root);
  cout << endl;
  return 0;
}