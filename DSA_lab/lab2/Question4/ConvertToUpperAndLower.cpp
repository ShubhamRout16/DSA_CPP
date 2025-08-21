#include<iostream>
#include<string>
using namespace std;
string convertToUpper(string word){
  int n = word.size();
  for(int i=0; i<n; i++){
    if(word[i] >= 'a' && word[i] <= 'z'){
      // convert to uppercase
      word[i] = word[i] - 32 ;
    }
  }
  return word;
}
string convertToLower(string word){
  int n = word.size();
  for(int i=0; i<n; i++){
    if(word[i] >= 'A' && word[i] <= 'Z'){
      // convert to lowercase
      word[i] = word[i] + 32;
    }
  }
  return word;
}
int main(){
  string name = "Shubham Rout";
  cout << convertToUpper(name) << endl;
  cout << convertToLower(name) << endl;
  return 0;
}
// Core concept is that
// to convert to uppercase -> subtract -> 32
// to convert to lowercase -> add -> 32