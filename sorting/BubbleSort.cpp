#include<iostream>
using namespace std;

// Bubble sort algorithm follows the pushing of maximum element to the last of the array by adjacent swapping
// time complexity ?
// O(N^2) for the worst case and average case
// O(N) for the best case
void BubbleSort(int arr[] , int n){
  for(int i=n-1; i>=0; i--){
    int didSwap = 0;
    for(int j=0; j<=i-1; j++){
      if(arr[j] > arr[j+1]){
        didSwap = 1;
        swap(arr[j],arr[j+1]);
      }
    }
    if(didSwap == 0){
      break;
    }
  }
}

void print(int arr[] , int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  int arr[] = {9,8,10,2,30,89};
  BubbleSort(arr,6);
  print(arr,6);
  return 0;
}