#include<iostream>
using namespace std;
void MissingNumber(int arr[] , int n){
  int left = 0;
  int right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;

    if(arr[mid] == mid + 1){
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  int missingNum = left + 1;
  cout << "Missing number is : " << missingNum << endl;
}
int main(){
  int n;
  cout << "Enter number of elements : " << endl;
  cin >> n;
  
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  MissingNumber(arr , n);
  return 0;
}