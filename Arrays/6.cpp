// SORT ARRAY IN 0'S 1'S & 2'S
// BRUTE FORCE -> MERGE SORT
// BETTTER APPROACH
#include<bits/stdc++.h>
using namespace std;
void betterapproach(vector<int> &arr){
  int n = arr.size();
  int cnt0 = 0 ,cnt1 = 0, cnt2 = 0;
  for(int i=0; i<n; i++){
    if(arr[i] == 0) cnt0++;
    else if(arr[i] == 1) cnt1++;
    else cnt2++;
  }
  for(int i=0; i<cnt0; i++) arr[i] = 0;
  for(int i=cnt0; i<(cnt0+cnt1); i++) arr[i] = 1;
  for(int i=(cnt0+cnt1); i<n; i++) arr[i] = 2;
}
int main(){
  vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
  betterapproach(arr);
  cout << "after sorting" << endl;
  for(int i=0; i<arr.size(); i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// OPTIMAL APPROACH
// DUTCH NATIONAL FLAG ALGORITHM
#include<bits/stdc++.h>
using namespace std;
void optimalapproach(vector<int> &arr,int n){
  int low = 0, mid = 0 , high = n-1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[mid],arr[low]);
      mid++;
      low++;
    }
    else if(arr[mid] == 1) mid++;
    else{
      swap(arr[mid],arr[high]);
      high--;
    }
  }
}
int main(){
  vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
  int n = arr.size();
  optimalapproach(arr,n);
  cout << "after sorting" << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}