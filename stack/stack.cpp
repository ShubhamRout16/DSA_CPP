#include<iostream>
using namespace std;

class Stack{
  public:
  int size;
  int top;
  int *s;

  void push(Stack *st, int x){};
  int pop(Stack *st){};
  int peek(Stack st , int pos){};
  int isEmpty(Stack st){};
  int isFull(Stack st){};
  int StackTop(Stack st){};
};

void Stack :: push(Stack *st, int x){
  if(st->top == st->size - 1){
    cout << "Stack overflow" << endl;
  }
  else{
    st->top++;
    st->s[st->top] = x;
  }
};

int Stack :: pop(Stack *st){
  int x = -1;

  if(st->top == -1){
    cout << "Stack underflow" << endl;
  }
  else{
    x = st->s[st->top];
    st->top--;
  }
  return x;
};

int Stack :: peek(Stack st , int pos){
  int x = -1;
  if(st.top - pos - 1 < 0) cout << "Invalid position" << endl;
  else x = st.s[st.top - pos +1];
  return x;
}

int Stack :: isEmpty(Stack st){
  if(st.top == -1) return 1;
  else return 0;
}

int Stack :: isFull(Stack st){
  if(st.top == st.size - 1) return 1;
  else return 0;
}

int Stack :: StackTop(Stack st){
  int x = -1;
  if(st.top == -1) return -1;
  else{
    return st.s[st.top];
  }
}

int main(){
  Stack st;
  cout << "Enter the size of the stack : " << endl;
  cin >> st.size;
  st.s = new int[st.size];
  st.top = -1;
  int x;
  cout << "Enter element to push : " << endl; cin >> x;
  st.push(&st,x);

  st.pop(&st);
  return 0;
}

/*
---------- stack  condition ----------
if(top == -1) stack is empty
if(top == size - 1) stack is full 
*/