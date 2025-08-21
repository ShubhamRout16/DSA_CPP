#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> &nums , int target){
  int n = nums.size();
  int left = 0;
  int right = n - 1;
  int index ;
  while(left <= right){
    int mid = left + (right - left) / 2 ;
    // if mid = target found element
    if(nums[mid] == target){
      index = mid;
      return index;
    }
    // if mid > target search in the left half
    if(nums[mid] > target){
      right = mid - 1;
    }
    // if mid <  target search in the right half
    else {
      left = mid + 1;
    }
  }
  return -1; 
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
  int target;
  cout << "Enter the number to find : " << endl;
  cin >> target;
  int indx = binarySearch(nums ,target);
  if(indx == -1){
    cout << "Element not found." << endl;
  }
  else{
    cout << "Element -> " << target << " found at index -> " << indx << endl;
  }
  return 0;
}
// time complexity will be -> O(logN)
// space complexity will be -> O(1) -> we are not using any extra space