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


int main(){
  int Arr[] = {10,20,30,40,50};
  createLL(Arr,5);
  cout << "Length of Linked List : " << LengthLL(first) << endl;
  displayLL(first);
  return 0;
}