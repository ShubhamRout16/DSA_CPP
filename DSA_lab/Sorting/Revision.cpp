#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[] , int n){
  // outer loop 
  for(int i=0; i<=n-2; i++){
    int  min = i;
    // inner loop
    for(int j=i; j<=n-1; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    // swap
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  // print the array after sorting
  cout << "Array after Selection sorting.\n";
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}
void bubbleSortOpti(int arr[] , int n){
  int didSwap = 0;
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=i-1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        didSwap = 1;
      }
    }
    if(didSwap == 0){
      break;
    }
  }
  // print the array after sorting
  cout << "Array after Bubble sorting.\n";
  for (int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int main(){
  int n;
  cout << "Enter the number of elements of array.\n";
  cin >> n;

  int arr[n];
  cout << "Enter array elements.\n";
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  cout << "\n";

  selectionSort(arr , n);
  bubbleSortOpti(arr,n);
  return 0;
}