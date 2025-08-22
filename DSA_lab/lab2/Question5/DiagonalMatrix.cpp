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

  int diagMatrix[row];
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(i == j){
        diagMatrix[i] = arr[i][j];
      }
    }
  }

  cout << "Diagonal matrix elements are : " << endl;
  for(int i=0; i<row; i++){
    cout << diagMatrix[i] << " ";
  }
  return 0;
}