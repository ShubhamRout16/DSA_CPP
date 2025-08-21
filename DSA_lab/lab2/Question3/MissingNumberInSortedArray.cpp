#include<iostream>
#include<vector>
using namespace std;
int FindMissingNumber(vector<int> &nums , int N){
  int n = nums.size();
  for(int i=1; i<=N; i++){
    int flag = 0;
    for(int j=0; j<n; j++){
      if(nums[j] == i){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      return i; // return number
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
  int N;
  cout << "Enter the ending range : " << endl;
  cin >> N;
  int number = FindMissingNumber(nums , N);
  if(number == -1){
    cout << "No number is missing." << endl;
  }else{
    cout << "Number found and its : " << number << endl;
  }
  return 0;
}
// time complexity for this code will be O(N * n)
// special case -> O(N^2) or O(n^2) -> when N = n
// space complexity for this code will be O(1) -> we are not using any extra space
