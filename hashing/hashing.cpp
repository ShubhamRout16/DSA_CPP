// imagine we are given a array a[]={1,2,3,1,4,3} -> array has atmax of 3 which are (1,2,3)
// and we are asked how many times 1 appears 2 appears and so on
//  1-> 2times how to find it?
// brute force method
#include<bits/stdc++.h>
using namespace std;
int times(int n, int a[],int N){
  int count = 0;
  for(int i=0; i<N; i++){
    if(a[i]==n){
      count++;
    }
  }
  return count;
}
int main(){
  int n;
  cout << "enter the number you want to find" << endl;
  cin >> n;
  int a[]={1,2,3,1,4,3};
  int N = sizeof(a)/sizeof(a[0]);
  cout << "no of times is" << " " << times(n,a,N);
}
// and what will be the TC?
// TC for one number is O(N) , and if there are Q numbers we have to find then TC will be O(Q * N)
// assume Q = 10^5 and size of arr (N) = 10^5 then TC will be O(10^5 * 10^5) =O(10^10)
// TC for 10^8 is 1sec then TC for 10^10 will be 100sec which is huge amount of time for code to run 
// and here comes HASHING which helps in shortening the time taking process
// HASHING -> pre storing/fetching
#include<bits/stdc++.h>
using namespace std;
int main(){
  // size of the array
  int n;
  cout << "enter the size of the array" << endl;
  cin >> n ;

  // array of given set of elements
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  
  // pre compute
  // make hash array
  int hash[13] = {0};
  for(int i=0; i<n; i++){
    hash[arr[i]] += 1;
  }

  // no of queries
  int q;
  cout << "enter the no of queries";
  cin >> q;

  // queries & fetching
  while(q--){
    int number;
    cin >> number;
    // fetching
    cout << hash[number] << endl;
  }
  return 0;
}
// Character hashing 
// brute force method for the counting the number of times elements
#include<bits/stdc++.h>
using namespace std;
int count(char ch, string &s){
  int cnt =0;
  for (int i=0; i<s.size(); i++){
    if(s[i] == ch){
      cnt++;
    }
  }
  return cnt;
}
int main(){
  string s = "abcdababa";
  char ch;
  cout << "enter the charcater you want to find ";
  cin >> ch;
  cout << "no of times " << " " << count(ch,s);
  return 0;
}

// character hashing
// for lowercase letters
#include<bits/stdc++.h>
using namespace std;
int main(){
  // define string 
  string s;
  cout << "enter string";
  cin >> s;

  // pre compute
  int hash[26] = {0};
  for(int i=0; i<s.size(); i++){
    hash[s[i]-'a'] += 1;
  }

  // queries and fetching
  int q;
  cout << "enter the number of queries" << endl;
  cin >> q;
  while(q--){
    char ch;
    cin >> ch;
    // fetching
    cout << hash[ch-'a'] << endl;
  }
  return 0;
}
// if the exclusivity of the characters is not provided 
#include<bits/stdc++.h>
using namespace std;
int main(){
  // define string 
  string s;
  cout << "enter string";
  cin >> s;

  // pre compute
  int hash[256] = {0};
  for(int i=0; i<s.size(); i++){
    hash[s[i]] += 1;
  }

  // queries and fetching
  int q;
  cout << "enter the number of queries" << endl;
  cin >> q;
  while(q--){
    char ch;
    cin >> ch;
    // fetching
    cout << hash[ch] << endl;
  }
  return 0;
}

// hashing using maps
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  // pre compute 
  map<int,int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }

  // iterating through map
  for(auto it: mpp){
    cout << it.first << "->" << it.second << endl;
  }
  int q;
  cin >> q;
  while(q--){
    int number;
    cin >> number;
    // fetch
    cout << mpp[number] << endl;
  }
}