#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArrayOpti(vector<int> &nums){
  // we have solved the problem using Kadane's algorithm
  // time complexity is O(N) and space complexity O(1)
  int n = nums.size();
  int maxi = INT_MIN;
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += nums[i];

    if(sum > maxi){
      maxi = sum;
    }

    if(sum < 0){
      sum = 0;
    }
  }

  // to calculate the max sum of subarray for empty subarray
  if(maxi < 0) maxi = 0;

  return maxi;
}
int main(){
  int n ;
  cout << "Enter the number of elements of array : ";
  cin >> n;
  vector<int> nums;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  cout << "Sum of max subarray is : " << maxSubArrayOpti(nums) << endl;
  return 0;
}