#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArray(vector<int> &nums){
  int n = nums.size();
  int maxi = INT_MIN;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      int sum = 0;
      for(int k=i; k<j; k++){
        sum += nums[k];
      }
      maxi = max(maxi,sum);
    }
  }
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
  cout << "Sum of max subarray is : " << maxSubArray(nums) << endl;
  return 0;
}
// Time complexity of this method is O(N^3)
// space complexity of this method is O(1) 