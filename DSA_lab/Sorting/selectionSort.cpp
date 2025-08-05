#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
  // we will run loop till second last number , because we dont need to swap the last digit
  for(int i=0; i<=n-2; i++){
    int min = i;
    // run loop to find the minimum number
    for(int j=i; j<=n-1; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    // swap both the min number and first index of each loop
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  // print the new array
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}

// TIME COMPLEXITY
// if we carefully observe loop is running from 0 to n-2 -> n-1 times
// the inner loop is running for i=0 -> 0 to n-1 for i=1 -> 1 to n-2
// (n-1) + (n-2) + (n-3) + ...... + 3 + 2 + 1 
// this sumamtion is equal to (n*(n+1)/2) -> n^2/2 + n/2
// ignore n/2 which is very smaller compared to n^2 also ignore constant 
// TC -> O(n^2)