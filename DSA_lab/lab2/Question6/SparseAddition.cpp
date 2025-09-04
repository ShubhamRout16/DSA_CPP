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

void addSparseMatrix(Triplet A[] , Triplet B[] , Triplet C[]){
  if (A[0].row != B[0].row || A[0].col != B[0].col){
    cout << "Addition is not possible." << endl;
    C[0].val = 0;
    return;
  }

  int i = 1 , j = 1 , k = 1;
  int n1 = A[0].val , n2 = B[0].val ;

  while (i <= n1 && j <= n2){
    if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)){
      C[k++] = A[i++];
    }
    else if(B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)){
      C[k++] = B[j++];
    }
    else{
      C[k].row = A[i].row;
      C[k].col = A[i].col;
      C[k].val = A[i].val + B[j].val ;
      k++; i++; j++;
    }
  }

  while(i <=n1) C[k++] = A[i++];
  while(j <=n2) C[k++] = B[j++];

  C[0].row = A[0].row;
  C[0].col = A[0].col;
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

  addSparseMatrix(A ,B ,C);

  cout << "Added Sparse Matrix : " << endl;
  printSparseMatrix(C);
  return 0;
}