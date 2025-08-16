#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;
int LongestConsecutiveArrayOpti(vector<int> &nums){
  int n = nums.size();
  // consider the edge case where the nums array is []
  if(n == 0) return 0;
  int longest = 1;
  unordered_set<int> st;
  for(int i=0; i<n; i++){
    st.insert(nums[i]);
  }

  for(auto it : st){
    // this means if prev element is not present then its the beginning of sequence
    if(st.find(it - 1) == st.end()){
      int cnt = 1;
      int x = it;
      // this means while the next element is not equal to end -> means while there is still next element in the sequence
      while(st.find(x+1) != st.end()){
        cnt = cnt + 1;
        x = x + 1;
      }
      longest = max(longest,cnt);
    }
  }
  return longest;
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
  cout << "The longest sequence is : " << LongestConsecutiveArrayOpti(nums) << endl;
  return 0;
}
// time complexity will be -> O(N) + O(2N) -> O(3N)
// O(N) for iterating through the array and putting the elements in the set data strucuture
// O(2N) while finding the consecutive sequence loop runs for most twice in the worst case
// if we consider the worst case for set operations in that case time complexity will be around O(N^2)
// if we used set instead of unordered set then time complexity would have been O(NlogN) -> O(logN) for set data strucuture
// space complexity will be -> O(N) -> using set data strucutre to solve the problem