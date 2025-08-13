#include <iostream>
#include <vector>
using namespace std;
vector <int> pairSumOpti(vector <int> nums , int target){
  vector <int> ans;
  int n = nums.size();
  int i = 0 ;
  int j = n - 1;
  int pairSum = 0;
  while(i < j){
    pairSum = nums[i] + nums[j];
    if(pairSum > target) j--;
    else if(pairSum < target) i++;
    else {
      ans.push_back(i);
      ans.push_back(j);
      return ans;
    }
  }
  return ans;
}
int main(){
  vector <int> nums = {2,7,11,15};
  int target = 26;
  vector <int> ans = pairSumOpti(nums , target);
  cout << ans[0] << "," << ans[1] << endl;
  return 0;
}
// Time complexity of this optimised  method is O(n) -> linear loop is only applied