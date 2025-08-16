#include<iostream>
#include<vector>
using namespace std;
int longestConsecutiveBetter(vector<int> &nums){
  int n = nums.size();
  int longest = 1;
  int lastSmaller = INT_MIN;
  int cntCurr = 0;
  // we are distorting the array by sorting it
  sort(nums.begin() , nums.end());
  for(int i=0; i<n; i++){
    if(nums[i] - 1 == lastSmaller){
      cntCurr = cntCurr + 1;
      lastSmaller = nums[i];
    }
    else if(nums[i] != lastSmaller){
      cntCurr = 1;
      lastSmaller = nums[i];
    }
    longest = max(longest , cntCurr);
  }
  return longest;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter the array elements." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  cout << "The longest sequence is : " << longestConsecutiveBetter(nums) << endl;
  return 0;
}
// time complexity will be O(NlogN) + O(N) -> NlogN for sorting the array and O(N) for finding the sequence
// space complexity will be O(1) -> no extra space will be used