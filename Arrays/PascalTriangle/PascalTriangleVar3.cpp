#include<iostream>
#include<vector>
using namespace std;
vector<int> generateRow(int row){
  long long ans = 1;
  vector<int> ansRow ;
  ansRow.push_back(1);
  for(int i=1; i<row; i++){
    ans = ans * (row - i);
    ans = ans / i;
    ansRow.push_back(ans);
  }
  return ansRow;
}
vector<vector<int>> pascalTriangleVar3(int N){
  vector<vector<int>> ans;
  for(int i=1; i<=N; i++){
    vector<int> temp = generateRow(i);
    ans.push_back(temp);
  }
  return ans;
}
int main(){
  int N;
  cout << "Enter N : " << endl;
  cin >> N;
  vector<vector<int>> result = pascalTriangleVar3(N);

  cout << "Pascal triangle will be" << endl;
  for(auto &row : result){
    for(auto &val : row){
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
// time complexity will be -> O(N^2) -> for generating row we were taking O(N) and for every column O(N)
// space complexity will be -> O(1) -> we are only using space for storing the answer.