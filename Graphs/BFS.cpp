#include<iostream>
using namespace std;

// queue for breadth first search
class Node {
  public:
  Node *next;
  int data;
};
Node *front = nullptr;
Node *rear = nullptr;

void enqueue(int x){
  Node *t = new Node;
  // new memory allocation failed
  if(t == nullptr){
    cout << "Queue is full" << endl;
  }else{
    t->data = x;
    t->next = nullptr;
    // if queue is empty
    if(front == nullptr){
      front = rear = t;
    }else{
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue(){
  int x = -1;
  Node *t;
  if (front == nullptr){
    cout << "Queue is empty" << endl;
  }else{
    x = front->data;
    t = front;
    front = front->next;
    free(t);
  }
  return x;
}

int isEmpty(){
  return front == nullptr;
}

void BFS(int G[][7] , int start , int n){
  int i = start;
  int visited[7] = {0};
  cout << i << endl;
  visited[i] = 1;
  enqueue(i);
  while(!isEmpty()){
    i = dequeue();
    for(int j=1; j<n; j++){
      if(G[i][j] == 1 && visited[j] == 0){
        cout << j << endl;
        visited[j] = 1;
        enqueue(j);
      }
    }
  }
}

void DFS(int G[][7] , int start , int n){
  int i = start;
  int visited[7] = {0};
  if (visited[i] == 0){
    cout << i << endl;
    visited[i] = 1;
    for(int j=1; j<n; j++){
      if(G[i][j] == 1 && visited[j] == 0){
        DFS(G,j,n);
      }
    }
  }
}
int main(){
  int G[7][7] = {
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
  };
  BFS(G,4,7);
  return 0;
}