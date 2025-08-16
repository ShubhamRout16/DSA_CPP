#include<iostream>
#include<vector>
using namespace std;
void markRow(vector<vector<int>> &nums , int i){
for(int j=0; j<nums[i].size(); j++){
  if(nums[i][j] != 0){
    nums[i][j] = -1 ;
  }
}
}
void markColumn(vector<vector<int>> &nums , int j){
for(int i=0; i<nums.size(); i++){
  if(nums[i][j] != 0){
    nums[i][j] = -1 ;
  }
}
}
vector<vector<int>> setMatrixZeroesBF(vector<vector<int>> &nums){
  // step 1
  for(int i=0; i<nums.size(); i++){
    for(int j=0; j<nums[i].size(); j++){
      if(nums[i][j] == 0){
        markRow(nums , i); // this traverses for M
        markColumn(nums , j); // this traverses for N
      }
    }
  }
  // step 3
  for(int i=0; i<nums.size(); i++){
    for(int j=0; j<nums[i].size(); j++){
      if(nums[i][j] == -1){
        nums[i][j] = 0;
      }
    }
  }

  return nums;
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
  vector<vector<int>> result = setMatrixZeroesBF(nums);

  cout << "\nResultant Matrix:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
// time complexity will be O(N*M) * O(N+M) + O(N*M)
// space complexity will be O(1) -> not using any extra space 