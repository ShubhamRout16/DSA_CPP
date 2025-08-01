// Q) PRINT NAME N TIMES USING RECURSION
// recursion using parameterised method and without using global variable
// TC -> O(N) & SC -> O(N)
#include<iostream>
using namespace std;
void printnames(int i , int n){
  if(i>n) return ;
  else{
    cout << "shubham" << endl;
    printnames(i+1,n);
  }
}
int main(){
  int n;
  cout << "enter the number of times" << endl;
  cin >> n;
  printnames(1,n);
  return 0;
}
// Q) PRINT LINEARLY FROM 1-N USING RECURSION
#include <iostream>
using namespace std;
void printnum(int i, int n){
  if(i>n) return;
  else{
    cout << i << " ";
    printnum(i+1,n);
  }
}
int main(){
  int n;
  cout << "enter the number of times";
  cin >> n;
  printnum(1,n);
  return 0;
}
// Q) PRINT IN THE TERMS OF N-1 (my method)
#include<iostream>
using namespace std;
void numprint(int i, int n){
  if(i>n) return;
  else{
    cout << n << " ";
    n--;
    numprint(1,n);
  }
}
int main(){
  int n;
  cout << "enter the number of times";
  cin >> n;
  numprint(1,n);
  return 0;
}
// strivers method
#include<iostream>
using namespace std;
void numprint2(int i , int n){
  if(i<1) return ;
  else{
    cout << i << " ";
    numprint2(i-1,n);
  }
}
int main(){
  int n;
  cout << "enter the numbers of times";
  cin >> n;
  numprint2(n,n);
  return 0;
}
// Q) PRINT FROM 1-N USING BACKTRACKING
#include<iostream>
using namespace std;
void backnum(int i, int n){
  if(i<1) return;
  else{
    backnum(i-1,n);
    cout << i << " ";
  }
}
int main(){
  int n;
  cout << "enter the number of times";
  cin >> n;
  backnum(n,n);
  return 0;
}
// Q) PRINT FROM N-1 USING BACKTRACKING
#include<iostream>
using namespace std;
void backnum2(int i, int n){
  if(i>n) return;
  else {
    backnum2(i+1,n);
    cout << i << " ";
  }
}
int main(){
  int n;
  cout << "enter the number of times";
  cin >> n;
  backnum2(1,n);
  return 0;
}

// Parameterised way and Functional way of summation of N Numbers
// Parameterised method
#include<iostream>
using namespace std;
void m1(int i, int sum){
  if(i<1){
    cout << "sum is" << sum;
    return;
  }
  else{
    m1(i-1,sum+i);
  }
}
int main(){
  int n;
  cout << "enter the original number";
  cin >> n;
  m1(n,0);
  return 0;
}

// Functional way
#include<iostream>
using namespace std;
int f(int n){
  if(n == 0) return 0;
  else return n + f(n-1);
}
int main(){
  int n;
  cout << "enter the original number";
  cin >> n;
  cout << "sum is " << f(n);
  return 0;
}

// recursive code for factorial of n
#include<iostream>
using namespace std;
int f(int n){
  if(n==1) return 1;
  else return n * f(n-1);
}
int main(){
  int n;
  cout << "enter the number for factorial";
  cin >> n;
  cout << "factorial is " << f(n);
  return 0;
}

// parameterised code for factorial of n
#include<iostream>
using namespace std;
void fac(int i, int fact){
  if(i<1){
    cout << "factorial is " << fact ;
  }else{
    fac(i-1,fact*i);
  }
}
int main(){
  int n;
  cout << "enter original number";
  cin >> n ;
  fac(n,1);
  return 0;
}

// Reversing a array using recursion
// using two pointers
#include<bits/stdc++.h>
using namespace std;
void reverse(int l, int arr[], int r){
  if(l>=r) return;
  else{
    swap(arr[l],arr[r]);
    reverse(l+1,arr,r-1);
  }
}
int main(){
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  reverse(0,arr,n-1);
  cout << "new array" << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}
// also solve this using single pointers
#include<bits/stdc++.h>
using namespace std;
void reverse1(int i ,int a[],int n){
  if(i>(n/2)) return;
  else{
    swap(a[i],a[n-i-1]);
    reverse1(i+1,a,n);
  }
}
int main(){
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(a[0]);
  reverse1(0,a,n);
  cout << "new array" << endl;
  for(int i=0; i<n; i++){
      cout << a[i] << " ";
  }
  return 0;
}

// check whether the given string is palindrome or not
#include<bits/stdc++.h>
using namespace std;
bool palcheck(int i, string &s){
  if(i>=s.size()/2) return true;
  if(s[i] != s[s.size() - i -1]) return false;
  return palcheck(i+1,s);
}
int main(){
  string s = "madsm";
  cout << palcheck(0,s); // 1 -> true & 0-> false
  return 0;
}

// multiple recursive calls on fibonaaci series
#include<bits/stdc++.h>
using namespace std;
int f(int n){
  if(n<=1) return n;
  int last = f(n-1);
  int slast = f(n-2);
  return last + slast;
}
int main(){
  int n;
  cout << "enter the fibonnaci term";
  cin >> n;
  cout << f(n);
  return 0;
}