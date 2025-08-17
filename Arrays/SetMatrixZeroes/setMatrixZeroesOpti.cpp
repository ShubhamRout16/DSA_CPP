#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> setMatrixZeroesBetter(vector<vector<int>> &nums){
  int rows = nums.size();
  int columns = nums[0].size();
  // vector<int> col(columns , 0); -> row[0] -> matrix[0][..]
  // vector<int> row(rows , 0); -> col[0] -> matrix[..][0]
  // step1 -> marking
  int col0 = 1;
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){ 
      if(nums[i][j] == 0){
        // mark the i-th row
        nums[i][0] = 0;
        // mark the j-th col
        if(j != 0){
          nums[0][j] = 0;
        }
        else{
          col0 = 0;
        }
      }
    }
  }
  // step 2 -> iterating through matrix but ignoring 0-th row & col
  for(int i=1; i<rows; i++){
    for(int j=1; j<columns; j++){
      if(nums[i][j] != 0){
        // check if i-th row and j-th col is marked or not
        if(nums[i][0] == 0 || nums[0][j] == 0){
          nums[i][j] = 0;
        }
      }
    }
  }

  // 0-th row depends on nums[0][0] if its 0 then 0-th row is completely zero
  if(nums[0][0] == 0){
    for(int j=0; j<columns; j++){
      nums[0][j] = 0;
    }
  }
  // 0-th column depends on col0 if its 0 then the 0-th column is completely zero
  if(col0 == 0){
    for(int i=0; i<rows; i++){
      nums[i][0] = 0;
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
  vector<vector<int>> result = setMatrixZeroesBetter(nums);

  cout << "\nResultant Matrix:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
// time complexity will be -> O(2*(N*M))
// space complexity will be -> O(1) -> we are not using any extra space -> we are just using a extra variable