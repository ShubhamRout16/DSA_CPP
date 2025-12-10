#include<iostream>
using namespace std;

void MinHeapify(int arr[] , int index , int n){
  int smallest = index;
  int left = 2*index+1;
  int right = 2*index+2;

  if(left<n && arr[left] < arr[smallest]) smallest = left;
  if(right<n && arr[right] < arr[smallest]) smallest = right;

  if(smallest != index){
    swap(arr[index] , arr[smallest]);
    MinHeapify(arr,smallest,n);
  }
}

void BuildMinHeap(int arr[] , int n){
  // builduing min heap using step down for time complexoty of O(N)
  for(int i=(n/2)-1; i>=0; i--){
    MinHeapify(arr,i,n);
  }
}

void print(int arr[] , int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  int arr[] = {10,3,8,9,5,13,18,14,11,70};
  BuildMinHeap(arr,10);
  print(arr,10);
  return 0;
}