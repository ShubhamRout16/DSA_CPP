#include<iostream>
#include<vector>
using namespace std;
int xorMethod(vector<int> &nums , int N){
  int n = nums.size();
  int xor1 = 0 ;
  int xor2 = 0 ;
  // xor for all the elements in the range
  for(int i=1; i<=N; i++){
    xor1 = xor1 ^ i;
  }
  // xor for all the elements in the array
  for(int i=0; i<n; i++){
    xor2 = xor2 ^ nums[i];
  }

  int missingElement = xor1 ^ xor2;
  return missingElement;
}
int main(){
  int n ;
  cout << "Enter number of elements." << endl;
  cin >> n;
  vector<int> nums;
  cout << "Enter number of array elements : " << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  int N;
  cout << "Enter ending range : " << endl;
  cin >> N;
  cout << "Missing elements is : " << xorMethod(nums , N) << endl;
  return 0;
}
// time complexity for this code will be -> O(N) + O(n)
// space complexity for this code will be -> O(1) -> because we are not using any extra space 