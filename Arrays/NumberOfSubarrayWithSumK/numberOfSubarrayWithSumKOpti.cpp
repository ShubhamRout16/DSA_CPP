#include <iostream>
#include <vector>
#include <map>
using namespace std;
int numberofSubarrayBF(vector<int> &nums , int target){
  int n = nums.size();
  int cnt = 0;
  unordered_map<int,int> mpp;
  mpp[0] = 1;
  int prefSum = 0;
  for(int i=0; i<n; i++){
    prefSum += nums[i];
    int remove = prefSum - target;
    cnt += mpp[remove];
    mpp[prefSum] += 1;
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
// time complexity will be -> O(N * logN) , NlogN for unordered map and if ordered map , worst case O(1) and best case O(N)
// space complexity will be o(N)
