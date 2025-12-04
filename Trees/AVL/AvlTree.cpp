#include<iostream>
using namespace std;

class Node {
  public:
  Node *lchild;
  Node *rchild;
  int data;
  int height;
};
Node *root = nullptr;

int NodeHeight(Node *p){
  int hl , hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl > hr ? hl+1 : hr+1;
}

int BalanceFactor(Node *p){
  int hl , hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl - hr;
}

Node * LLRotation(Node *p){
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;

  // calculate new height of p and pl , plr remains unchanged
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  if (root == p){
    root = pl;
  }
  return pl;
}

Node * LRRotation(Node *p){
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;

  // calculate new height after rotation
  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  if(root == p){
    root = plr;
  }
  return plr;
}

Node * RRRotation(Node *p){
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  pr->lchild = p;
  p->rchild = prl;

  // calculate height changes after rotations
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);

  if(root == p){
    root = pr;
  }
  return pr;
}

Node * RLRotation(Node *p){
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  p->rchild = prl->lchild;
  pr->lchild = prl->rchild;
  prl->lchild = p;
  prl->rchild = pr;

  // calculate height changes
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);
  prl->height = NodeHeight(prl);

  if(root == p){
    root = prl;
  }
  return prl;
}

Node *RInsert(Node *p , int key){
  Node *t = nullptr;
  if(p == nullptr){
    t = new Node;
    t->data = key;
    t->height = 1;
    t->lchild = t->rchild = nullptr;
    return t;
  }

  if(key < p->data){
    p->lchild = RInsert(p->lchild , key);
  }
  else if(key > p->data){
    p->rchild = RInsert(p->rchild , key);
  }
  // after every node creation we are calculating its height
  p->height = NodeHeight(p);

  if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) ==1){
    return LLRotation(p);
  }else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
    return LRRotation(p);
  }else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
    return RRRotation(p);
  }else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
    return RLRotation(p);
  }
  return p;
}

void Inorder(Node *p){
  if(p){
    Inorder(p->lchild);
    cout << p->data << " ";
    Inorder(p->rchild);
  }
}

void Preorder(Node *p){
  if(p){
    cout << p->data << " ";
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

void Postorder(Node *p){
  if(p){
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout << p->data << " ";
  }
}

int main(){
  root = RInsert(root, 10);
    root = RInsert(root, 20);
    root = RInsert(root, 30);
    root = RInsert(root, 40);
    root = RInsert(root, 50);
    root = RInsert(root, 25);

  cout << "Inorder Traversal (Sorted): ";
  Inorder(root);
  cout << endl;

  cout << "Preorder Traversal: ";
  Preorder(root);
  cout << endl;

  cout << "Postorder Traversal: ";
  Postorder(root);
  cout << endl;
  return 0;
}