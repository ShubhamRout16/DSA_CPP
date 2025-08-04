// write a program to find sum of every row and column in a 2d array
#include<stdio.h>
void RowAndColumnSum(int row1 , int col1, int arr1[row1][col1]){
  // find the sum of every row
  int rowSum = 0;
  for(int i=0; i<row1; i++){
    for(int j=0; j<col1; j++){
      rowSum += arr1[i][j]; 
    }
  }
  printf("sum of every row is %d\n",rowSum);

  // find the sum of every column
  int colSum = 0;
  for(int i=0; i<col1; i++){
    for(int j=0; j<row1; j++){
      colSum += arr1[i][j];
    }
  }
  printf("sum of every column is %d\n",colSum);
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
    RowAndColumnSum(m , n, matrixA);
  return 0;
}