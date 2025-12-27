#include<iostream>
using namespace std;

int partition(int arr[] , int start , int end){
  int pos = start;
  int pivot = start;
  for(int i=start; i<=end; i++){
    if(arr[i] <= pivot){
      swap(arr[i],arr[pos]);
      pos++;
    }
  }
  return pos-1;
}

void qs(int arr[],int start , int end){
  if (start >= end) return;
  int pind = partition(arr,start,end);
  qs(arr,start,pind-1);
  qs(arr,pind+1,end);
}

int main(){
  int arr[] = {7,2,8,5,9,2};
  qs(arr,0,5);
  for(int i=0; i<6; i++){
    cout << arr[i] << " ";
  }
  return 0;
}