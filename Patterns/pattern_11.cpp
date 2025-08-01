#include<iostream>
using namespace std;
class  Solution{
public:
    void pattern_11(int n){
      int start = 1;
      for(int i=0; i<n; i++){
        if(i%2==0) start = 1;
        else start = 0;
        for(int j=0; j<=i; j++){
          cout << start;
          start = 1 - start ; // flipping
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
    obj.pattern_11(n);
  }
  return 0;
}