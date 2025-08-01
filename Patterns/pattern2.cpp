#include<iostream>
using namespace std;
void pattern2(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      cout << "*";
    }
    cout << endl;
  }
}
class Solution{
public:
    void pattern_2(int n){
      for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
          cout << "*";
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
    obj.pattern_2(n);
    pattern2(n);
  }
  return 0;
}