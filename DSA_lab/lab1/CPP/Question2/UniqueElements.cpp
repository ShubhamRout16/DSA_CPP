#include<iostream>
#include<vector>
using namespace std;
vector<int> uniqueElements(vector<int> &nums){
  int n = nums.size();
  vector<int> result;
  for(int i=0; i<n; i++){
    int isDuplicate = 0;
    for(int j=0; j<i; j++){
      if(nums[i] == nums[j]){
        isDuplicate = 1;
        break;
      }
    }
    if(isDuplicate == 0){
      result.push_back(nums[i]);
    }
  }
  return result;
}
int main(){
  int n;
  cout << "Enter number of elements." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter elements of array." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = uniqueElements(nums);

  for(int val : result){
    cout << val << " " ;
  }
  cout << endl;
  return 0;
}