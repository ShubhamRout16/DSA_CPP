
#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter number of elements : " << endl;
  cin >> n;
  
  int N;
  cout << "Enter the range : " << endl;
  cin >> N;
  
  int arr[n];
  cout << "Enter array elements : " << endl;
  for(int i=0; i<n; i++){
      cin >> arr[i];
  }
  
  cout << "current elements are : " << endl;
  for(int i=0; i<n; i++){
      cout << arr[i] << " ";
  }
  cout << endl;
  
  // logic here for linear time complexity
  int expectedSum = (N * (N+1)) / 2 ;
  int arrSum = 0;
  for(int i=0; i<n; i++){
      arrSum += arr[i];
  }
  
  int missingNum = expectedSum - arrSum;
  
  cout << "Missing number in the range " << N << " is " << missingNum << endl;
  
  
  return 0;
}
// solve this problem in linear time complexity -> O(n)