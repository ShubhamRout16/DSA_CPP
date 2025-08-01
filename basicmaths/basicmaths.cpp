// PROBLEMS RELATED TO COUNTING DIGITS
// #include<bits/stdc++.h>
// using namespace std;
// int countDigits(int n){
//   int cnt = 0;
//   while(n>0){
//     cnt++;
//     n = n/10;
//   }
//   return cnt;
// }
// int main(){
//   int N;
//   cout << "enter the number: ";
//   cin >> N;
//   cout << "Number of digits is: " << countDigits(N) << endl;
//   return 0;
// }

// #include <bits/stdc++.h>
// #include <iostream>
// #include <cmath> // for log10 function
// using namespace std;
// int countDigits2(int n){
//   int cnt;
//   cnt = (int)(log10(n) + 1);
//   return cnt;
// }
// int main(){
//   int N;
//   cin >> N;
//   cout << countDigits2(N) << endl;
//   return 0;
// }


// time compleity of this code is O(log10(N)) 
// whenever in the code it is being dividded by 10 then TC will be O(log10(N)) if it is being divide by 5 then TC will be O(log5(N)) if it divided by n times then TC will be O(logn(N))
// where n -> is the number of times being divided and N -> the number given by the user


// GFG PROBLEM -> https://www.geeksforgeeks.org/problems/count-digits5716/1
// #include<iostream>
// using namespace std;
// int evenDigits(int n){
//   int og = n;
//   int evenCnt = 0;
//   while(n>0){
//     int d;
//     d = n % 10;
//     if(d != 0 && og % d == 0){
//       evenCnt++;
//     }
//     n = n/10;
//   }
//   return evenCnt;
// }
// int main(){
//   int N;
//   cout << "enter the number : ";
//   cin >> N;
//   cout << "the even number of digits which divides : " << evenDigits(N) << endl; 
//   return 0;
// }

// PROBLEMS RELATED TO REVERSING A NUMBER
// #include<iostream>
// using namespace std;
// int revNum(int n){
//   int rev = 0 , lastdgt;
//   while(n > 0){
//     lastdgt = n % 10 ;
//     rev = (rev * 10) + lastdgt;
//     n = n/10;
//   }
//   return rev;
// }
// int main(){
//   int N;
//   cout << "Enter the number to reverse : ";
//   cin >> N;
//   cout << "The number reversed is : " << revNum(N) << endl; 
//   return 0;
// }

// check palindrome
// #include<iostream>
// using namespace std;
// int revNum(int n){
//   int rev = 0,lastdigit;
//   while(n>0){
//     lastdigit = n % 10;
//     n = n/10;
//     rev = (rev * 10) + lastdigit ;
//   }
//   return rev;
// }
// int checkPalindrome(int chckp,int og){
//   if(chckp == og){
//     cout << "OG num is palindrome";
//   }
//   else{
//     cout << "not palindrome";
//   }
// }
// int main(){
//   int n;
//   cout << "enter OG num";
//   cin >> n;
//   int saveOg = n ;
//   int gotrev = revNum(n);
//   checkPalindrome(gotrev,saveOg);
//   return 0;
// }

// check armstrong
// #include<iostream>
// using namespace std;
// int rev(int n){
//   int revn = 0 , lastdgt , sum = 0;
//   while(n>0){
//     lastdgt = n % 10;
//     sum = sum + (lastdgt * lastdgt * lastdgt);
//     n = n/ 10;
//     revn = ( revn * 10 ) + lastdgt;
//   }
//   return sum;
// }
// int main(){
//   int n;
//   cout << "enter original number";
//   cin >> n;
//   int gotsum = rev(n);
//   if(gotsum == n){
//     cout << "the og is armstrong";
//   }
//   else{
//     cout << "the og is not armstrong";
//   }
//   return 0;
// }

// print all the divisors of the given number
// brute force method -> TC IS O(n)
// always think brute force -> better -> optimal
// #include <iostream>
// using namespace std;
// int printalldiv(int n){
//   for(int i=1; i<n; i++){
//     if(n % i == 0){
//       cout << i << " ";
//     }
//   }
//   return 0;
// }
// int main(){
//   int n; 
//   cout << "enter original number";
//   cin >> n;
//   printalldiv(n);
// }

// another method
// #include <iostream>
// #include <vector>
// #include <math.h>
// #include <algorithm>
// using namespace std;
// int printalldiv(int n){
//   vector <int> ls;
//   for(int i=1; i<= sqrt(n); i++){
//     if(n%i == 0){
//       ls.push_back(i);
//       if((n/i) != i){
//         ls.push_back (n/i);
//       }
//     }
//   }
//   sort(ls.begin(),ls.end());
//   for(auto it : ls) cout << it << " ";
//   return 0;
// }
// int main(){
//   int n;
//   cout << "enter original number";
//   cin >>  n ;
//   printalldiv(n);
//   return 0;
// }

// check number is prime or not
// what is prime number? -> number containing 2 factors having 1 and itself.
// extreme brute force method
// TC -> O(N)
// #include <iostream>
// using namespace std;
// int checkprime(int n){
//   int count;
//   for(int i=1; i<=n; i++){
//     if(n % i == 0){
//       count++;
//     }
//   }
//   if(count == 2){
//     cout << "the original number is prime";
//   }else{
//     cout << "the original number is not prime";
//   }
//   return 0;
// }
// int main(){
//   int n;
//   cout << "enter original number";
//   cin >> n;
//   checkprime(n);
//   return 0;
// }
// better method than brute force method
// TC -> O(sqrt(N))
// #include<iostream>
// #include<math.h>
// using namespace std;
// int checkprime(int n){
//   int count;
//   for(int i=1; i<=sqrt(n); i++){  //we can also write i*i<=n works same as i<=sqrt(n)
//     if(n % i == 0){
//       count++; 
//       if((n/i) != i){
//         count++;
//       }
//     }
//   }
//   if(count == 2){
//     cout << "the given number is prime number";
//   }
//   else{
//     cout << "the given number is not prime number";
//   }
//   return 0;
// }
// int main(){
//   int n;
//   cout << "enter original number";
//   cin >> n;
//   checkprime(n);
//   return 0;
// }

// GCD/HCF
// brute force case -> TC -> O(min(n1,n2))
// #include<iostream>
// using namespace std;
// int min(int n1, int n2){
//   if(n1 < n2) return n1;
//   else return n2;
// }
// int findgcd(int n1,int n2){
//   int gcd = 1 ; // all numbers have 1 as a common divisor
//   for(int i=1; i<= min(n1,n2); i++){
//     if(n1 % i == 0 && n2 % i == 0){
//      gcd = i ;
//     }
//   }
//   cout << "gcd is " << gcd << endl;
//   return gcd;
// }
// int main(){
//   int n1,n2;
//   cout << "enter n1" << " ";
//   cin >> n1;
//   cout << "enter n2";
//   cin >> n2;
//   findgcd(n1,n2);
//   return 0;
// }
// improved method -> better for cases where  n1 = 20 and n2 = 40 saves TC and not good for cases such as n1 = 11 and n2 =  13
// #include <iostream>
// using namespace std;
// int min(int n1, int n2){
//   if(n1 < n2) return n1;
//   else return n2;
// }
// int findgcd(int n1 , int n2){
//   int gcd = 1;
//   for(int i=min(n1,n2); i>=1; i--){
//     if(n1 % i == 0 && n2 % i == 0){
//       gcd = i;
//       break;
//     }
//   }
//   cout << "gcd is " << gcd;
//   return gcd;
// }
// int main(){
//   int n1,n2; 
//   cout << "enter n1" << endl;
//   cin >> n1;
//   cout << "enter n2" << endl;
//   cin >> n2;
//   findgcd(n1,n2);
//   return 0;
// }
// EUCLIDEAN ALGORITHM
// #include<iostream>
// using namespace std;
// int eualgofindgcd(int n1 , int n2){
//   int gcd = 1;
//   while(n1 > 0 && n2 > 0){
//     if(n1 > n2) n1 = n1 % n2;
//     else n2 = n2 % n1 ;
//   }
//   if(n1 == 0) gcd = n2;
//   else gcd = n1;
//   cout << "gcd is " << gcd;
//   return gcd;
// }
// int main(){
//   int n1, n2;
//   cout << "enter n1" << endl;
//   cin >> n1;
//   cout << "enter n2" <<  endl;
//   cin >> n2;
//   eualgofindgcd(n1,n2);
//   return 0;
// }