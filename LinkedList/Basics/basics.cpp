#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
};

class linkedList{
  private:
  Node *first;
  public:
    linkedList(){
      first = NULL;
    }
    linkedList(int A[] , int n){

    }
    ~linkedList(){};

    void display(){

    }

    void insert(int index , int x){

    }

    int Delete(int index){

    }


    int Length(){

    }
};

linkedList :: linkedList(int A[] , int n){
  Node *last , *t;
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for(int i=1 ; i<n; i++){
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

linkedList::~linkedList(){
  Node *p = first;
  while(first){
    first = first->next;
    delete p;
    p = first;
  }
}

void linkedList::display(){
  Node *p = first;
  while(p != NULL){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int linkedList::Length(){
  Node *p = first;
  int len = 0;
  while(p != NULL){
    len++;
    p = p->next;
  }
  return len;
}

void linkedList::insert(int index, int x){
  Node *t , *p = first;

  if(index < 0 || index > Length()) return;

  t = new Node;
  t->data = x;
  t->next = NULL;

  if(index == 0){
    first = t;
  }
  else{
    for(int i=0; i<index-1; i++){
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

int linkedList::Delete(int index){
  Node *p , *q = NULL;
  int x = -1;
  if(index < 1 || index > Length()) return -1;
  if(index == 1){
    p = first;
    first = first->next;
    x = p->data;
    delete p;
  }
  else{
    p = first;
    for(int i=0; i<index-1; i++){
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
  }
  return x;
}

int main(){
  int A[] = {1,2,3,4,5};
  linkedList l(A,5);
  l.display();
  return 0;
}