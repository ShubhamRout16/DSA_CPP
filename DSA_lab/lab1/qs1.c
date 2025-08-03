#include <stdio.h>
int* createArray(int n){
  // creating array
  int arr[n];
  for(int i=0; i<n; i++){
    printf("Enter array element \n");
    scanf("%d", &arr[i]);
  }
  // displaying the array
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
void displayArray(int arr[] , int size){
  for(int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  return;
}
void  insertInArray(int arr[] , int position , int element , int size){
  for(int i = size-1; i>=1; i--){
    arr[i+1] = arr[i];
  }
  arr[position] = element;
  // array after insertion
  for(int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
}
void deleteElArray(int arr[], int position , int size){
  for(int i=position; i<size-1; i++){
    arr[i] = arr[i+1];
  }
  arr[size-1] = 0;
  // array after element deletion
  for(int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  return;
}
int linearSearch(int arr[] , int size , int element){
  int index;
  for(int i=0; i<size; i++){
    if(arr[i] == element){
      index = i;
      break;
    }
  }
  return index;
}
int main(){
  int n;
  printf("Enter the number of elements of the array \n");
  scanf("%d", &n);
  int option;
  printf("Enter the option \n");
  scanf("%d", &option);
  switch(option){
    case 1:
      // call create array function
      createArray(n);
      break;
    case 2:
      {// call display array function
      int arr[5] = {1,2,3,4,5};
      int size;
      size = sizeof(arr) / sizeof(arr[0]);
      displayArray(arr , size);
      break;}
    case 3:
      // call insert function
      {int arr2[7] = {9,5,2,5,1};
      int position;
      printf("Enter the position \n");
      scanf("%d",&position);
      int insertionEl;
      printf("Enter the element to insert\n");
      scanf("%d",&insertionEl);
      int size2;
      size2 = sizeof(arr2) / sizeof(arr2[0]);
      insertInArray(arr2 , position , insertionEl , size2);
      break;}
    case 4:
      // call delete function
      // we will only work on to delete through index
      {int arr3[5] = {9,5,2,5,1};
      // int deleteElIndex;
      // printf("Enter the to delete element index\n");
      // scanf("%d",&deleteElIndex);
      int delPosition;
      printf("Enter to delete element position\n");
      scanf("%d",&delPosition);
      int size3;
      size3 = sizeof(arr3) / sizeof(arr3[0]);
      deleteElArray(arr3 , delPosition , size3);
      break;}
    case 5:
        {
          // call linear search function
          int elFind;
          printf("Element to find\n");
          scanf("%d",&elFind);
          int arr4[5] = {1,2,3,4,5};
          int size4;
          size4 = sizeof(arr4) / sizeof(arr4[0]);
          int searchEl = linearSearch(arr4 ,size4 ,elFind);
          printf("Element found at index %d", searchEl);
        }
  }
}