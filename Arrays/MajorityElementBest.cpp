#include <iostream>
using namespace std;
int majorityElBest(vector<int> &arr){
  // for best approach for solving majority element problem we will take -> Moore's voting algorithm
  // time complexity for this approach will be 
  // moore's voting algorithm -> O(N)
  // if in the question it is given that there may not exist a majority element 
  // to check that we applied second loop -> O(N)
  // total time complexity if given in question majority element is not present -> O(N) + O(N)
  // (normally) total time complexity if given in question that majority element is present -> O(N)
  // no extra space is being used -> Space Complexity will be -> O(1)
  int n;
  n = arr.size();
  int el;
  int cnt = 0;
  for(int i=0; i<n; i++){
    if(cnt == 0){
      cnt = 1;
      el = arr[i];
    }
    else if(arr[i] == el){
      cnt++;
    }
    else {
      cnt --;
    }
  }
  int cnt1 = 0;
  for(int i=0; i<n; i++){
    if(arr[i] == el){
      cnt1++;
    }
  }
  if(cnt1 > (n/2)){
    return el;
  }
  return -1;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector <int> arr;
  cout << "Enter the array elements." << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    arr.push_back(val);
  }
  cout << "Majority element is " << majorityElBest(arr) << endl;
  return 0;
}
// for the best approach we will use moore's voting algorithm