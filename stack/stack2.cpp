#include<iostream>
using namespace std;

class Node{
  Node *top;
  public:
  int data;
  Node *next;
  void push(int x){};
  int pop(){};
  int peek(int pos){};
  int stackTop(){};
  int isEmpty(){};
  int isFull() {};
};

void Node :: push(int x){
  Node *t = new Node;
  if(t == NULL){
    cout << "Stack overflow" << endl;
  }
  else{
    t->data = x;
    t->next = top;
    top = t;
  }
};


int Node :: pop(){
  Node *p;
  int x = -1;
  if(top == NULL) cout << "Stack underflow" << endl;
  else{
    p = top;
    top = top->next;
    x = p->data;
    delete p;
  }
  return x;
}

int Node :: peek(int pos){
  Node *p = top;
  for(int i=0; i<pos-1; i++){
    p = p->next;
  }
  if(p != NULL) return p->data;
  else return -1;
}

int Node :: stackTop(){
  if(top != NULL){
    return top->data;
  }
  else return -1;
}

int Node :: isEmpty(){
  if(top == NULL) return 1;
  else return 0;
}

int Node :: isFull(){
  Node *t = new Node;
  if(t = NULL) return 1;
  else return 0;
}

int main(){
  return 0;
}

/*
----------- Stack condition -------------
if(top == NULL) then its empty
Node *t = new Node; if(t == NULL) then its full
*/