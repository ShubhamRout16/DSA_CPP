// MERGE SORT ->divide and merge
// TC -> O(nlogn) -> at each step we are dividing the whole array thats why logn and it will take n steps thats why nlogn
// SC-> O(n) -> we are using temporary array to store elements in sorted array
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int low, int high){
  vector<int> temp;
  int mid = (low+high)/2;
  int left = low; //left pointer
  int right = mid+1; //right pointer
  while(left<=mid && right<=high){
    if(arr[left]<=arr[right]){
      temp.push_back(arr[left]);
      left++;
    }
    else{
      temp.push_back(arr[right]);
      right++;
    }
  }
  // exhausted case
  while(left<=mid){
    temp.push_back(arr[left]);
    left++;
  }
  while(right<=high){
    temp.push_back(arr[right]);
    right++;
  }
  // copying the elements of temp array into main array
  for(int i=low; i<=high; i++){
    arr[i] = temp[i-low];
  }
}
void merge_sort(vector<int> &arr,int low, int high){
  // base case
  if(low>=high) return;
  // mid
  int mid = (low+high)/2;
  // dividing and sort the left half
  merge_sort(arr,low,mid);
  // dividing and sorting the right half
  merge_sort(arr,mid+1,high);
  // merging
  merge(arr,low,high);
}
int main(){
  vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
  int n  = 7;
  merge_sort(arr,0,n-1);
  cout << "after merge sort" << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// QUICK SORT -> quick sort is slightly better than merge sort
// TC -> O(nlogn) & SC -> O(1) it doesnt uses any extra temp array for sorting thats why its slightly better than merge sort
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int low ,int high){
  int pivot = arr[low];
  int i = low;
  int j = high;
  while(i<j){
    while(arr[i]<=arr[pivot] && i<=high-1){
      i++;
    }
    while(arr[j]>arr[pivot] && j>=low+1){
      j--;
    }
    if(i<j) swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]);
  return j;
}
void qs(vector<int> &arr,int low,int high){
  if(low<high){
    int pIndex = partition(arr,low,high);
    qs(arr,low,pIndex-1);
    qs(arr,pIndex+1,high);
  }
}
vector<int> quicksort(vector<int> arr){
    qs(arr,0,arr.size()-1);
    return arr;
}
int main(){
  vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
  int n = arr.size();
  arr = quicksort(arr);
  cout << "after quicksort" << endl;
  for(int i=0; i<n; i++){
      cout << arr[i] << " ";
  }
}