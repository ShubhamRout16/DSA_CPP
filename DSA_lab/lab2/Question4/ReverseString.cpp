#include<iostream>
#include<string>
using namespace std;
string reverseString(string name){
  int n = name.size();
  int start = 0;
  int end = n - 1;
  while(start < end){
    char temp = name[end];
    name[end] = name[start];
    name[start] = temp;
    start++;
    end--;
  }
  return name;
}
int main(){
  string name = "Shubham Rout";
  cout << reverseString(name) << endl;
  return 0;
}
// time complexity of this code will be O(N/2) -> the loop will run till the middle of the array
// space complexity of this code will be O(1)