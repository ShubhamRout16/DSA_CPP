#include<iostream>
using namespace std;
int majorityEl(vector<int> &arr){
  int n;
  n = arr.size();
  
  for(int i=0; i<n; i++){
    int cnt = 0;
    for(int j=0; j<n; j++){
      if(arr[j] == arr[i]){
        cnt++;
      }
    }
    if(cnt > n/2){
      return arr[i];
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
  cout << "Majority element is " << majorityEl(arr) << endl;
  return 0;
}

// TIME COMPLEXITY OF THIS APPROACH IS
// O(N^2)
// because of two loops the time complexity is O(n^2)