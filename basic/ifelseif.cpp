#include<iostream>
using namespace std;

class Solution {
public:
    void studentGrade(int marks) {
        if(marks >= 90){
            cout << "Grade A";
        }
        else if(marks >= 70){
            cout << "Grade B";
        }
        else if(marks >= 50){
            cout << "Grade C";
        }
        else if(marks >= 35){
            cout << "Grade D";
        }
        else{
            cout << "Fail";
        }
    }
};
int main(){
    int marks;
    cout << "Enter the students marks :" << endl;
    cin >> marks;
    Solution obj;
    obj.studentGrade(marks);
    return 0;
}