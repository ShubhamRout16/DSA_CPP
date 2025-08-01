#include<iostream>
using namespace std;
void pattern18(int n){
  for(int i=0; i<n; i++){
    for(int j=69-i; j<=69; j++){
      cout << (char)j << " ";
    }
    cout << endl;
  }
};
int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int n;
    cin >> n;
    pattern18(n);
  }
  return 0;
}