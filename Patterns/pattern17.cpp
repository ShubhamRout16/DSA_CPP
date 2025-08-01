#include<iostream>
using namespace std;
void pattern17(int n){
  for(int i=0; i<n; i++){
    int num = 65;
    // space
    for(int j=0; j<n-i-1; j++){
      cout << " ";
    }
    // char
    for(int j=0; j<2*i+1; j++){
      // note - focus on this part
      int breakpoint = (2*i+1)/2;
      cout << (char)num ;
      if(j<breakpoint) num = num + 1;
      else num = num - 1;
    }
    // space
    for(int j=0; j<n-i-1; j++){
      cout << " ";
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
    pattern17(n);
  }
  return 0;
}