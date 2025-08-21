#include<iostream>
#include<string>
using namespace std;
string sortStringAlphabetically(string word){
  int n = word.size();
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(word[j] > word[j+1]){
        // swap adjacent elements
        char temp = word[j+1];
        word[j+1] = word[j];
        word[j] = temp;
      }
    }
  }
  return word;
}
int main(){
  string name = "Shubham Rout";
  cout << sortStringAlphabetically(name) << endl;
  return 0;
}
// time complexity will be O(n^2) 
// outer loop will run for O(n) and inner loop on an average run loop for O(n)
// space complexity of this code will be O(1) -> no extra space is being used