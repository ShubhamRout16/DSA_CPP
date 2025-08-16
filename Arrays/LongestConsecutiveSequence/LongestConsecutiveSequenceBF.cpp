#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int> &nums , int val){
  int n = nums.size();
  for(int i=0; i<n; i++){
    if(nums[i] == val){
      return true;
    }
  }
  return false;
}
int longestConsecutiveSequence(vector<int> &nums){
  int n = nums.size();
  int longest = 1;
  for(int i=0; i<n; i++){
    int x = nums[i];
    int cnt = 1;
    while(linearSearch(nums, x+1) == true){
      x = x + 1;
      cnt = cnt + 1;
    }
    longest = max(longest , cnt);
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
  int ans = longestConsecutiveSequence(nums);
  cout << "The longest sequence is: " << ans << endl;
  return 0;
}

// time complexity will be -> O(N^2) -> because two loops are used 
// space complexity will be -> O(1) -> because no extra space is bieng used