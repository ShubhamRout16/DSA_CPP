#include<iostream>
using namespace std;
void pascalTriangleVar2(int r ){
  int ans = 1;
  cout << ans << " " ;
  for(int i=1; i<r; i++){
    ans = ans * (r-i);
    ans = ans / i ;
    cout << ans << " ";
  }
  return;
}
int main(){
  int R;
  cout << "Enter row : " << endl;
  cin >> R;
  pascalTriangleVar2(R);
  return 0;
}
// time complexity will be O(R) -> where R is the number of columns
// space complexity is O(1) -> no extra space is beign used