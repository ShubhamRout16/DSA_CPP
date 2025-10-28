#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *prev;
  Node *next;

  Node(int value){
    data = value;
    prev = nullptr;
    next = nullptr;
  }
};

Node *first = nullptr;

// arr[] -> numbers of linked lists
// n -> number of nodes
void createLL(int arr[] , int n){
  Node *t , *last;
  first = new Node(arr[0]);
  last = first;

  for(int i=1; i<n; i++){
    t = new Node(arr[i]);
    t->prev = last;
    last->next = t;
    last = t; 
  }
}

void displayLL(Node *p){
  while(p != nullptr){
    cout << p->data << endl;
    p = p->next;
  }
}

int LengthLL(Node *p){
  int len = 0;

  while(p != nullptr){
    len++;
    p = p->next;
  }
  return len;
}

// index -> where we want to insert
// x -> the value we want to insert
void insertInLL(Node *p , int index , int x){
  Node *t;

  if(index < 0 || index > LengthLL(p)){
    return;
  }
  if(index == 0){
    // special case where there is only one node present
    t = new Node(x);
    t->prev = nullptr;
    t->next = first;
    first->prev = t;
    first = t;
  }
  else{
    for(int i=0; i<index-1; i++){
      p = p->next;
    }
    t = new Node(x);
    t->next = p->next;
    t->prev = p;
    if(p->next != nullptr){
      p->next->prev = t;
    }
    p->next = t;
  }
}

void deleteInLL(Node *p , int index){
  Node *q;
  int x = -1;
  if(index < 1 || index > LengthLL(p)) return ;
  if(index == 1){
    // if its the first index
    first = first->next;
    if(first != nullptr){
      first->prev = nullptr;
    }
    x = p->data;
    delete p;
  }
  else{
    for(int i=0; i<index-1; i++){
      p = p->next;
    }
    p->prev->next = p->next;
    if(p->next != nullptr){
      p->next->prev = p->prev;
    }
    x = p->data;
    delete p;
  }
}

int main(){
  int Arr[] = {10,20,30,40,50};
  createLL(Arr,5);
  insertInLL(first,0,25);
  cout << "Length of Linked List : " << LengthLL(first) << endl;
  displayLL(first);
  cout << endl;
  deleteInLL(first,1);
  displayLL(first);
  cout << endl;
  deleteInLL(first,5);
  displayLL(first);
  return 0;
}