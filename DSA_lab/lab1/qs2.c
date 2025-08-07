#include <stdio.h>
#include <stdlib.h>
int isPresent(int uniqueArr[] , int uniqueInd , int value){
  for(int i=0; i<uniqueInd; i++){
    if(uniqueArr[i] == value){
      return 1;
    }
  }
  return 0;
}
int* removeDup(int arr[] , int n , int* newSize){
  // array to track unique elements from the original array
  // since we have to return unique array from function for which we will dynamically allocate memory to unique array
  // malloc returns a pointer we are type casting into a integer
  int* uniqueArrEl = (int*)malloc(n * sizeof(int));
  // to track the index of the unique array
  int uniqInd = 0;
  for(int i=0; i<n; i++){
    // logic -> to loop through original array and for each element check if present in unique array or not
    // if not present add to unique array
    if(!isPresent(uniqueArrEl , uniqInd , arr[i])){
      uniqueArrEl[uniqInd] = arr[i];
      uniqInd++;
    }
  }
  *newSize = uniqInd;
  return uniqueArrEl;
}
int main(){
  int n;
  printf("enter the number of elements for array : \n");
  scanf("%d",&n);
  int arr[n];
  // input array elements
  for(int i=0; i<n; i++){
    printf("enter array elements\n");
    scanf("%d", &arr[i]);
  }
  // show array elements before deletion
  printf("array before removing duplicate elements\n");
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  // removeDuplicate element function calling
  int newSize;
  int* arr2 = removeDup(arr , n , &newSize);
  // show array elements after deletion
  printf("array after removing duplicate elements\n");
  for(int i=0; i<newSize; i++){
    printf("%d ", arr2[i]);
  }
  // memory managament best practices 101 - clean up memory
  free(arr2);
  return 0;
}

// arr2 stores the address of the dynamically allocated array returned by functions its calling