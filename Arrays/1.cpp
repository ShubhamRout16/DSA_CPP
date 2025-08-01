// Q) FIND THE LARGEST ELEMENT IN THE ARRAY
// brute force method
// TC -> O(nlogn) & SC -> O(n)
#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr,int n){
  // using sort method
  sort(arr.begin(),arr.end());
  return arr[n-1];
}
int main(){
  vector<int> arr = {1,8,7,56,90};
  int n = arr.size();
  cout << "largest element using sort " << largest(arr,n);
  return 0;
}
// optimal method 
// TC -> O(n) & SC-> 0(1)
#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr,int n){
  int max = arr[0];
  for(int i=0; i<n; i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}
int main(){
  vector<int> arr = {1,8,7,56,90};
  int n = arr.size();
  largest(arr,n);
  return 0;
}
// Q) FIND THE SECOND LARGEST ELEMENT OF THE ARRAY
// brute force method
// TC -> O(NLOGN + N) -> nlogn will be due to sort algortihm and n will be due to for loop running n times
#include<bits/stdc++.h>
using namespace std;
int second_largest(vector<int> &arr,int n){
  sort(arr.begin(),arr.end());
  int max = arr[n-1];
  int smax;
  for(int i=n-1; i>0; i--){
    if(arr[i]<max && arr[i]!=max){
      smax = arr[i];
      break;
    }
  }
  return smax;
}
int main(){
  vector<int> arr = {1,2,4,7,5,7};
  int n = arr.size();
  cout<< "smax is " << second_largest(arr,n);
  return 0;
}
// better approach 
// TC -> O(2N) 
#include<bits/stdc++.h>
using namespace std;
int slargest(vector<int> &arr,int n){
  // first pass TC -> O(N)
  int largest = arr[0];
  for(int i=0; i<n; i++){
    if(arr[i]>largest){
      largest = arr[i];
    }
  }
  // second pass TC -> O(N)
  int largest2 = -1;
  for(int i=0; i<n; i++){
    if(arr[i]>largest2 && arr[i]!=largest){
      largest2 = arr[i];
    }
  }
  return largest2;
}
int main(){
  vector<int> arr = {1,2,4,7,5,7};
  int n = arr.size();
  cout << "better approach second largest " << slargest(arr,n);
  return 0;
}
// OPTIMAL APPROACH  -> in optimal approach everything will be done in a single pass
// if there is any negative number in the test case of the a given array then -> slargest = INT_MIN
// TC -> O(N)
#include<bits/stdc++.h>
using namespace std;
int slargest(vector<int> &arr,int n){
  int largest = arr[0];
  int largest2 = -1;
  for(int i=0; i<n; i++){
    if(arr[i]>largest){
      largest2 = largest;
      largest = arr[i];
    }
    else if(arr[i]>largest2 && arr[i]!=largest){
      largest2 = arr[i];
    }
  }
  return largest2;
}
int main(){
  vector<int> arr = {1,2,4,7,5,7};
  int n = arr.size();
  cout << "optimal approach second largest " << slargest(arr,n);
  return 0;
}
// FIND THE SECOND SMALLEST 
// TC -> O(N)
#include<bits/stdc++.h>
using namespace std;
int ssmallest(vector<int> &arr,int n){
  int smallest = arr[0];
  int smallest2 = INT_MAX;
  for(int i=0; i<n; i++){
    if(arr[i]<smallest){
      smallest2 = smallest;
      smallest = arr[i];
    }
    else if(arr[i] != smallest && arr[i] < smallest2){
      smallest2 = arr[i];
    }
  }
  return smallest2;
}
int main(){
  vector<int> arr = {1,2,4,7,5,7};
  int n = arr.size();
  cout << "optimal approach second smallest " << ssmallest(arr,n);  
  return 0;
}
// Q) CHECK IF AN ARRAY IS SORTED OR NOT 
// there is no brute ,better or optimal solution of this
#include<bits/stdc++.h>
using namespace std;
int sortcheck(vector<int> &arr,int n){
  for(int i=1; i<n; i++){
    if(arr[i] > arr[i-1]){

    }
    return false;
  }
  return true;
}
int main(){
  vector<int> arr = {1,2,2,3,3,1};
  int n = arr.size();
  cout << " the given array is sorted true(1)/false(0) : " << sortcheck(arr,n);
  return 0;
}
// Q)REMOVE THE DUPLICATE IN PLACE FROM THE SORTED ARRAY
// BRUTE FORCE APPROACH
// first pass will have TC -> NLOGN & second pass will have TC -> N total TC -> O(NLOGN+N);
// SC -> O(N) 
#include<bits/stdc++.h>
using namespace std;
int duplicates(vector<int> &arr,int n){
  // first pass - > all the unique elements will go in set
  set<int> st;
  for(int i=0; i<n; i++){
    st.insert(arr[i]);
  }
  // store the number of unique elements stored in set and later return it
  int k = st.size();
  // second pass -> traverse through set and put all elements back into modified array
  int index = 0;
  for(auto it: st){
    arr[index] = it;
    index++;
  }
  return k;
}
int main(){
  vector<int> arr = {1,1,2,2,2,3,3};
  int n = arr.size();
  int k = duplicates(arr,n);
  cout << "modified array is : " << endl;
  for(int i=0; i<k; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// OPTIMAL APPROACH
// TC -> O(N) AND SC-> O(1)
#include<bits/stdc++.h>
using namespace std;
int remove_duplicates(vector<int> &arr,int n){
  int i = 0;
  for(int j=1; j<n; j++){
    if(arr[j] != arr[i]){
      arr[i+1] = arr[j];
      i++;
    }
  }
  // number of unique elements
  return i+1;
}
int main(){
  vector<int> arr = {1,1,2,2,2,3,3};
  int n = arr.size();
  int k = remove_duplicates(arr,n);
  cout << "modified array is : " << endl;
  for(int i=0; i<k; i++){
    cout << arr[i] << " ";
  }
  return 0;
}