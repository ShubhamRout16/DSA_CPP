#include <iostream>
#include <vector>
using namespace std;
int linearSearch(vector <int> &vec , int n , int element){
  int index;
    for(int i=0; i<n; i++){
      if(vec[i] == element){
        index = i;
      }
    }
    return index;
}
int main(){
  int n;
  cout << "Enter number of elements" << endl;
  cin >> n;
  vector<int> vec;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    vec.push_back(val);
  }
  int element;
  cout << "Enter the element to find.\n";
  cin >> element;
  int index = linearSearch(vec , n , element);
  cout << "Element found at index " << index << endl;
  return 0;
}