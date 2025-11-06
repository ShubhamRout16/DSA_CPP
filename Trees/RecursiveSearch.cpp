#include<iostream>
using namespace std;
struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};

Node *RSearch(Node *t , int key){
  if (t == nullptr) return nullptr;
  if (key == t->data) return t;
  if (key < t->data) return RSearch(t->lchild, key);
  else return RSearch(t->rchild , key);
}

Node *createSampleTree(){
  Node *root = new Node{nullptr , 10 , nullptr};
  root->lchild = new Node{nullptr , 5 , nullptr};
  root->rchild = new Node{nullptr , 20 , nullptr};
  root->lchild->lchild = new Node{nullptr , 3 , nullptr};
  root->lchild->rchild = new Node{nullptr , 7 , nullptr};
  root->rchild->lchild = new Node{nullptr , 15 , nullptr};
  root->rchild->rchild = new Node{nullptr , 25 , nullptr};
  return root;
}

int main(){
  int key = 15;
  Node *root = createSampleTree();
  Node *result = RSearch(root,key);
  if(result != nullptr){
    cout << "Found : " << result->data << endl;
  }else{
    cout << "Not found." << endl;
  }
  return 0;
}