// FIND THE MISSING NUMBER IN THE ARRAY
// BRUTE FORCE
#include<bits/stdc++.h>
using namespace std;
int searchmiss(vector<int> &arr,int N){
  // first loop
  for(int i=1; i<=N; i++){
    int flag = 0;
    for(int j=0; j<N; j++){
      if(arr[j] == i){
        flag = 1;
        break;
      }
    }
    if(flag == 0) return i;
  }
}
int main(){
  int N;
  cout << "enter number N" <<  endl;
  cin >> N;
  vector<int> arr = {1, 2, 4, 5};
  cout << searchmiss(arr,N);
  return 0;
}
// BETTER SOLUTION
#include<bits/stdc++.h>
using namespace std;
int bettersearch(vector<int> &arr,int N){
  vector<int> hash(N+1,0); // creates vector array with n+1 elements all intialized with 0 numnber
  for(int i=0; i<N-1; i++){
    hash[arr[i]] = 1;
  }
  for(int i=1; i<=N; i++){
    if(hash[i]==0) return i;
  }
}
int main(){
  int N;
  cout << "enter number N" <<  endl;
  cin >> N;
  vector<int> arr = {1, 2, 4, 5};
  cout << bettersearch(arr,N);
  return 0;
}
// OPTIMAL METHOD
// there are 2 optimal method -> summation method and XOR method -> XOR method is better than summation -> in case when N is larger number
#include<bits/stdc++.h>
using namespace std;
int optimal1(vector<int> &arr,int N){
  // summation method
  int sum1 = ( N * (N+1) )/2 , sum2 = 0;
  for(int i=0; i<N-1; i++){
    sum2 = sum2 + arr[i];
  }
  return (sum1 - sum2) ;
}
int optimal2(vector<int> &arr,int N){
  // XOR METHOD
  int XOR1 = 0;
  for(int i=1; i<=N; i++){
    XOR1 = XOR1 ^ i;
  }
  int XOR2 = 0;
  for(int i=0; i<N-1; i++){
    XOR2 = XOR2 ^ arr[i];
  }
  return (XOR2^XOR1);
}
int optimal3(vector<int> &arr,int N){
  // IMPROVED XOR METHOD
    int XOR1 = 0,XOR2 = 0;
    for(int i=0; i<N-1; i++){
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i+1);
    }
    XOR1 = XOR1 ^ N;
    return (XOR1^XOR2);
}
int main(){
  int N;
  cout << "enter number N" <<  endl;
  cin >> N;
  vector<int> arr = {1, 2, 3, 5};
  cout << optimal1(arr,N) << endl ;
  cout << optimal2(arr,N) << endl ;
  cout << optimal3(arr,N) ;
  return 0;
}
// MAXIMUM CONSECUTIVE ONES
#include<bits/stdc++.h>
using namespace std;
int maxi(vector<int> &arr){
  int n = arr.size();
  int cnt = 0, maxi = 0;
  for(int i=0; i<n; i++){
    if(arr[i] == 1){
      cnt++;
      maxi = max(maxi,cnt);
    }
    else  cnt = 0;
  }
  return maxi;
}
int main(){
  vector<int> arr = {1, 1,0,1,1,1,0,1,1};
  cout << maxi(arr);
  return 0;
}
// the number which appears only once and others are appearing twice
// brute force
#include<bits/stdc++.h>
using namespace std;
int once(vector<int> &arr){
  int n = arr.size();
  for(int i=0; i<n; i++){
    int cnt = 0; 
    int nums = arr[i];
    for(int j=0; j<n; j++){
      if(arr[j]==nums){
        cnt++;
      }
    }
    if(cnt == 1) return nums;
  }
}
int main(){
  vector<int> arr = {1,1,2,3,3,4,4};
  cout << once(arr);
  return 0;
}
// better approach 
// hashing -> array hashing , map hashing
#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr){
  // find the max element
  int n = arr.size();
  int maxi = arr[0];
  for(int i=0; i<n; i++){
    if(arr[i]>maxi){
      maxi = arr[i];
    }
  }
  // declare the hash array
  vector<int> hash(maxi+1,0);
  // store the array elements and their frequencies in the hash array
  for(int i=0; i<n; i++){
    hash[arr[i]]++;
  }
  // iterate over the hash array and find the number with frequency 1
  for(int i=0; i<n; i++){
    if(hash[arr[i]] == 1){
      return arr[i];
    }
  }
}
int main(){
  vector<int> arr = {4, 1, 2, 1, 2};
  int ans = getSingleElement(arr);
  cout << "The single element is: " << ans << endl;
  return 0;
}
// map hashing
#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
int main()
{
  vector<int> arr = {4, 1, 2, 1, 2};
  int ans = getSingleElement(arr);
  cout << "The single element is: " << ans << endl;
  return 0;
}
// optimal hashing
#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr){
  int n = arr.size();
  int xor1 = 0;
  for(int i=0; i<n; i++){
    xor1 = xor1 ^ arr[i];
  }
  return xor1;
}
int main(){
  vector<int> arr = {4, 1, 2, 1, 2};
  int ans = getSingleElement(arr);
  cout << "The single element is: " << ans << endl;
  return 0;
  return 0;
}