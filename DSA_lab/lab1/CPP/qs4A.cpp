#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void arrayReverse(int arr[] , int size){
  int start = 0;
  int end = size - 1;
  while(start < end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
  // print the reversed array
  cout << "Array after reversing.\n";
  for(int i=0; i<size; i++){
    cout << arr[i] << " ";
  }
}
int main(){
  int n;
  cout << "Enter the number of elements of number.\n";
  cin >> n;
  int arr[n];
  cout << "Enter the array elements.\n";
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  cout << "Array  before reversing.\n";
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << "\n";
  arrayReverse(arr , n);
  return 0;
}