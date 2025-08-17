#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> RotateMatrixBy90Opti(vector<vector<int>> &nums){
  int n = nums.size();
  // step 1 -> transposing
  // this loop runs for O(N/2 * N/2)
  for(int i=0; i<=n-2; i++){
    for(int j=i+1; j<=n-1; j++){
      swap(nums[i][j] , nums[j][i]);
    }
  }
  // step 2 -> reversing each row
  // this loop runs for O(N * N/2)
  // N/2 for reversing -> using two pointers approach
  for(int i=0; i<n; i++){
    reverse(nums[i].begin() , nums[i].end());
  }
  return nums;
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
  vector<vector<int>> result = RotateMatrixBy90Opti(nums);

  cout << "\nResultant Matrix:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
//  time complexity will be O(N) + O(N*N/2)
//  space complexity will be O(1)