#include<iostream>
using namespace std;
void pattern7(int n){
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
class Solution{
public:
  void pattern_7(int n){
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
};
int main(){
  int t;
  cin >> t; 
  for(int i=0; i<t; i++){
    Solution obj;
    int n;
    cin >> n;
    obj.pattern_7(n);
    // pattern7(n);
  }
} 