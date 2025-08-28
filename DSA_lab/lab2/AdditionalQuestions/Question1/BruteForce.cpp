#include<iostream>
#include<cmath>
using namespace std;
int countPairsWithDifferenceK(int arr[] , int n , int k){
  int count = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(abs(arr[i] - arr[j]) == k){
        count++;
      }
    }
  }

  return count;
}
int main(){
  int n;
  cout << "Enter number of elements of the array..." << endl;
  cin >> n;

  int arr[n];
  cout << "Enter array elements.." << endl;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int k;
  cout << "Enter the value of the difference.." << endl;
  cin >> k;
  
  cout << "Number of pairs with difference " << k << " are " << countPairsWithDifferenceK(arr , n , k);
  return 0;
}

// time complexity will be -> O(n^2)