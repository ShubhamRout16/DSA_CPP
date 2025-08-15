#include<iostream>
#include<vector>
using namespace std;
vector<int> LeadersInArray(vector<int> &nums){
  int n = nums.size();
  vector<int> result;
  for(int i=0; i<n; i++){
    int leader = true;
    for(int j=i+1; j<n; j++){
      if(nums[i] < nums[j]){
        leader = false;
        break;
      }
    }
    if(leader == true){
      result.push_back(nums[i]);
    }
  }
  return result;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter the elements of array." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = LeadersInArray(nums);
  for(int res: result){
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
// time complexity will be O(N^2) because two loops are made to run -> worst case
// space complexity will be O(N) -> extra array used to store the answer -> worst case