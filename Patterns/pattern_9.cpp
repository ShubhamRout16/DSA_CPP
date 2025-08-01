#include<iostream>
using namespace std;
class Solution{
public:
    void pattern77(int n){
      for(int i=0; i<n; i++){
        // space
        for(int j=0; j<n-i-1; j++){
          cout << " ";
        }
        // star
        for(int j=0; j<2*i+1; j++){
          cout << "*";
        }
        // space
        for(int j=0; j<n-i-1; j++){
          cout << " ";
        }
        cout << endl;
      }
    }
    void pattern88(int n){
      for(int i=0; i<n; i++){
        // space
        for(int j=0; j<i; j++){
          cout << " ";
        }
        // star
        for(int j=0; j<2*n-(2*i+1); j++){
          cout << "*";
        }
        // space
        for(int j=0; j<i; j++){
          cout << " ";
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
    obj.pattern77(n);
    obj.pattern88(n);
  }
  return 0;
}