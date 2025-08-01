#include<iostream>
using namespace std;
void pattern15(int n){
  for(int i=1; i<=n; i++){
    int num = 65;
    for(int j=i; j<=n; j++){
      cout << (char)num << " ";
      num = num +1;
    }
    cout << endl;
  }
};
class Solution{
public:
    void pattern_15(int n){
      for(int i=1; i<=n; i++){
        int num = 65;
        for(int j=i; j<=n; j++){
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
    obj.pattern_15(n);
    pattern15(n);
  }
  return 0;
}