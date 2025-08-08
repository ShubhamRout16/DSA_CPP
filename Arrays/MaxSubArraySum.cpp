#include <climits>
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cout << "Enter number of elements." << endl;
  cin >> n;
  vector <int> vec;
  cout << "Enter array elements." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    vec.push_back(val);
  }

  // to find the subarray of all array
  // for(int i=0; i<n; i++){
  //   for(int j=i; j<n; j++){
  //     for(int k=i; k<=j; k++){
  //       cout << vec[k];
  //     }
  //     cout << " ";
  //   }
  //   cout << endl;
  // }

  // brute force approach of maxsum subarray
  // time complexity -> O(n^3)
  // int maxSum = INT_MIN;
  // for(int i=0; i<n; i++){
  //   int currSum = 0;
  //   for(int j=i; j<n; j++){
  //     currSum += vec[j];
  //     maxSum = max(currSum,maxSum);
  //   }
  // }

  // most optimized approach -> KADANE'S ALGORITHM
  // time complexity -> O(n);
  // edge case -> when all array elements are negative 
  // thats why we check currSum at the end
  int maxSum = INT_MIN;
  int currSum = 0;
  for(int i=0; i<n; i++){
    currSum += vec[i];
    maxSum = max(currSum, maxSum);
    if(currSum < 0){
      currSum = 0;
    }
  }
  cout << "maximum sum of subarray " << maxSum ;
  return 0;
}