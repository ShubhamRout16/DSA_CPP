#include<iostream>
#include<vector>
using namespace std;
vector<int> LeadersInArrayOpti(vector<int> &nums){
  int n = nums.size();
  vector<int> result;
  int maxi = INT_MIN;
  for(int i=n-1; i>=0; i--){
    if(nums[i] > maxi){
      result.push_back(nums[i]);
    }
    maxi = max(nums[i] , maxi);
  }
  sort(result.begin() , result.end());
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
  vector<int> result = LeadersInArrayOpti(nums);
  for(int res: result){
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
// time complexity will be O(N) + O(NlogN) -> for using loop + sorting array
// space complexity will be O(N) -> for using extra array for storing results