#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> reverseArray(vector<int> &nums){
  int n = nums.size();
  int start = 0;
  int end = n - 1;
  while(start < end){
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    start++;
    end--;
  }
  return nums;
}
int main(){
  int n;
  cout << "Enter number of elements : " << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = reverseArray(nums);
  cout << "Reversed array " << endl;
  for(int val : result){
    cout << val << " ";
  }
  return 0;
}