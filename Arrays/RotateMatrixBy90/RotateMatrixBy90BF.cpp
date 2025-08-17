#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> RotateMatrixBy90BF(vector<vector<int>> &nums){
  int n = nums.size();
  vector<vector<int>> ans(n , vector<int>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ans[j][(n-i) - 1] = nums[i][j];
    }
  }
  return ans;
}
int main(){
  int n;
  cout << "Enter size of square matrix (n)." << endl;
  cin >> n;
  vector<vector<int>> nums(n , vector<int>(n));
  cout << "Enter matrix elements row by row." << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> nums[i][j];
    }
  }
  vector<vector<int>> result = RotateMatrixBy90BF(nums);

  cout << "\nResultant Matrix:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
// time complexity will be -> O(n^2)
// space complexity will be -> O(n^2)