#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nextPermutation(vector<int> &nums){
  int n = nums.size();
  int ind = -1;
  for(int i=n-2; i>=0; i--){
    if(nums[i] < nums[i+1]){
      // found the breakpoint
      ind = i;
      break;
    }
  }
  if(ind == -1){
    // this is last permutation
    reverse(nums.begin() , nums.end());
    return nums;
  }
  // step 2 find nearest greater number
  for(int i=n-1; i>=0; i++){
    if(nums[i] > nums[ind]){
      swap(nums[i] , nums[ind]);
      break;
    }
  }
  // step 3 
  reverse(nums.begin() + ind + 1 , nums.end());
  return nums;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter array elements." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = nextPermutation(nums);
  for (int num : result) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}
// time complexity will be O(3N)
// space complexity will be O(N) for modifying the array otherwise O(1)