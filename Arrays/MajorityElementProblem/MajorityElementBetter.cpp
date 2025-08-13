#include<iostream>
#include<map>
using namespace std;
int majorityElBetter(vector<int> &arr){
  //  for this approach we will hash maps
  // loop through the map and store each element instance and its count in the hash map
  // in hash map -> the values are stored in the form of key value pair -> (el, count);
  // then we will loop through the map and check which elements value count is greater than N/2 then that element is majorithy element

  int n = arr.size();
  map<int,int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }
  for(auto it: mpp){
    if(it.second > (n/2)){
      return it.first;
    }
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
  cout << "Majority element is " << majorityElBetter(arr) << endl;
  return 0;
}
// time complexity 
// first loop -> O(nlogn) -> if we use unordered map then it will O(n) for worst and average cases -> then time complexity will be O(n^2)
// second loop -> O(n)
// Space complexity -> O(n) -> takes a extra space