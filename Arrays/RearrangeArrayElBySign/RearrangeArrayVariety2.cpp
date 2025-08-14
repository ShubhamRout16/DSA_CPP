// the problem statement -> in this varieety the number of positive elements and negative elements are not equal , we have to rearrange elements
// alternately and for the remaining elements arrange them in the same order as they were in the array.

#include<iostream>
#include<vector>
using namespace std;
vector<int> RearrangeElementsVar2(vector<int> &nums){
  int n = nums.size();
  vector<int> pos;
  vector<int> neg;
  // segregate the array into positive array and negative array
  for(int i=0; i<n; i++){
    if(nums[i] > 0) pos.push_back(nums[i]);
    else neg.push_back(nums[i]);
  }

  // if positive elements are less than negative elements
  if(pos.size() < neg.size()){
    // first fill the array till the positive elements and negative elements are equal in number
    for(int i=0; i<pos.size(); i++){
      nums[2*i] = pos[i];
      nums[2*i+1] = neg[i];
    }
    // filled the remaining negative elements at the end of the array
    int index = pos.size()*2;
    for(int i=pos.size(); i<neg.size(); i++){
      nums[index] = neg[i];
      index++;
    }
  }

  // if positive elements are greater than negative elements
  else{
    // first fill the array till the negative elements
    for(int i=0; i<neg.size(); i++){
      nums[2*i] = pos[i];
      nums[2*i+1] = neg[i];
    }
    // fill the remaining positive elements at the end of the array
    int index = neg.size()*2;
    for(int i=neg.size(); i<pos.size(); i++){
      nums[index] = pos[i];
      index++;
    }
  }

  return nums;
}
int main(){
  int n;
  cout << "Enter the number of elements." << endl;
  cin >> n;
  vector<int> nums;
  for(int i=0; i<n; i++){
    int val;
    cin >> val;
    nums.push_back(val);
  }
  vector<int> result = RearrangeElementsVar2(nums);
  // print the result array
  for(int val: result){
    cout << val << " ";
  }
  return 0;
}
// time complexity of this method 
// O(N) + O(min(pos,neg)) + O(leftovers)
// O(min(pos,neg)) -> will have two cases 
// one -> when all there are only positive and negative elements present
// then O(min(pos,neg)) + O(leftovers) = O(0) + O(N)
// second -> when there will be equal number of positive and negative elements
// then O(min(pos,neg)) + O(leftovers) = O(N/2) + O(0)
// so from these cases the worst complexity  will be O(N)
// so final time complexity will be O(N) + O(N) -> O(2N)

// space complexity will be -> O(N)
// because for storing negative elements it take space of -> O(N/2)
// similarly for storing of the positive elements it will take -> O(N/2)