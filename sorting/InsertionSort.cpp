#include<iostream>
using namespace std;

// Insertion sort is based on the algorithm that it takes a element and place it in its correct position
void InsertionSort(int arr[] , int n){
  for(int i=1; i<n; i++){
    int key = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void print(int arr[] , int n){
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}

int main(){
  int arr[] = {6,1,4,3,2};
  InsertionSort(arr,5);
  print(arr,5);
  return 0;
}