#include<iostream>
#include<vector>
using namespace std;
vector<int> pascalTriangleVar2M2(int rows){
  // for every row , each has row number of elements in it
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(ans);
  for(int i=1; i<rows; i++){
    ans = ans * (rows-i);
    ans = ans / i;
    ansRow.push_back(ans);
  }
  return ansRow;
}
int main(){
  int N;
  cout << "Enter row number : " << endl;
  cin >> N;
  vector<int> result = pascalTriangleVar2M2(N);
  for(int val : result){
    cout << val << " ";
  }
  return 0;
}