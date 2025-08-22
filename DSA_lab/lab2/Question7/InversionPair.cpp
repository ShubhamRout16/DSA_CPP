#include<iostream>
using namespace std;
void inversionPair(int arr[] , int n){
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(i < j && arr[i] > arr[j]){
        cout << "Inversion pair -> " << arr[i] << "," << arr[j] << endl;
      }
    }
  }
}
int main(){
  int n;
  cout << "Enter number of elements : " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n;  i++){
    cin >> arr[i];
  } 
  cout << "Current array is : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  inversionPair(arr,n);
  return 0;
}