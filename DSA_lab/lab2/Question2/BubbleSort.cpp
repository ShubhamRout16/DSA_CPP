#include<iostream>
#include<vector>
using namespace std;
vector<int> bubbleSort(vector<int> &nums){
  int n = nums.size();
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=i-1; j++){
      if(nums[j] > nums[j+1]){
        // swap adjacent elements
        int temp = nums[j+1];
        nums[j+1] = nums[j];
        nums[j] = temp;
      }
    }
  }
  return nums;
}
int main(){
  int n;
  cout << "Enter number of elements in array." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter array elements : " << endl; 
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = bubbleSort(nums);
  cout << "Array after applying bubble sort : " << endl;
  for(int val : result){
    cout << val << " ";
  }
  return 0;
}
// time complexity is O(N^2) -> found out through sum of first n natural numbers
// space complexity is O(1) -> because no extra space is being used we are using in place method