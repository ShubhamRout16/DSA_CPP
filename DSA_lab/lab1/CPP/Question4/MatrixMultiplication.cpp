#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> matrixMultiplication(vector<vector<int>> &matrixA , vector<vector<int>> &matrixB){
  int rowsA = matrixA.size();
  int columnsA = matrixA[0].size();
  int columnsB = matrixB[0].size();

  vector<vector<int>> result(rowsA , vector<int>(columnsB , 0));

  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsB; j++){
      for(int k=0; k<columnsA; k++){
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
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
  int rowsB , columnsB;
  cout << "Enter number of rows for matrix B : " << endl;
  cin >> rowsB;
  cout << "Enter number of columns for matrix B : " << endl;
  cin >> columnsB;

  if(rowsB != columnsA){
    cout << "Matrix multiplication is not possible" << endl;
    return 0;
  }
  
  vector<vector<int>> matrixA(rowsA , vector<int>(columnsA));
  vector<vector<int>> matrixB(rowsB , vector<int>(columnsB));

  cout << "Enter matrixA elements : " << endl;
  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsA; j++){
      cin >> matrixA[i][j];
    }
  }
  cout << "Enter matrixB elements : " << endl;
  for(int i=0; i<rowsB; i++){
    for(int j=0; j<columnsB; j++){
      cin >> matrixB[i][j];
    }
  }

  vector<vector<int>> result = matrixMultiplication(matrixA , matrixB);

  cout << "Resultant matrix is : " << endl;
  for(int i=0; i<rowsA; i++){
    for(int j=0; j<columnsB; j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}