#include<iostream>
using namespace std;

// selection sort is based on the principle of select a minimum and swap
// time complexity ? 
// loop runs for N + (N-1) + (N-2) + ..... + 1 + 0
// summation of this many times is N * (N-1)/2 
// which is equal to N^2 -> O(N^2)
// same timecomplexity for best , worst and average
void selectionSort(int arr[] , int n){
  for(int i=0; i<n; i++){
    int mini = i;
    for(int j=i+1; j<n; j++){
      if(arr[j] < arr[mini]){
        mini = j;
      }
    }
    swap(arr[mini],arr[i]);
  }
}

void print(int arr[] , int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  // int arr[] = {9,8,10,2,30,89};
  // best case no swaps needed which is already sorted array
  int arr[] = {1,2,3,4,5,6};
  selectionSort(arr,6);
  print(arr,6);
  return 0;
}