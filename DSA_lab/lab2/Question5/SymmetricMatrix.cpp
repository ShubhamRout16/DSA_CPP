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

  // check if the current matrix is symmetric matrix or not
  int count = 0;
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(arr[i][j == arr[j][i]]){
        count++;
      }
    }
  }
  if(count == row){
    cout << "Current matrix is symmetric matrix" << endl;
  }

  // for storing matrix diagonal elements
  int diagMatrix[row];
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(i == j){
        diagMatrix[i] = arr[i][j];
      }
    }
  }

  // defining and initialising the array for storing the lowerPart of the matrix to be 0
  int size = (row * (row+1)/2) / 2; // formula for calculating the number of elements below diagonal since size gives the total number of symmetric elements below and upper in the symmetric matrix 
  int upperPart[size];
  // cout << size ; 
  int lowerPart[size];
  int lowerArrIndx = 0;
  int upperArrIndx = 0;
   
  // logic for storing the upper part of the matrix
  for(int i=0; i<=row-1; i++){
    for(int j=0; j<i; j++){
      upperPart[upperArrIndx] = arr[j][i];
      upperArrIndx++;
    }
  }

  // logic for storing the lower part of the matrix
  for(int i=0; i<=row-1; i++){
    for(int j=0; j<i; j++){
      lowerPart[lowerArrIndx] = arr[i][j];
      lowerArrIndx++;
    }
  }

  cout << "Diagonal matrix elements are : " << endl;
  for(int i=0; i<row; i++){
    cout << diagMatrix[i] << " ";
  }

  cout << endl;

  cout << "Upper part of the symmetric matrix : " << endl;
  for(int i=0; i<size; i++){
    cout << upperPart[i] << " ";
  }

  cout << endl;
  cout << "Lower part of the symmetric matrix : " << endl;
  for(int i=0; i<size; i++){
    cout << lowerPart[i] << " ";
  }
  return 0;
}