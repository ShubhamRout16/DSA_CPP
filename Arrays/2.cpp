// Q) LEFT ROTATE EACH ELEMENT BY ONE PLACE
// optimal approach
// TC -> O(N) SC-> O(1) -> its not taking any space but considering the array on which the whole process is operating then SC -> O(N)
#include<bits/stdc++.h>
using namespace std;
int lrbyoneplace(vector<int> &arr,int n){
  int temp = arr[0];
  for(int i=1; i<n; i++){
    arr[i-1]=arr[i];
  }
  arr[n-1]=temp;
  return 0;
}
int main(){
  vector<int> arr = {1,2,3,4,5};
  int n = arr.size();
  lrbyoneplace(arr,n);
  cout << "modified array is : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// Q) LEFT ROTATE EACH ELEMENTS BY D PLACES
// brute force approach
// TC -> O(N)+O(N-D)+O(D) = O(N+D) SC->O(N)
// Q) BUT CAN WE DO THIS IN SPACE OF O(1); -> OPTIMAL APPROACH
#include<bits/stdc++.h>
using namespace std;
void dplaces(vector<int> &arr,int n,int d){
  // if d>n then
  d = d % n;
  // storing the d number of elements in temp array
  vector<int> temp;
  for(int i=0; i<d; i++){
    temp.push_back(arr[i]);
  }
  // shifting
  for(int i=d; i<n; i++){
    arr[i-d] = arr[i];
  }
  // push back the temp array elements to main array
  for(int i=n-d; i<n; i++){
    arr[i] = temp[i-(n-d)];
  }
}
int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  int n = arr.size();
  int d;
  cout << "enter d : " << endl;
  cin >> d;
  dplaces(arr,n,d);
  cout << "rotated array is : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// OPTIMAL APPROACH -> "REVERSAL ALGORITHM"
// ROTATING D PLACES TO THE LEFT BY USING REVERSAL ALGORTIHM
// TC -> O(2N) BUT SC -> O(1)
#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr,int start,int end){
  while(start <= end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
void reversal(vector<int> &arr,int n,int d){
  // reverse till d places
  reverse(arr,0,d-1); // TC -> O(D)
  // reverse from d to n places
  reverse(arr,d,n-1); // TC -> O(N-D)
  // reverse the whole array
  reverse(arr,0,n-1); // TC -> O(N)
}
int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  int n = arr.size();
  int d;
  cout << "enter d : " << endl;
  cin >> d;
  reversal(arr,n,d);
  cout << "after using reversal algorithm : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}

// ROTATING D PLACES TO THE RIGHT BY USING REVERSAL ALGORITHM
#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr,int start,int end){
  while(start <= end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
void reversal(vector<int> &arr,int n,int d){
  // reverse from end k places
  reverse(arr,n-d,n-1);
  // reversing from 0 to n-k-1 places
  reverse(arr,0,(n-d)-1);
  // reversing from 0 to n-1
  reverse(arr,0,n-1);
}
int main(){
   vector<int> arr = {1,2,3,4,5,6,7};
  int n = arr.size();
  int d;
  cout << "enter d : " << endl;
  cin >> d;
  reversal(arr,n,d);
  cout << "after using reversal algorithm(rotating right) : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}

// RIGHT ROTATE BY D PLACES
// BRUTE FORCE
#include<bits/stdc++.h>
using namespace std;
void dplaces(vector<int> &arr,int n,int d){
  // if d>n then
  d = d % n;
  // storing the d number of elements in temp array
  vector<int> temp;
  for(int i=n-d; i<n; i++){
    temp.push_back(arr[i]);
  }
  // shifting
  for(int i=n-d-1; i>=0 ; i++){
    arr[i+d] = arr[i];
  }
  // push back the temp array elements to main array
  for(int i=0; i<d-1; i++){
    arr[i] = temp[i];
  }
}
int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  int n = arr.size();
  int d;
  cout << "enter d : " << endl;
  cin >> d;
  dplaces(arr,n,d);
  cout << "rotated array is : " << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// Q) MOVE ALL ZEROS TO THE END OF THE ARRAY
// brute force method
// TC -> O(2N) & SC -> O(X)
#include<bits/stdc++.h>
using namespace std;
void move(vector<int> &arr,int n){
  // store all non zeros numbers in temp array
  // TC -> O(N)
  vector<int> temp;
  for(int i=0; i<n; i++){
    if(arr[i] != 0){
      temp.push_back(arr[i]);
    }
  }
  // iterate through array to insert non zero numbers at start
  // TC -> O(X)
  for(int i=0; i<temp.size(); i++){
    arr[i] = temp[i];
  }
  // fill the remaining indexes with 0
  // TC -> O(N-X)
  for(int i=temp.size(); i<n; i++){
    arr[i] = 0 ;
  }
}
int main(){
  vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
  int n = arr.size();
  move(arr,n);
  cout << "moved to end" << endl;
  for(int i=0; i<n; i++){
      cout << arr[i] << " ";
  }
}
// optimal method
// TC -> O(N) & SC -> O(1)
#include<bits/stdc++.h>
using namespace std;
void move(vector<int> &arr,int n){
  // find j
  int j = -1;
  for(int i=0; i<n; i++){
    if(arr[i]==0){
      j = i;
      break;
    }
  }
  // handling the case where there are no zeroes
  if(j==-1) return;
  // find i
  for(int i=j+1; i<n; i++){
    if(arr[i] != 0){
      swap(arr[i],arr[j]);
      j++;
    }
  }
}
int main(){
  vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
  int n = arr.size();
  move(arr,n);
  cout << "moved to end (optimal approach) " << endl;
  for(int i=0; i<n; i++){
      cout << arr[i] << " ";
  }
}
// LINEAR SEARCH 
#include<bits/stdc++.h>
using namespace std;
int linear(vector<int> &arr,int n,int num){
  int flag = -1;
  int key;
  for(int i=0; i<n; i++){
    if(arr[i] == num){
      key = i;
      flag = 1;
      break;
    }
  }
  if(flag == 1){
    return key;
  }
  else return -1;
}
int main(){
  vector<int> arr = {1,0,2,3,2,0,0,4,5,1};
  int n = arr.size();
  int num;
  cout << "number you want to find : " << endl;
  cin >> num;
  cout << "the index at which number is present " << linear(arr,n,num);
}
// Q) UNION OF THE TWO SORTED ARRAYS
// BRUTE FORCE APPROACH
#include<bits/stdc++.h>
using namespace std;
void union1(vector<int> &arr1,vector<int> &arr2,int n1,int n2){
  // declaring set and traversing both array and storing it
  set<int> st;
  for(int i=0; i<n1; i++){
    st.insert(arr1[i]);
  }
  for(int i=0; i<n2; i++){
    st.insert(arr2[i]);
  }
  // making union array and storing all elements of set
  vector<int> union2;
  int i = 0;
  for(auto it: st){
    union2[i] = it;
    i++;
  }
  // print the array
  for(int i=0; i<union2.size(); i++){
    cout << union2[i] << " ";
  }
}
int main(){
  vector<int> arr1 = {1,2,3,4,5};
  vector<int> arr2 = {2,1,3,2,4,5,6};
  int n1 = arr1.size();
  int n2 = arr2.size();
  union1(arr1,arr2,n1,n2);
  return 0;
}
// OPTIMAL METHOD
// TC -> O(N1+N2) & SC -> O(N1+N2) which is the worst case and is used for returing the array & for solving the problem it is using the SC -> O(1)
#include<bits/stdc++.h>
using namespace std;
void union1(vector<int> &arr1,vector<int> &arr2,int n1,int n2){
  int i = 0;
  int j = 0;
  vector<int> unionArr;
  while(i<n1 && j<n2){
    if(arr1[i] <= arr2[j]){
      if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
        unionArr.push_back(arr1[i]);
      }
      i++;
    }
    else{
      if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
        unionArr.push_back(arr2[j]);
      }
      j++;
    }
  }
  // if i got exhausted
  while(j<n2){
    if(unionArr.size() == 0 || unionArr.back() != arr2[j]){
      unionArr.push_back(arr2[j]);
    }
    j++;
  }
  // if j got exhausted
  while(i<n1){
    if(unionArr.size() == 0 || unionArr.back() != arr1[i]){
      unionArr.push_back(arr1[i]);
    }
    i++;
  }
}
int main(){
  vector<int> arr1 = {1,2,3,4,5};
  vector<int> arr2 = {2,1,3,2,4,5,6};
  int n1 = arr1.size();
  int n2 = arr2.size();
  union1(arr1,arr2,n1,n2);
  return 0;
}
// INTERSECTION OF THE TWO ARRAYS
// brute force 
