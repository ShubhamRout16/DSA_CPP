#include<iostream>
using namespace std;

struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};

struct Stack{
  int size;
  int top;
  Node **S;
};

void create(Stack *st , int size){
  st->size = size;
  st->top = -1;
  st->S = new Node*[st->size];
}

void push(Stack *st , Node *x){
  if(st->top == st->size - 1){
    cout << "Stack overflow" << endl;
  }else{
    st->top++;
    st->S[st->top] = x;
  }
}

Node* pop(Stack *st){
  Node *x = nullptr;
  if(st->top == -1){
    cout << "Stack underflow" << endl;
  }else{
    x = st->S[st->top--];
  }
  return x;
}

int isEmpty(Stack st){
  return st.top == -1;
}

void preOrder(Node *t){
  Stack st;
  create(&st,100);

  while(t != nullptr || !isEmpty(st)){
    if(t != nullptr){
      cout << t->data << " ";
      push(&st,t);
      t = t->lchild;
    }else{
      t = pop(&st);
      t = t->rchild;
    }
  }
}

Node *createSampleTree(){
  Node *root = new Node{nullptr , 10 , nullptr};
  root->lchild = new Node{nullptr , 20 , nullptr};
  root->rchild = new Node{nullptr , 30 , nullptr};
  root->lchild->lchild = new Node{nullptr , 40 , nullptr};
  root->lchild->rchild = new Node{nullptr , 50 , nullptr};
  root->rchild->lchild = new Node{nullptr , 60 , nullptr};
  root->rchild->rchild = new Node{nullptr , 70 , nullptr};
  return root;
}

int main(){
  Node *root = createSampleTree();
  cout << "Iterative Preorder traversal" << endl;
  preOrder(root);
  cout << endl;
  return 0;
}