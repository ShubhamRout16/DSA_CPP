#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralMatrixOpti(vector<vector<int>> &nums){
  int n = nums.size();
  int m = nums[0].size();
  vector<int> ans;
  int top = 0; 
  int bottom = n - 1;
  int left = 0;
  int right = m - 1;
  while(left <= right && top <= bottom){
    // 1st movement -> left to right
    for(int i=left; i<=right; i++){
      ans.push_back(nums[top][i]);
    }
    top++;
    // 2nd movement -> top to bottom
    for(int i=top; i<=bottom; i++){
      ans.push_back(nums[i][right]);
    }
    right--;
    if(top <= bottom){
      // 3rd movement -> right to left
      for(int i=right; i>=left; i--){
        ans.push_back(nums[bottom][i]);
      }
      bottom--;
    }
    if(left <= right){
      // 4th movement -> bottom to top
      for(int i=bottom; i>=top; i--){
        ans.push_back(nums[i][left]);
      }
      left++;
      }
  }
  return ans;
}
int main(){
  int rows;
  cout << "Enter no of rows." << endl;
  cin >> rows;
  int columns;
  cout << "Enter no of Columns." << endl;
  cin >> columns;
  vector<vector<int>> nums(rows , vector<int>(columns));
  cout << "Enter matrix elements row by row." << endl;
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
      cin >> nums[i][j];
    }
  }
  vector<int> result = spiralMatrixOpti(nums);

  cout << "\nSpiral Order Traversal:\n";
  for (int val : result) {
      cout << val << " ";
  }
  cout << endl;
  return 0;
}
//  time complexity will be O(N * M)
//  space complexity will be O(N) -> we are using extra 1D array to store the output