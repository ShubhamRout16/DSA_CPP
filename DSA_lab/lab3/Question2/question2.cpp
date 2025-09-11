#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverseStrStack(string &str){
  stack<char> charstr;

  for(char c : str){
    charstr.push(c);
  }

  for(int i=0; i<str.length(); i++){
    str[i] = charstr.top();
    charstr.pop();
  }
};

int main(){
  string str;
  cout << "Enter the input string : " << endl;
  getline(cin,str);

  cout << "String before reversing : " << str << endl;

  reverseStrStack(str);

  cout << "Reversed String : " << str << endl;
  return 0;
}