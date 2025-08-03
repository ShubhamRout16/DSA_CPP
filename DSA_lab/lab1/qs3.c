// predict the output of the code
#include <stdio.h>
int main(){
  int arr[5] = {1};
  int size = sizeof(arr) / sizeof(arr[0]);
  for(int i=0; i<size; i++){
    printf("%d ", arr[i]);
  }
  return 0;
}
// remaining elements are automatically defaulty initialised as 0