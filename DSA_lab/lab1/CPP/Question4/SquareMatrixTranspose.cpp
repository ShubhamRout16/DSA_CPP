#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> transposeMatrix(vector<vector<int>> &matrixA){
  int rowsA = matrixA.size();
  int columnsA = matrixA[0].size();

  for(int i=0; i<=columnsA-2 ; i++){
    for(int j=i+1; j<=columnsA-1; j++){
      swap(matrixA[i][j] , matrixA[j][i]);
    }
  }

  return matrixA;
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

  cout << "Resultant matrix : " << endl;
  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsA; j++){
      cout << matrixA[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
// better time complexity for transpose of square matrix -> in place method -> but only for square matrices
// O(n/2)