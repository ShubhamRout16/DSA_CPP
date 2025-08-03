// reverse the elements of an array
// brute force - using extra array
#include<stdio.h>
void reverseArray(int arr[] , int n){
  int reversedArray[n];
  for(int i=0; i<n; i++){
      reversedArray[i] = arr[n - i - 1];
  }
  // print reversed array
  printf("reversed array.\n");
  for(int i=0; i<n; i++){
    printf("%d " , reversedArray[i]);
  }
}
// without using extra array
void reverseArray2(int arr[] , int n){
  int start = 0;
  int end = n - 1;
  while (start < end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }

  printf("the reversed array.\n");
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
  }
}
int main(){
  int n;
  printf("enter the size of array.\n");
  scanf("%d", &n);
  int arr[n];
  for(int i=0; i<n; i++){
    printf("enter array elements.\n");
    scanf("%d", &arr[i]);
  }
  reverseArray(arr , n);
  printf("\n");
  reverseArray2(arr , n);
  return 0;
}

// 2nd  method is more memory efficient 
// because first method creates a array of n integers
// and second emthod only create 1 variable which is 1 integer