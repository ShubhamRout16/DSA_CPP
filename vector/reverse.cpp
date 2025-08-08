#include <iostream>
#include <vector>
using namespace std;
void reverseArr(vector <int> &vec , int n){
  int start = 0;
  int end = n-1; 
  while(start < end){
    int temp = vec[start];
    vec[start] = vec[end];
    vec[end] = temp;
    start++;
    end--;
  }
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
  reverseArr(vec , n);

  cout << "reversed array." << endl;
  for(int val: vec){
    cout << val << " ";
  }
  cout << endl;
  return 0;
}