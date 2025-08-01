// TWO SUM PROBLEM
// BRUTE FORCE 
// TC -> O(N^2)
#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>&arr,int target){
  int n = arr.size();
  int found = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i]+arr[j] == target){
        found = 1;
      }
    }
  }
  if(found == 1) return 1;
  else 0;
}
int main(){
  vector<int> arr = {2,6,5,8,11};
  int target;
  cout << "enter the target number";
  cin >> target;
  if(bruteforce(arr,target) == 1) cout << "YES"  << endl ; 
  else cout << "NO";
  return 0;
}
 
// BETTER APPROACH -> most optimal approach for variety 2 where we have to return the indexes
// TC -> O(NlogN) -> ordered map & unordered map -> O(N) best and average case & O(N^2) -> worst case
// SC -> O(N) -> because we are using hashmap 
#include<bits/stdc++.h>
using namespace std;
vector<int> betterapproach(vector<int> &arr,int target){ //we will use vector here to return the indexes
  int n = arr.size();
  map<int,int> mpp;
  for(int i=0; i<n; i++){
    int num = arr[i];
    int moreNeeded = target - num;
    if(mpp.find(moreNeeded) != mpp.end()){
      return {mpp[moreNeeded],i};
    }
    mpp[num] = i;
  }
  return {-1,-1};
}
int main(){
  vector<int> arr = {2,6,5,8,11};
  int target;
  cout << "enter the target number";
  cin >> target;
  vector<int> result = betterapproach(arr,target);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}

// OPTIMAL APPROACH -> most optimal approach for variety 1
// TC -> O(N) + O(NLOGN) due to sorting
// SC -> O(1) if we are not considering the distortion we are doing while sorting the array , and if we are considering it then O(N)
#include<bits/stdc++.h>
using namespace std;
int optimalapproach(vector<int> &arr,int target){
  int n = arr.size();
  int left = 0,right = n-1;
  while(left<right){
    int sum = arr[left] + arr[right];
    if(sum == target) return 1;
    else if(sum < target) left++;
    else right--;
  }
  return 0;
}
int main(){
  vector<int> arr = {2,6,5,8,11};
  int target;
  cout << "enter the target number";
  cin >> target;
  if(optimalapproach(arr,target) == 1) cout << "YES";
  else cout << "NO";
  return 0;
}