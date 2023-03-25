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
/*
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
*/


//REDUNDANT BRACKET                      (T.C == O(N))    

bool findRedundantBrackets(string &s)
{
    stack<char>st;

    for(int i = 0 ; i < s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
/*
Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes
*/


//MINIMUM COST TO MAKE STRING VALID          (T.C == O(N) , S.C == O(N))
int findMinimumCost(string str) {
    //odd condition
    if(str.length()%2 == 1){
        return -1;
    }

    stack<char>s;
    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        } else {
          // for closing bracket '}'
          if(!s.empty() && s.top() == '{'){
              s.pop();
          }
          else{
              s.push(ch);
          }
        }
    }
    //stack contain invalid expression
    int a = 0 , b = 0;                 //a == opening bracket, b == closing bracket
    while(!s.empty()){
        if(s.top()== '{'){
            a++;
        }
        else{
            b++;
        }
        s.pop();
    }
    int ans = (a + 1)/2 + (b + 1)/2;
    return ans;
}
/*
Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0
*/


//NEXT SMALLER ELEMENT          (T.C == O(N)        
#include<vector>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);

    vector<int>ans(n);
    for(int i = n-1 ; i >=0 ; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
/*
Sample Input 1:
2
4
2 1 4 3
3
1 3 2
Sample Output 1:
1 -1 3 -1
-1 2 -1
*/


//LARGEST RECTANGULAR AREA IN HISTOGRAM       (T.C == O(N) 
#include<limits.h>
class Solution {
private:
    vector<int>nextSmallerElement(vector<int>arr , int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);

        for(int i = n-1 ; i >= 0 ; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans is stack's top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>arr , int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);

        for(int i = 0 ; i < n ; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            //ans is stack's top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>next(n);
        next = nextSmallerElement(heights , n);

        vector<int>prev(n);
        prev = prevSmallerElement(heights , n);

        int area = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area , newArea);
            
        }
        return area;
    }
};
/*
Input: heights = [2,1,5,6,2,3]
Output: 10
*/


//THE CELEBRITY PROBLEM
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a , int b, int n){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        
        //put all elements in stack
        for(int i = 0 ; i < n ; i++){
            s.push(i);
        }
        
        //get 2 person and compare them
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        //single element left verify it , as a celebraty
        int ans = s.top();
        
        //row check
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(M[ans][i] == 0){
                zeroCount++;
            }
        }
        
        //all zero
        if(zeroCount == n){
            rowCheck = true;
        }
        
        //column check
        bool colCheck = false;
        int oneCount = 0;
        for(int i = 0 ; i < n ; i++){
            if(M[i][ans] == 1){
                oneCount++;
            }
        }
        
        //allone
        if(oneCount == n-1 ){
            colCheck = true;
        }
        
        
        if(rowCheck == true && colCheck == true){
            return ans;
        }
        else{
            return -1;
        }
    }
};
/*
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
*/


//N STACK IN AN ARRAY             (T.C == O(N) , S.C == O(N + S)
class NStack
{
    int *arr;
    int *top;
    int *next;
    int n , s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top initialize
        for(int i = 0 ; i < n ; i++){
            top[i] = -1;
        }

        //next initialize
        for(int i = 0 ; i < s; i++){
            next[i] = i+1;
        }

        //update last index value to -1
        next[s-1] = -1;

        //freespot initialize
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freespot == -1){
            return false;
        }
        //find index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //insert element into array
        arr[index] = x;

        //update next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};
/*
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True 
True
True
20
30
*/


// DESIGN A STACK THAT SUPPORTS GETMIN() IN O(1) TIME AND O(1) EXTRA SPACE
class SpecialStack {
    // Define the data members.
    stack<int>s;
    int mini;

    public:
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        else{
            int curr = s.top();
            s.pop();
            if(curr > mini){
                return curr;
            }
            else{
                int prevMini = mini;
                int val = 2*mini - curr;
                mini = val;

                return prevMini;
            }
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};
/*
Sample Input 1:
6
1 13
1 47
5
4
2
3
Sample Output 1:
13
false
47
13
*/