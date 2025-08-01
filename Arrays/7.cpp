// MAJORITY ELEMENT 
// BRUTE FORCE 
// TC -> O(N^2)
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr){
  int n = arr.size();
  // will pick each element and iterate through the array and keep a counter check
  for(int i=0; i<n; i++){
    int cnt = 0;
    for(int j=0; j<n; j++){
      if(arr[j] == arr[i]){
        cnt++;
      }
    }
    // will check if the counter is greater than n/2 times then return the number which is the majority element
    if(cnt > n/2) return arr[i];
  }
  // majority element not found
  return -1;
}
int main(){
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}

// BETTER APPROACH -> in better approach we will have to trim the TC from O(N^2) to somewhere arounf O(NlogN) or O(N) or O(2N)
// focuses on using the hashing method where we will use the hashmap data structure to store the element and its count as key and value pair
// TC -> O(N) + O(NlogN) & SC -> O(N) tc for iterating through the array and tc for hashmap and we are using a extra space of hashmap 
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr){
  int n = arr.size();
  // hashmap to store the element and the number of times it appears
  map<int,int> mpp;
  // pick a element and iterate through the array to count the number of times it appears and store it in the hashmap
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }
  // iterate through the hashmap and find the value of the element which comes greater than n/2 times and return it
  for(auto it : mpp){
    if(it.second > (n/2)){
      return it.first;
    }
  }
  // majority element not found
  return -1;
}
int main(){
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}

// OPTIMAL APPROACH -> in this we have to think to somehow trim the space complexity to O(1)
// for this we will apply MOORE'S VOTING ALGORITHM
// for this algorithm we will have a intiution where we will take 2 variables a element and its count
// TC -> O(N) & SC -> O(1)
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr){
  int n = arr.size();
  // applying moores voting algorithm
  int cnt = 0; // if cnt = 0 then no element is selected yet
  int el;
  // through this algorithm we will find the element which is majority element if the majority element exists in the array
  for(int i=0; i<n; i++){
    if(cnt == 0){
      // selecting the element
      cnt = 1;
      el = arr[i];
    }
    else if(arr[i] == el) cnt++;
    else cnt--;
  }

  // check if the majority element we have found is really the majority element or not by iterating thorugh the array
  int cnt1 = 0;
  for(int i=0; i<n; i++){
    if(el == arr[i]){
      cnt1++;
    }
  }

  // if element count greater than n/2 times return majority element
  if(cnt1 > (n/2)) return el;
  else return -1;
}
int main(){
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}