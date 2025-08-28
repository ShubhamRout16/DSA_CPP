#include<iostream>
using namespace std;
void distinctElements(int arr[] , int n){
  int count = 0;
  for(int i=0; i<n; i++){
    int duplicateEl = 0;
    for(int j=0; j<i; j++){
      if(arr[i] == arr[j]){
        duplicateEl = 1;
        break;
      }
    }
    if(duplicateEl   == 0){
      count++;
    }
  }
  cout << "Total number of distinct elements : " << count << endl;
}
int main(){
  int n;
  cout << "Enter number of elements : " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  cout << "Current array is : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  distinctElements(arr , n);
  return 0;
}