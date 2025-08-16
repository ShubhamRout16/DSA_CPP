#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> setMatrixZeroesBetter(vector<vector<int>> &nums){
  int rows = nums.size();
  int columns = nums[0].size();
  vector<int> col(columns , 0);
  vector<int> row(rows , 0);
  // this loop runs for O(N*M)
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
      if(nums[i][j] == 0){
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  // this loop runs for O(N*M)
  for(int i =0; i<rows; i++){
    for(int j=0; j<columns; j++){
      if(row[i] || col[j]){
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
// time complexity will be O(2*N*M)
// space complexity will be O(N) + O(M)