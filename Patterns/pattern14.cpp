#include<iostream>
using namespace std;
void pattern14(int n){
    for(int i=1; i<=n; i++){
      int num = 65;
      for(int j=1; j<=i; j++){
        cout << (char)num << " ";
        num = num + 1;
      }
      cout << endl;
    }
};
class Solution{
public:
    void pattern_14(int n){
      for(int i=1; i<=n; i++){
        int num = 65;
        for(int j=1; j<=i; j++){
          cout << (char)num << " ";
          num = num + 1;
        }
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
    obj.pattern_14(n);
    pattern14(n);
  }
}