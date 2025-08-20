#include<iostream>
#include<vector>
using namespace std;
void sumOfRowAndColumns(vector<vector<int>> &matrixA){
  int row = matrixA.size();
  int column = matrixA[0].size();

  for(int i=0; i<row; i++){
    int rowSum = 0;
    for(int j=0; j<column; j++){
      rowSum += matrixA[i][j];
    }
    cout << "Sum of " << i+1 << "th row is " << rowSum << endl;
  }
  
  cout << endl;

  for(int i=0; i<column; i++){
    int colSum = 0;
    for(int j=0; j<row; j++){
      colSum += matrixA[j][i];
    }
    cout << "Sum of " << i+1 << "th column is " << colSum << endl;
  }

}
int main(){
  int rowsA , columnsA;
  cout << "Enter number of rows for matrix A : " << endl;
  cin >> rowsA;
  cout << "Enter number of columns for matrix A : " << endl;
  cin >> columnsA;
  
  vector<vector<int>> matrixA(rowsA , vector<int>(columnsA));

  cout << "Enter matrixA elements : " << endl;
  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsA; j++){
      cin >> matrixA[i][j];
    }
  }
  sumOfRowAndColumns(matrixA);

  return 0;
}