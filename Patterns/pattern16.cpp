#include<iostream>
using namespace std;
void pattern16(int n){
  int num = 65;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      cout << (char)num << " ";
    }
    num = num + 1;
    cout << endl;
  }
};
class Solution{
public:
    void pattern_16(int n){
      int num = 65;
      for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
          cout << (char)num << " ";
        }
        num = num + 1;
        cout << endl;
      }
    }
};
int main(){
  int t;
  cin >> t; 
  for(int i=0; i<t; i++){
    int n;
    cin >> n;
    Solution obj;
    obj.pattern_16(n);
    pattern16(n);
  }
  return 0;
}