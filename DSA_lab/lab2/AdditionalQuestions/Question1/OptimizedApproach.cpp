#include<iostream>
#include<algorithm>
using namespace std;
void countPairsWithDifferenceK(int arr[] , int n , int  k){
  sort(arr, arr+n);
  int count = 0;

  int i = 0;
  int j = 1;
  while(i < n && j < n){
    if(i == j){
      j++;
      continue;
    }

    int diff = arr[j] - arr[i];

    if(diff == k){
      count++;
      i++;
      j++;
    }
    else if(diff < k){
      j++;
    }
    else{
      i++;
    }
  }

  cout << "Number of count pairs with difference " << k << " are " << count;
}
int main(){
  int n;
  cout << "Enter numbre of elements : " << endl;
  cin >> n;

  int arr[n];
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int k;
  cout << "Enter the absolute difference : " << endl;
  cin >> k;
  countPairsWithDifferenceK(arr , n , k);
  return 0;
}

// time complexity of this code will be O(nlogn) -> O(logn) for sorting & -> O(n) for two pointer iteration