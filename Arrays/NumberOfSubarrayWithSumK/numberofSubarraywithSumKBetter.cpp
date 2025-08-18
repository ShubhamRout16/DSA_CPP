#include <iostream>
#include <vector>
using namespace std;
int numberofSubarrayBF(vector<int> &nums , int target){
  int n = nums.size();
  int cnt = 0;
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
      sum += nums[j];

      if(sum == target){
      cnt++;
      }
    }
  }
  return cnt;
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
  int target;
  cout << "Enter the target value." << endl;
  cin >> target;
  cout << "The number of subarray with sum equals to target " << numberofSubarrayBF(nums , target) << endl;
  return 0;
}
// time complexity we have reduced to O(N^2)
// space complexity is O(1)