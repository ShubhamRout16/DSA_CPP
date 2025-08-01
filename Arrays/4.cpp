// longest subarray with sum k
// better approach
// this code will be partially accepted if we are applying it on the array having positives negatives and zeros -> because its a better approach
// this code will be most optimal solution for cases when array has only positives and zeros
#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a,long long k){
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for(int i=0; i<a.size(); i++){
    sum += a[i];
    if(sum == k){
      maxLen = max(maxLen,i+1);
    }
    int rem = sum - k;
    if(preSumMap.find(rem) != preSumMap.end()){
      int len = i - preSumMap[rem];
      maxLen = max(maxLen,len);
    }
  if(preSumMap.find(sum) == preSumMap.end()){
    preSumMap[sum] = i ;
  }
  }
  return maxLen;
}
int main(){
  vector<int> a = {1,2,3,1,1,1,1,4,2,3};
  long long k;
  cout << "sum " << endl;
  cin >> k;
  cout << longestSubarrayWithSumK(a,k);
  return 0;
}
// optimal approach
// time complexity of this approach is O(2N) and space complexity if O(1)
// at first time complexity seemed to be O(N^2) 
#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a,long long k){
  int left = 0 , right = 0;
  long long sum = a[0];
  int maxLen = 0;
  int n = a.size();
  while(right < n){
    while(left <= right && sum > k){
      sum -= a[left];
      left++;
    }
    if(sum == k){
      maxLen = max(maxLen,right-left+1);
    }
    right++;
    if(right < n) sum += a[right];
  }
  return maxLen;
}
int main(){
  vector<int> a = {1,2,3,1,1,1,1,4,2,3};
  long long k;
  cout << "sum " << endl;
  cin >> k;
  cout << longestSubarrayWithSumK(a,k);
  return 0;
}