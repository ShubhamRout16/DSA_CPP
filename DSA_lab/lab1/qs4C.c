// transpose of the matrix
#include<stdio.h>
void matrixTranspose(int row , int col , int arr[row][col]){
  int t[row][col];
  // transpose matrix initialise 0
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      t[row][col] = 0;
    }
  }
  // transpose matrix logic
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      t[j][i] = arr[i][j];
    }
  }
  // print array after transpose
  printf("Transpose of Matrix A:\n");
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      printf("%d " , t[i][j]);
    }
    printf("\n");
  }
}
int main(){
  int m, n;
  printf("Enter the number of rows for matrix A: ");
  scanf("%d", &m);
  printf("Enter the number of columns for matrix A: ");
  scanf("%d", &n);
  
  int matrixA[m][n];
  // Input matrix A
  printf("Enter elements of matrix A:\n");
  for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
          scanf("%d", &matrixA[i][j]);
      }
  }
  
  // Print matrix A
  printf("Matrix A:\n");
  for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
          printf("%d ", matrixA[i][j]);
      }
      printf("\n");
  }
  matrixTranspose(m , n ,matrixA);
  return 0;
}