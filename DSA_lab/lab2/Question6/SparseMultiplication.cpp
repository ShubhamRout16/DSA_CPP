#include<iostream>
using namespace std;
struct Triplet{
  int row , col , val;
};

void createSparseMatrix(Triplet A[] , int &rows , int &cols , int &n){
  cout << "Enter rows , cols , number of non-zero elements : ";
  cin >> rows >> cols >> n;

  A[0].row = rows;
  A[0].col = cols;
  A[0].val = n;

  cout << "Enter row , column and value of each non-zero element : " << endl;
  for(int i=1; i <= n; i++){
    cin >> A[i].row >> A[i].col >> A[i].val ;
  }
}

void printSparseMatrix(Triplet A[]){
  cout << "Row col Value" << endl;
  for(int i=1; i<=A[0].val; i++){
    cout << A[i].row  << " " << A[i].col  << " " << A[i].val  << endl;
  }
}

void multiplySparseMatrix(Triplet A[] , Triplet B[] , Triplet C[]){
  if(A[0].col != B[0].row){
    cout << "Multiplication is not possible" << endl;
    C[0].val = 0;
    return;
  }
  int k = 1;
  int rows = A[0].row , cols = B[0].col;
  int temp[50][50] = {0};

  for(int i=1; i<=A[0].val; i++){
    for(int j=1; j<=B[0].val; j++){
      if(A[i].col == B[j].row){
        temp[A[i].row][B[j].col] += A[i].val * B[j].val;
      }
    }
  }

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(temp[i][j] != 0){
        C[k].row = i;
        C[k].col = j;
        C[k].val = temp[i][j];
        k++;
      }
    }
  }

  C[0].row = rows;
  C[0].col = cols;
  C[0].val = k - 1;
}

int main(){
  Triplet A[50] , B[50] , C[50];
  int rows1 , cols1 , n1;
  int rows2 , cols2 , n2;

  cout << "Sparse Matrix : " << endl;
  createSparseMatrix(A , rows1 , cols1 , n1);

  cout << "Sparse Matrix : " << endl;
  createSparseMatrix(B , rows2 , cols2 , n2);

  multiplySparseMatrix(A ,B ,C);

  cout << "Added Sparse Matrix : " << endl;
  printSparseMatrix(C);
  return 0;
}