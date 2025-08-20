#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> transposeMatrix(vector<vector<int>> &matrixA){
  int rowsA = matrixA.size();
  int columnsA = matrixA[0].size();

  vector<vector<int>> result(columnsA , vector<int>(rowsA));

  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsA; j++){
      result[j][i] = matrixA[i][j];
    }
  }

  return result;
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

  vector<vector<int>> result = transposeMatrix(matrixA);
  // matrix row and columns might change after transpose
  int row = result.size();
  int column = result[0].size();
  cout << "Resultant matrix : " << endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}