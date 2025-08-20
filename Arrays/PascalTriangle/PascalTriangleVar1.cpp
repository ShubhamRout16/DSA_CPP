#include<iostream>
#include<vector>
using namespace std;
int NCR(int n , int r){
  long long res = 1;
  for(int i=0; i<r; i++){
    res = res * (n-i);
    res = res / (i+1);
  }
  return res;
}
int main(){
  int R;
  cout << "Enter row : " << endl;
  cin >> R;
  int C;
  cout << "Enter column : " << endl;
  cin >> C;
  cout << "Element found is : " << NCR(R-1 , C-1) << endl;
  return 0;
}
// time complexity will be O(r) which is (C-1) because we are running loop for r times
// space complexity will be O(1) because no extra space has been used