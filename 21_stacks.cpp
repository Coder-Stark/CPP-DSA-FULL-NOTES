//STACKS

#include<iostream>
#include<stack>
using namespace std;

/*
int main(){

    //create a stack
    stack<int>s;

    //push
    s.push(5);
    s.push(4);

    //pop
    s.pop();

    //top element
    cout<<"The top element of stack is : "<<s.top()<<endl;

    //empty
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"Stack is non empty "<<endl;
    }

    //size
    cout<<"The size of stack is : "<<s.size()<<endl;

    return 0;

}
*/
/*OUTPUTS
The top element of stack is : 5
Stack is non empty
The size of stack is : 1
*/


//IMPLEMENTATION OF STACK

class Stack{
    //properties
    public:
    int *arr;
    int size;
    int top;

    //behaviour/function
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    //push
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow "<<endl;
        }
    }

    //pop
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow "<<endl;
        }
    }

    //peek/top element show
    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack Empty "<<endl;
            return -1;
        }
    }

    //empty
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    
    Stack st(4);
    
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is Empty "<<endl;
    }
    else{
        cout<<"Stack is Not Empty "<<endl;
    }

}

/*OUTPUTS
3
2
1

Stack Empty
-1

Stack is Empty 
*/


//TWO STACKS
class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        arr = new int[s];
        top1 = -1;
        top2 = s;
        this->size = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};


/*OUTPUTS
Sample Input 1:
3 5
1 1 3
1 2 4
1 1 5
2 1
2 2
Sample Output 1:
5
4
*/


//REVERSE A STRING USING STACK
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "Shivam";
    stack <char> s;

    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout<<"Answer is : "<<ans<<endl;

    return 0;
}

/*OUTPUTS
Answer is : mavihS
*/

//DELETE MIDDLE ELEMENT FROM STACK
/*
void solve(stack<int>&inputStack,int count , int size){
   //base case
   if(inputStack == size/2){
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   //recursive call
   solve(inputStack , count+1 , N);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack,int count, int N){
	
   int count = 0;
   solve(inputStack , n);
   
}
*/
/*OUTPUT(EXPECTED)
Sample Input 1:
2
4
1 2 3 4 5
7
83 74 67 49 94 8 11 1
Sample Output 1:
1 2 4 5
83 74 67 94 8 11 1
*/


//VALID PARNTHESIS
bool isValidParenthesis(string expression)
{
    stack<char>s;

    for(int i = 0 ; i < expression.length() ; i++){
        char ch = expression[i];

        //if open bracket
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else{ 
            //closing bracket
            if (!s.empty()) {
              char top = s.top();
              if (ch == ')' && top == '(' || ch == ']' && top == '[' ||
                  ch == '}' && top == '{') {
                s.pop();
              } else {
                return false;
              }
            } else {
              return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

/*OUTPUTS
Sample Input 1 :
2
[()]{}{[()()]()}
[(])
Sample Output 1 :
Balanced
Not Balanced
*/


//INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK   (T.C = O(N))
void solve(stack<int>&s , int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    //recursive call
    solve(s , x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack , x);
    return myStack;
}

/*
Sample Input 1 :
2
3 8
4 3 2
4 5
6 2 4 9
Sample Output 1 :
8 4 3 2
5 6 2 4 9
*/


//REVERSE STACK USING RECURSION   (T.C == O(N2))
void insertAtBottom(stack<int>&s , int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, x);
    s.push(num);
}
void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);
    insertAtBottom(stack ,num);
}

/*
Sample Input 1 :
3
2 1 3 
Sample Output 1 :
2 1 3                //first element shows top element
*/


//SORT A STACK                  (T.C == O(N2))

void sortedInsert(stack<int> &s , int num){
	//base case
	if(s.empty() || (!s.empty() && s.top() < num)){
		s.push(num);
		return;
	}
	int n = s.top();
	s.pop();

	//recursive call
	sortedInsert(s , num);
	s.push(n);
}
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return;
	}
	int num = stack.top();
	stack.pop();

	//recursive call
	sortStack(stack);
	sortedInsert(stack , num);
}
/*OUTPUT
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
*/
