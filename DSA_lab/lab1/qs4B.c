//  find the matrix multiplication
#include<stdio.h>

void multiply(int row1 , int col1 , int col2 , int matrixA[row1][col1] , int matrixB[col1][col2]) {
    int result[row1][col2];
    // initialize the result array with zeroes
    for(int i=0; i<row1; i++){
      for(int j=0; j<col2; j++){
        result[i][j] = 0;
      }
    }

    // multiplication of both 2D arrays
    for(int i=0; i<row1; i++){
      for(int j=0; j<col2; j++){
        for(int k=0; k<col1; k++){
          result[i][j] += matrixA[i][k] * matrixB[k][j];
        }
      }
    }

    // print the multiplication arrays
    for(int i=0; i<row1; i++){
      for(int j=0; j<col2; j++){
        printf("%d " , result[i][j]);
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
    
    int x, p;
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &x);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &p);
    
    int matrixB[x][p];
    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < p; j++){
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    // Print matrix B
    printf("Matrix B:\n");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < p; j++){
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
    
    // Check if multiplication is possible
    if(n != x) {
        printf("Matrix multiplication not possible! Number of columns of A must equal number of rows of B.\n");
        return 0;
    }
    
    multiply(m , n , p , matrixA , matrixB);
    return 0;
}

// important points while passing 2dimesion array to the function
// -> must specify the column size of 2d
// variable length array