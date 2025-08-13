#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxSubArrayOptiPrint(vector<int> &nums){
  // we also might have a follow up question
  // where we have to print the subarray with max sum and there might be more than one subarray and we have to print any one of them
  int n = nums.size();
  int maxi = INT_MIN;
  int sum = 0;
  int start = 0;
  int ans_Start = -1;
  int ans_End = -1;
  for(int i=0; i<n; i++){
    sum += nums[i];
    if(sum == 0){
      start = i;
    }

    if(sum > maxi){
      maxi = sum;
      ans_Start = start;
      ans_End = i;
    }

    if(sum < 0){
      sum = 0;
    }
  }

  // to calculate the max sum of subarray for empty subarray
  if(maxi < 0) maxi = 0;

  cout << "The subarray is: [";
  for(int i=ans_Start; i<= ans_End; i++){
    cout << nums[i] << " ";
  }
  cout << "]" << "\n";

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
  cout << "Sum of max subarray is : " << maxSubArrayOptiPrint(nums) << endl;
  return 0;
}
// the time complexity of this is O(N) 
// space complexity of this is O(1) -> we are not using any extra space