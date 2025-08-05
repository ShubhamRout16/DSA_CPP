#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bubbleSortOptimized(int arr[] , int n){
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
    cout << "runs\n";
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

  bubbleSortOptimized(arr , n);
}

// if we take 6 5 4 3 2 1 as a input we can see that the loop runs for 6 times
// if we take 1 2 3 4 5 6 which is already sorted then we loop will not run single time because array is already sorted in ascending order
// we have made our bubble sort code optimized due to which 
// The TIME COMPLEXITY WILL BE O(N)