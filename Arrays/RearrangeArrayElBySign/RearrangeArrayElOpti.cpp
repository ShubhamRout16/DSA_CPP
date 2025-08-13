#include<iostream>
#include<vector>
using namespace std;
vector<int> RearrangeElementsOpti(vector<int> &nums){
  int n = nums.size();
  vector<int> ans(n,0);

  int posIndex = 0;
  int negIndex = 1;

  for(int i=0; i<n; i++){
    if(nums[i] > 0){
      ans[posIndex] = nums[i];
      posIndex += 2;
    }
    else{
      ans[negIndex] = nums[i];
      negIndex += 2;
    }
  }

  return ans;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector<int> nums;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = RearrangeElementsOpti(nums);
  // print the result array
  for(int val: result){
    cout << val << " ";
  }
  return 0;
}
// time complexity -> 