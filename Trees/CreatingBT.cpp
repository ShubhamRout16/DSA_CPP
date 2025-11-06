// for creating a binary tree we need queue data strcuture
#include<iostream>
using namespace std;

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(Queue *q , int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q = new int[q->size];
}

void enqueue(Queue *q , int x){
  if((q->rear + 1) % q->size == q->front){
    cout << "Queue is full" << endl;
  }else{
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

int dequeue(Queue *q){
  int x = -1;
  if(q->front == q->rear){
    cout << "Queue is empty" << endl;
  }else{
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

int main(){
  Queue q;
  int size;

  cout << "Enter the size of queue : " << endl;
  cin >> size;
  create(&q , size);
  enqueue(&q , 10);
  enqueue(&q , 20);
  enqueue(&q , 30);
  cout << "Dequeued element is : " << dequeue(&q) << endl;
  delete [] q.Q;
  return 0;
}