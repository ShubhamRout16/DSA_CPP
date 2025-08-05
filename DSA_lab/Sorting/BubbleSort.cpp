#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[] , int n){
  // logic for bubble sort
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=i-1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
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

  bubbleSort(arr , n);
  return 0;
}

// TIME COMPLEXITY 
// the outer loop runs from n-1 to 0 -> n times
// the inner loop runs for (n-1) + (n-2) + (n-3)+ ........ + 3 + 2 + 1
// the summation of this is approximately (n*(n+1)/2) -> (n^2/2 + n/2)
// since n/2 is smaller then it will be ignored
// O(n^2) -> this is worst case and average case
// problem in this code was that this code will run loops even if the array is sorted 
// due to which our code becomes not optimized.