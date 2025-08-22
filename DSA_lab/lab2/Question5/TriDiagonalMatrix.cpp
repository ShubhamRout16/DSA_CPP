#include<iostream>
using namespace std;
int main(){
  int row;
  cout << "Enter number of rows : " << endl;
  cin >> row;
  int column;
  cout << "Enter number of columns : " << endl;
  cin >> column;
  int arr[row][column];

  cout << "Enter matrix elements : " << endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      cin >> arr[i][j];
    }
  }

  cout << endl;

  cout << "Current matrix elements are : " << endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  // for storing matrix diagonal elements
  int diagMatrix[row];
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(i == j){
        diagMatrix[i] = arr[i][j];
      }
    }
  }

  // defining and initialising the array for storing upperPart of the matrix to be 0
  int upperPart[row-1];
  for(int i=0; i<row-1; i++){
    upperPart[i] = 0;
  }

  // logic for storing the upper part of the matrix
  for(int i=0; i<=row-2; i++){
    for(int j=row-1; j>0; j++){
      upperPart[i] = arr[i][i+1];
    }
  }
  
  // defining and initialising the array for storing the lowerPart of the matrix to be 0
  int lowerPart[row-1];
  for(int i=0; i<row-1; i++){
    lowerPart[i] = 0 ;
  }

  // logic for storing the lower part of the matrix
  for(int i=row-1; i>0; i--){
    for(int j=0; j<=row-1; j++){
      lowerPart[j] = arr[j+1][j];
    }
  }

  cout << "Diagonal matrix elements are : " << endl;
  for(int i=0; i<row; i++){
    cout << diagMatrix[i] << " ";
  }

  cout << endl;

  cout << "Upper part of triDiagonal Matrix : " << endl;
  for(int i=0; i<row-1; i++){
    cout << upperPart[i] << " ";
  }

  cout << endl;

  cout << "Lower part of the triDiagonal matrix : " << endl;
  for(int i=0; i<row-1; i++){
    cout << lowerPart[i] << " ";
  }
  return 0;
}