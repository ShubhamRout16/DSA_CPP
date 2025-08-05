#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[] , int n){
  for(int i=0; i<=n-1; i++){
    int j = i;
    while(j>0 && arr[j-1] > arr[j]){
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;
      j--;
      cout << "runs\n";
    }
  }
   // print the new array
   cout << "Array after sorting.\n";
   for(int i=0; i<n; i++){
     cout << arr[i] << " ";
   }
}
int main(){
  int n;
  cout << "Enter number of elements of Array.\n";
  cin >> n;
  int arr[n];
  cout << "Enter array elements\n";
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  cout << "\n";

  cout << "Array before sorting\n";
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
  insertionSort(arr,  n);
  return 0;
}