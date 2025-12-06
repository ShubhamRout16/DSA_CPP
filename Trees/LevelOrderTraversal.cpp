#include<iostream>
#include<queue>
using namespace std;

class Node {
  public:
  int data;
  Node *lchild;
  Node *rchild;
  Node(int value){
    data = value;
    lchild = rchild = nullptr;
  }
};

vector<vector<int>> levelOrder(Node *root){
  if (root == nullptr) return {};
  vector<vector<int>> res;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int len = q.size();
    vector<int> level;
    res.push_back({});
    for(int i=0; i<len; i++){
      Node *curr = q.front();
      q.pop();
      level.push_back(curr->data);
      if(curr->lchild != nullptr){
        q.push(curr->lchild);
      }
      if(curr->rchild != nullptr){
        q.push(curr->rchild);
      }
    }
    res.push_back(level);
  }
  return res;
}

int main(){
  Node *root = new Node(5);
  root->lchild = new Node(12);
  root->rchild = new Node(13);

  root->lchild->lchild = new Node(7);
  root->lchild->rchild = new Node(14);

  root->rchild->rchild = new Node(2);

  root->lchild->lchild->lchild = new Node(17);
  root->lchild->lchild->rchild = new Node(23);

  root->lchild->rchild->lchild = new Node(27);
  root->lchild->rchild->rchild = new Node(3);

  root->rchild->rchild->lchild = new Node(8);
  root->rchild->rchild->rchild = new Node(11);


  vector<vector<int>> result = levelOrder(root);

  for(auto & lvl : result){
    for (int val : lvl) cout << val << " ";
    cout << endl;
  }
  return 0;
}