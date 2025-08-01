// SELECTION SORT -> Selecting minimum and swapping
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int N){
  // step 1 -> outer loop range
  for(int i=0; i<N; i++){
    // step 2 -> find minimum element of the range
    int min = i ; // assuming first element of range is minimum
    for(int j=i+1; j<N; j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    // step 3 -> swap the minimum element with first element of the range
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
  // step 4 -> check the sorted array
  cout << "after selection sort" << endl;
  for(int i=0; i<N; i++){
    cout << arr[i] << " ";
  }
}
int main(){
  int arr[] = {13,46,24,52,20,9};
  int N = sizeof(arr)/sizeof(arr[0]);
  selection_sort(arr,N);
  return 0;
}

// BUBBLE SORT -> put the max element at last by adjacent swapping
#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[], int N){
  // for best case where the given array is already sorted 
  int didswap = 0;
  // step1 -> range of the unordered array
  for(int i=N-1; i>=0; i--){
    // step2 -> range for pushing the last element to last index by adjacent swapping
    for(int j=0; j<=i-1; j++){ // we didnt run j<=i because after for last element it will compare with next element which is nothing and will give runtime error
      if(arr[j]>arr[j+1]){
        // step3 -> swapping the adjacent element
        swap(arr[j],arr[j+1]);
        didswap = 1;
      }
    }
    // check for best case
    if(didswap == 0){
    break;
    }
  }
  // step4 -> check the sorted array
  cout << "after bubble sort" << endl;
  for(int i=0; i<N; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  if(didswap == 0){
      cout << "hit the best case with swaps = " << didswap;
  }
}
int main(){
  // int arr[] = {9,13,20,24,46,52}; for best case
  int arr[] = {13,46,24,52,20,9};
  int N = sizeof(arr)/sizeof(arr[0]);
  bubble_sort(arr,N);
  return 0;
}
// similarly for this bubble sort the TC -> O(N^2) which is the worst case 
// OPTIMIZED CASE (best case) TC -> O(N)

// INSERTION SORT ->select a element and put its correct order
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int N){
  // step -> interate through the array by selecting each element and putting it in its correct order
  for(int i=0; i<N; i++){
    int j = i;
    while(j>0 && arr[j-1]>arr[j]){
      swap(arr[j-1],arr[j]);
      j--;
    }
  }
  cout << "array after insertion sort" << endl;
  for(int i=0; i<N; i++){
    cout << arr[i] << " ";
  }
}
int main(){
  // int arr[] = {9,13,20,24,46,52}; for best case
  int arr[] = {13,46,24,52,20,9};
  int N = sizeof(arr)/sizeof(arr[0]);
  insertion_sort(arr,N);
  return 0;
}
// TC -> O(N^2) worst case
// TC -> O(N) best case
