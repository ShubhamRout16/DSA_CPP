#include<iostream>
#include<vector>
using namespace std;
vector<int> RearrangeElements(vector<int> &nums){
  int n = nums.size();
  vector<int> pos;
  vector<int> neg;
  // seperate all the positive and negative integers from the array into pos and neg array
  for(int i=0; i<n; i++){
    if(nums[i] > 0){
      pos.push_back(nums[i]);
    }
    else{
      neg.push_back(nums[i]);
    }
  }

  // rearrange the indexes and the values in the main array
  for(int i=0; i<n/2; i++){
    nums[2*i] = pos[i];
    nums[2*i+1] = neg[i];
  }

  return nums;
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
  vector<int> result = RearrangeElements(nums);
  // print the result array
  for(int val: result){
    cout << val << " ";
  }
  return 0;
}
// time complexity is O(N) + O(N/2) 
// space complecity is O(N/2) + O(N/2) -> O(N)