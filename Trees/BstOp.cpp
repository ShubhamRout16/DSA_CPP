#include<iostream>
using namespace std;

// creation of BST 
// insertion in BST 
//  - iterative insertion
//  - recursive insertion
// deletion in Bst
//  - having 0 nodes , 1 nodes and more than 2 child
// successor and predecessor in Bst
// Searching in Bst
//  - iterative searching
//  - recursive searching

class Node {
  public:
  int data;
  Node* lchild ;
  Node* rchild;

  Node(int value){
    data = value;
    lchild = rchild = nullptr;
  }
};

Node* insert(Node*root , int value){
  Node* tail;
  Node* NEW;
  if(root == nullptr){
    Node* temp = new Node(value);
    return temp;
  }
  while(root != nullptr){
    tail = root;
    if(root->data > value){
      root = root->lchild;
    }
    else if(root->data < value){
      root = root->rchild;
    }
    else{
      // for duplication attach on right side
      root = root->rchild;
    }
  }
  NEW = new Node(value);
  if(NEW->data > tail->data){
    // attach to right side
    tail->rchild = NEW;
  }
  else{
    // attach to left side
    tail->lchild = NEW;
  }
  return tail;
}

Node* Rinsert(Node* root , int value){
  if(root == nullptr){
    Node* temp = new Node(value);
    return temp;
  }
  if(root->data > value){
    root->lchild = Rinsert(root->lchild,value);
  }
  else if(root->data < value){
    root->rchild = Rinsert(root->rchild,value);
  }
  else{
    root->rchild = Rinsert(root->rchild,value);
  }
  return root;
}

// to get the successor of Bst
Node* getSuccessor(Node* curr){
  curr = curr->rchild;
  while(curr != nullptr && curr->lchild != nullptr){
    curr = curr->lchild;
  }
  return curr;
}

// to get the predessor of Bst
Node* getPredecessor(Node* curr){
  curr = curr->lchild;
  while(curr != nullptr && curr->rchild != nullptr){
    curr = curr->rchild;
  }
  return curr;
}

Node* Deletion(Node* root , int value){
  if(root == nullptr){
    return root;
  }
  if(root->data > value){
    root->lchild = Deletion(root->lchild,value);
  }
  else if(root->data < value){
    root->rchild = Deletion(root->rchild,value);
  }
  else{
    // handling nodes having 0 or 1 child
    if(root->lchild == nullptr){
      Node* temp = root->rchild;
      delete root;
      return temp;
    }
    if(root->rchild == nullptr){
      Node* temp = root->lchild;
      delete root;
      return temp;
    }
    // handling node having more than 2 child using successor
    // Node* succ = getSuccessor(root);
    // root->data = succ->data;
    // root->rchild = Deletion(root->rchild,succ->data);

    // handling node having more than 2 child using predecessor
    Node* pred = getPredecessor(root);
    root->data = pred->data;
    root->lchild = Deletion(root->lchild, pred->data);
  }
  return root;
}

Node* Search(Node*root , int key){
  while(root != nullptr){
    if(root->data == key){
      return root;
    }
    else if(root->data > key){
      root = root->lchild;
    }
    else{
      root = root->rchild;
    }
  }
  return nullptr;
}

Node* Rsearch(Node*root , int key){
  if(root == nullptr){
    return nullptr;
  }
  else if(root->data == key){
    return root;
  }
  else if(root->data > key){
    return Rsearch(root->lchild,key);
  }
  else{
    return Rsearch(root->rchild,key);
  }
}
void inorder(Node* root){
  if(root != nullptr){
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
  }
}

int main(){
  int arr[] = {6,3,17,5,11,18,2,1,20,14};
  Node* root = nullptr;
  for(int i=0; i<10; i++){
    root = Rinsert(root,arr[i]);
  }
  inorder(root);
  cout << endl;
  // Deletion(root,20);
  // inorder(root);
  // cout << endl;
  // Deletion(root,3);
  // inorder(root);
  Node* result = Rsearch(root , 18);
  if(result != nullptr){
    cout << "Node found : " << result->data << endl;
  }
  else {
    cout << "Node not found" << endl;
  }
  return 0;
}