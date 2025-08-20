#include<iostream>
#include<vector>
using namespace std;
int main(){
  int arr[5] = {1};
  for(int i=0; i<5; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// only first element is initialized as 1
// the rest of the elements are automatically initialised to 0