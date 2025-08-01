#include<iostream>
using namespace std;
void pattern3(int n){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        cout << j;
      }
      cout << endl;
    }
}
class Solution{
public:
  void pattern3(int n){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        cout << j;
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
    obj.pattern3(n);
    pattern3(n);
  }
}