#include<iostream>
using namespace std;

// implementation of the max heap using array
class MaxHeap{
  int *arr;
  int size; // tells the total number of elements currently in the heap
  int total_size; // tell the total size of the array

  public:
  MaxHeap(int n){
    arr = new int[n];
    size = 0;
    total_size = n;
  }

  void insert(int value){
    // check if heap size is available or not for insertion
    if(size == total_size){
      cout << "Heap Overflow" << endl;
      return;
    }
    // insert the element at the last of the array
    arr[size] = value;
    int index = size;
    size++;
    // check if the currently inserted element is in its right position or not
    while(index > 0 && arr[(index-1)/2] < arr[index]){
      // compared if the currently inserted element is greater than its parent or not and swapped their position if true
      swap(arr[index],arr[(index-1)/2]);
      index = (index-1)/2;
    };
    cout << arr[index] << " is inserted in the heap" << endl;
  }
  void print(){
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
  }

  void Heapify(int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    // largest will the store the index of the element which is greater than parent , lchild and rchild
    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;

    if(largest != index){
      swap(arr[index],arr[largest]);
      Heapify(largest);
    }
  }

  void Delete(){
    if(size == 0){
      cout << "Heap underflow" << endl;
      return;
    }

    // max heap ka top node delete hota ha 
    cout << arr[0] << " deleted from the heap";
    arr[0] = arr[size-1];
    size--;
    if(size == 0) return;
    Heapify(0);
  }
};

int main(){
  MaxHeap H1(6);
  H1.insert(4);
  H1.insert(20);
  H1.insert(37);
  H1.insert(90);
  H1.print();
  return 0;
}