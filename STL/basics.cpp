// #include<iostream>
// #include<list>
// #include <set>
#include<bits/stdc++.h>
using namespace std;
void explainPair(){
  // making pair of int and int 
  // we can make pair of any datatypes
  // we can also create a pair inside of another pair => nested pair.
  // after accessing every datatypes from the we have to print " " (space).
  // on creating nested pairs we dont use make_pair constructor.
  // make_pair is used to automatically understand the type of datatypes inside of pair
  pair<int,int> pr1 = make_pair(2,8);
  cout << pr1.first << " " << pr1.second << endl;

  pair<int,char> pr2 = make_pair(2,'s');
  cout << pr2.first << " " << pr2.second << endl;

  pair<pair<int,char>,int> pr3 = {{2,'s'},4};
  cout << pr3.first.second << " " << pr3.second << " " << pr3.first.first << endl;

  cout << "Pairs done!" << endl;
};
void explainVector(){
  // vector is a container.
  // in normal array we can not change the size of the array after decalaring it.
  // but with vector which is dynamic array we can do several functions which normal array cant do.
  //vector having array of int with variable name vec.
  // in vector push_back and emplace_back do the same thing.
  // vector also follows zero based indexing.
  vector<int> vec; 
  vec.push_back(1);
  vec.push_back(3);
  vec.emplace_back(4);

  // printing vector
  for(int i=0; i<vec.size(); i++){
    cout << vec[i] << " ";
  }

  cout << endl;
  // iterator :-
  // it is a pointer which takes the location of arrays element.
  // vec.begin() it access the location of the first element of the array
  // vec.end() it access the location of the end which is after the last element.

  vector<int>::iterator beginItr = vec.begin(); // location of 1
  vector<int>::iterator endItr = vec.end(); // location after 4
  cout << *beginItr << endl; // 1
  cout << *endItr << endl; // 0 

  // note:- we dont use i<=endItr since endItr access location after the last element.
  // so the loop will run from start to end automatically.
  for(vector<int>::iterator i=beginItr; i<endItr; i++){
    cout << *i << " "; // [1,3,4]
  }
  cout << endl;

  endItr = endItr - 1; // this will access the location of element before last element.
  for(vector<int>::iterator i=beginItr; i<=endItr; i++){
    cout << *i << " "; // [1,3,4]
  }
  cout << endl;

  // NOTE:- we can also skip these types of initialisation by using {auto iterator}
  // vector<int>::iterator beginItr = vec.begin();
  // vector<int>::iterator endItr = vec.end(); 
  // auto is the type of iterator which can automatically initialise the type of iterator according to the type of datatype of vector.
  auto beginItr2 = vec.begin();
  auto endItr2 = vec.end();
  cout << *beginItr2 << endl;

  for(auto i: vec){
    cout << i << " ";
  }
  cout << endl;
  cout << "does the same thing but makes shit easier!" << endl;

  // Reverse iterator:- use to print the array in reverse order.
  auto reverseBegin = vec.rbegin();
  auto reverseEnd = vec.rend();
  for(auto i=reverseBegin; i<reverseEnd; i++){
    cout << *i << " ";
  }

  cout << endl;
  // so we did not tell the vector what values it contains hence it will print 0.
  vector<int>vec2(5);
  vec2.push_back(3);
  vec2.push_back(2);
  vec2.push_back(4);

  // 0 0 0 0 0 3 2 4
  for(auto i: vec2){
    cout << i << " ";
  }

  cout << endl;
  
  // this time we told the vector to print 8 , 5 times before pushing any element
  vector<int>vec3(5,8);
  vec3.push_back(3);
  vec3.push_back(2);
  vec3.push_back(4);

  for(auto i: vec3){
    cout << i << " "; // 8 8 8 8 8 3 2 4
  }
  
  cout << endl; 

  vector<int> dupVec(vec3);
  for(auto i: dupVec){
    cout << i << " "; // 8 8 8 8 8 3 2 4
  }

  cout << endl; 

  // now if we want to print only from second 8 onwards
  vector<int> dupVec2(vec3.begin() + 1 , vec3.end());
  for(auto i: dupVec2){
    cout << i << " "; // 8 8 8 8 3 2 4
  }

  cout << endl; 

  // to erase a element from the vector
  vector<int> v;
  v.push_back(50);
  v.push_back(100);
  v.push_back(200); 
  // it will create a dynamic array of {50,100,200}
  v.erase(v.begin() + 1); //{50,200};
  for(auto i: v){
    cout << i << " ";
  }
  cout <<  endl;
  v.push_back(300);
  v.push_back(250);
  v.push_back(400);
  // {50,200,300,250,400}
  cout << "new dynamic array";
  cout << endl;
  for(auto i: v){
    cout << i << " ";
  }
  cout << endl;
  // if we want to delete the range of elements from the dynamic array
  v.erase(v.begin() + 1 , v.begin() + 3 ); //{50,250,400} [start,end) , start is included but end is not included.
  for(auto i: v){
    cout << i << " ";
  }

  // How to insert a function inside of an vector
  vector<int >v(2,100); //{100,100}
  v.insert(v.begin(),300); //{300,100,100}
  v.insert(v.begin()+1,2,10); //{300,10,10,100,100} , v.insert(start,number of times,the value want to enter).


  cout << v.size(); // give the number of elements inside the vector array
  
  vector<int> v2; // v2 -> {10,20}
  v2.push_back(10);
  v2.push_back(20);

  vector <int> v3; // v3 -> {30,40}
  v3.push_back(30);
  v3.push_back(40);

  v2.swap(v3); //v2 -> {30,40} and v3 -> {10,20}

  v.clear(); // clears the entire array 

  v.empty(); // returns a boolean value true or false 
  // even if there is one value inside of vector array it will return false.
};
void explainList(){
  list<int> ls;
  ls.push_back(2); //{2}
  ls.emplace_back(4); // {2,4}
  ls.push_front(2); // in cpp list is doublely linked list and its cost friendly according to time and space complexity
  // {2,2,4} whereas in vector insert is a single linked list
}
void explainDeque(){
  deque<int>dq;
  dq.push_back(1); //{1}
  dq.emplace_back(2); //{1,2}
  dq.push_front(4); //{4,1,2}
  dq.emplace_front(3); //{3,4,1,2}
  dq.pop_back(); //{3,4,1} pops from back
  dq.pop_front(); //{4,1} pops from front
  dq.back(); // lets us access the last element of deque
  dq.front(); // lets us access the first element of deque
}
void explainStack(){
  // stack is LIFO -> last in first out
  // stack has 3 functions -> push,pop,top
  // all the operations in stacks are working in O(1) -> constant time
  stack<int> st;
  st.push(1); // {1}
  st.push(2); // {2,1}
  st.push(3); // {3,2,1}
  st.push(3); // {3,3,2,1}
  st.emplace(5); // {5,3,3,2,1}
  cout << st.top(); // prints 5 -> in stack there is no st[2] like is array it will give us error
  st.pop(); //removes 5 from the stack and new stack looks like {3,3,2,1}
  cout << st.top(); //3
  cout << st.size(); //4
  cout << st.empty(); //false
  stack<int> st1,st2;
  st1.swap(st2);
}
void explainQueue(){
  // queue is similar to stack and works in FIFO -> first iin first out
  queue<int> q;
  q.push(1);// {1}
  q.push(2);// {1,2}
  q.emplace(4);// {1,2,4}
  q.back() += 5; // {1,2,9}

  cout << q.back(); // prints 9
  q.pop(); // pops 1st element
  cout << q.front(); // prints 2
  // size , swap , empty are same as stack
}
void explainPQ(){
  // Priority Queue 
  // in priority queue the largest element remains at top whether it is strings , character or integers
  // the time complexity for the functions of priority queue
  // push -> occurs in log n
  // top -> occurs in O(1)
  // pop -> occurs in log n
  priority_queue<int>pq;
  pq.push(5); //{5}
  pq.push(2); //{5,2}
  pq.push(8); //{8,5,2}
  pq.push(10); //{10,8,5,2}
  cout << pq.top(); // prints 10
  pq.pop(); // pops 10 from the queue {8,5,2}
  cout << pq.top(); // prints 8
  // size swap and empty functions are same as others

  // Minimum heap
  // minimum heap is the type of priority queue which stores the minimum element at the top
  priority_queue<int , vector<int> , greater<int>>pq;
  pq.push(5); // {5}
  pq.push(2); // {2,5}
  pq.push(8); // {2,5,8}
  pq.emplace(10); // {2,5,8,10}
  cout << pq.top(); //prints 2
}
void explainSet(){
  // Set -> stores everything in a sprted order and unique
  // it stores only unique elements and doesnt stores the duplicate element
  set<int> st;
  st.insert(1); //{1}
  st.insert(2); //{1,2}
  st.emplace(2); //{1,2}
  st.insert(4); //{1,2,4}
  st.insert(3); //{1,2,3,4}

  // {1,2,3,4,5}
  auto it = st.find(3); // points the iterator which points to the 3.
  auto it = st.find(6); // if it tells to find the element which is not present , then in that case it points to st.end() -> points to the cursor after the ending element
  st.erase(3); //erases 3 and takes log n time to complete the process

  int cnt = st.count(3); // if present will count the times of occurrence as 1 and if not present then it will count the time of occurrence to be 0
  
  // we can give the element of the set to erase the element or we can give the iterator of the element for which to erase the element
  // time takes to complete the process is O(1) -> constant time
  auto it = st.find(3);
  st.erase(it); 

  // {1,2,3,4,5}
  auto it1 = st.find(2);
  auto it2 = st.find(4);
  st.erase(it1,it2); // after erase {1,4,5} [first,end)

  // lower_bound() and upper_bound() works in the same way as it does in the vector
  auto it = st.lower_bound(2);
  auto it = st.upper_bound(3);
}
void explainMultiSet(){
  // everything is same as set 
  // but it can store multiple occurrences of any number in the set
  // stores element in the sorted order
  multiset<int>ms;
  ms.insert(1); // {1}
  ms.insert(1); // {1,1}
  ms.insert(1); // {1,1,1}

  ms.erase(1); // it will erase all the 1's present in the multiset

  int cnt = ms.count (1); // it will count the total number of 1's present in the set

  ms.erase(ms.find(1)); // it will only erase the first occurrence of 1 from the set
  ms.erase(ms.find(1), std::next(ms.find(1) , 2));
  // about next functions used : std::next is a utility function from the <iterator> library in C++. It advances a given iterator by a specified number of steps and returns a new iterator, without modifying the original iterator.
  // this code will erase (st,end) and output returned will be {1} 
}
void explainUSet(){
  unordered_set<int> st;
  // lower_bound and upper_bound function does not work in the unordered set and rest of the functions works normally
  // it does not store any element in the ordered manner
  // normally it takes a time complexity of O(1)
  // but in the worst case it can take a time complexity of  O(N)
}
void explainMap(){
  // map is the datastructure which stores value in the format of keys and values where key can be of any datatype and value can be also of any datatype 
  // but the key should be unique and value can be duplicated it wont matter
  // map stores unique keys in the sorted order
  map <int , int> mpp;
  // map <int , pair<int,int>> mpp;
  // map <pair<int,int> , int> mpp;

  mpp[1] = 2 ; // stores {1,2}
  mpp.emplace(3,1);
  mpp.insert({2,4});

  for(auto it : mpp){
    cout << it.first << " " << it.second << endl;
  }

  cout << mpp[1];
  cout << mpp[5];

  auto it = mpp.find(5); // since there is no 5 it will point to the end and after the set

  auto it = mpp.lower_bound(2);
  auto it = mpp.upper_bound(3);
}
void explainMultimap(){
  // it stores duplicate keys in the sorted order
  // generally stores in the time complexity of log(N)
}
bool comp(pair<int,int> p1, pair<int,int> p2){
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false;

  if(p1.first > p2.first) return true;
  return false;
}
void explainExtra(){
  // if there is an array {4,3,1,5,6} and if we use
  int a[4] = {4,2,1,3};
  sort(a,a+4); // then it will sort the array in ordered manner
  // if we are using any vector then we can use
  vector <int> v;
  sort(v.begin(),v.end());
  int b[5] = {1,2,3,6,5} ; // and we only want to sort 6,5
  sort(b+4,b+5);
  // sort(b, b+n , greater<int>()); //if we want to sort in the descending order

  // it is a myway type of sorting where we can sort simultaneouslly increasing and decreasing
  pair<int,int> c[] = {{1,2}, {2,1}, {4,1}};
  // sort it according to second element
  // if second element is same,then sort
  // it according to first element but in descending
  int n = sizeof(c) / sizeof(c[0]);
  sort(c, c+n , comp); // where comp is the self written comparator which is boolean function

  // {{4,1}, {2,1}, {1,2}};

  int num = 7;
  int cnt = __builtin_popcount(num); //it will count the number of said bits in num 
  // since num = 7 whose binary is 111 so cnt will give 3 and if num = 6 whose binary is 110 then cnt would have returned 2

  long long num = 165786578689;
  int cnt = __builtin_popcountll(num);

  string s = "123";
  sort(s.begin(),s.end());
  do{
    cout << s << endl;
  }while(next_permutation(s.begin() , s.end()));

  int maxi = *max_element(a,a+n);
}
int main(){
  explainPair();
  explainVector();
  explainList();
  explainDeque();
  explainStack();
  explainPQ();
  explainSet();
  explainMultiSet();
  explainUSet();
  explainMap();
  explainMultimap();
  explainExtra();
  return 0;
}