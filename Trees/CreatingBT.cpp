// for creating a binary tree we need queue data strcuture
#include<iostream>
using namespace std;

struct Node{
  Node *lchild;
  int data;
  Node *rchild;
};

Node *root = nullptr;

struct Queue{
  int size;
  int front;
  int rear;
  Node **Q;
};

void create(Queue *q , int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q = new Node*[q->size];
}

void enqueue(Queue *q , Node *x){
  if((q->rear + 1) % q->size == q->front){
    cout << "Queue is full" << endl;
  }else{
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

Node* dequeue(Queue *q){
  Node *x = nullptr;
  if(q->front == q->rear){
    cout << "Queue is empty" << endl;
  }else{
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isEmpty(Queue q){
  return q.front == q.rear;
}

void TreeCreate(){
  struct Node *p , *t;
  int x;
  Queue q;
  create(&q,100);

  cout << "Enter root value : ";
  cin >> x;
  root = new Node;
  root->data = x;
  root->lchild = root->rchild = nullptr;
  enqueue(&q , root);

  while(!isEmpty(q)){
    p = dequeue(&q);
    cout << "Enter left child for " << p->data ;
    cin >> x;
    if(x != -1){
      Node *t = new Node;
      t->data = x;
      t->lchild = t->rchild = nullptr;
      p->lchild = t;
      enqueue(&q,t);
    }
    cout << "Enter right child for " << p->data;
    cin >> x;
    if(x != -1){
      Node *t = new Node;
      t->data = x;
      t->lchild = t->rchild = nullptr;
      p->rchild = t;
      enqueue(&q,t);
    }
  }
}

void preorder(Node *p){
  if(p != nullptr){
    cout << p->data << " ";
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void postOrder(Node *p){
  if(p != nullptr){
    preorder(p->lchild);
    preorder(p->rchild);
    cout << p->data << " ";
  }
}

void Inorder(Node *p){
  if(p != nullptr){
    preorder(p->lchild);
    cout << p->data << " ";
    preorder(p->rchild);
  }
}

int main(){
  TreeCreate();
  cout << "Pre order traversal" << endl;
  preorder(root);
  cout << "In order traversal" << endl;
  Inorder(root);
  cout << "Post order traversal" << endl;
  postOrder(root);
  return 0;
}