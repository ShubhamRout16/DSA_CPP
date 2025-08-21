#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string deleteVowels(string word){
  int n = word.size();
  string result;
  for(int i=0; i<n; i++){
    char ch = tolower(word[i]);
    if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
      result += word[i];
    }
  }
  return result;
}
int main(){
  string word = "Abide";
  cout << deleteVowels(word) << endl;
  return 0;
}
// time complexity of this code will be -> O(n)
// space complexity of this code will be -> O(n)