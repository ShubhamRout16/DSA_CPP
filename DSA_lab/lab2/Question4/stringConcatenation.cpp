#include<iostream>
#include<string>
using namespace std;
int main(){
  // using two different strings to concatenate
  string s1 = "Shubham ";
  string s2 = "Rout";
  string result = s1 + s2;
  cout << result << endl;

  // using the append function
  string s3 = "Shubham ";
  s3.append("Rout");
  cout << s3 << endl;

  // concatenating directly
  cout << "Shubham " << "Rout" << endl;
  return 0;
}