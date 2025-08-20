#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
vector<int> createArray(){
  int n;
  cout << "Enter number of elements for array." << endl;
  cin >> n;
  vector<int> arr;
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    arr.push_back(val);
  }
  return arr;
}
void displayArray(vector<int> &arr){
  cout << "Created array is.." << endl;
  for(int val : arr){
    cout << val << " ";
  }
  cout << endl;
}
void insertInArray(vector<int> &arr){
  int el , position;
  cout << "Enter element to insert : " << endl;
  cin >> el;
  cout << "Enter position to insert element : " << endl;
  cin >> position;
  int n = arr.size();
  arr.push_back(0);
  for(int i=n; i>position; i--){
    arr[i] = arr[i-1];
  }
  arr[position] = el ;
}
void deleteFromArray(vector<int> &arr){
  int position;
  cout << "Enter position : " << endl;
  cin >> position;
  int n = arr.size();
  for(int i=position; i<n-1; i++){
    arr[i] = arr[i+1];
  }
  arr.pop_back();
}
void linearSearch(vector<int> &arr){
  int n = arr.size();
  int elFound = 0;
  int el , idx;
  cout << "Enter element to find : " << endl;
  cin >> el;
  for(int i=0; i<n; i++){
    if(arr[i] == el){
      elFound = 1;
      idx = i;
      break;
    }
  }
  if(elFound == 1){
    cout << "Element " << el << " found at index " << idx << endl;
  }
}
int main(){
  while(true){
    int option;
    cout << "Enter option : ";
    cin >> option;
    // vector<int> arr;
    switch(option){
      case 1:
        // create function
        arr = createArray();
        break;
      case 2:
        // display function
        displayArray(arr);
        break;
      case 3:
        // insert function
        insertInArray(arr);
        displayArray(arr);
        break;
      case 4:
        // delete function
        deleteFromArray(arr);
        displayArray(arr);
        break;
      case 5:
        // linear search
        linearSearch(arr);
        break;
      case 6:
        return 0;
      default:
        cout << "Invalid option" << endl;
    }
  }
  return 0;
}