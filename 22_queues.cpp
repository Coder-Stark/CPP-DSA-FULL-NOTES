//QUEUES                     

#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<"The size of queue is : "<<q.size()<<endl;
    cout<<"The front element of queue is : "<<q.front()<<endl;

    q.pop();
    cout<<"The size of queue is : "<<q.size()<<endl;
    cout<<"The front element of queue is : "<<q.front()<<endl;

    cout<<q.empty()<<endl;

    if(q.empty()){
        cout<<"Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    //DOUBLY ENDED QUEUE
    deque<int>d;

    d.push_front(12);
    d.push_back(14);
    
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();

    if(d.empty()){
        cout<<"Doubly Ended Queue is empty"<<endl;
    }
    else{
        cout<<"Doubly Ended Queue is not empty"<<endl;
    }


}
/*OUTPUT
The size of queue is : 3
The front element of queue is : 1      
The size of queue is : 2
The front element of queue is : 2      
0
Queue is not empty

//DOUBLY ENDED QUEUE
12
14
14
14
Doubly Ended Queue is empty
*/
 
//IMPLEMENT QUEUE                       (T.C == O(1))                  

class Queue {
        int *arr;
        int size;
        int rear;
        int qfront;
public:
    Queue() {
        size = 10001;
        arr = new int[size] ;
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};
/*
Sample Input 1 :
1
7
1 17
1 23
1 11
2
2
2
2
Sample Output 1 :
17
23
11
-1
*/


//CIRCULAR QUEUE                          (T.C == O(1))   
#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:

    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value){

        //to check queue is full
        if((front == 0 && rear == size-1) ||(rear == (front-1)%(size-1))){
            // cout<<"Queue is full"<<endl;
            return false;
        }

        //first element to push
        else if (front == -1){
            front = rear = 0;
        }

        //push in between array / queue maintain cyclic nature 
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;                  //normal flow
        }

        //push inside the queue
        arr[rear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){

        //check queue is empty
        if(front == -1){
            // cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        //single element is present
        if(front == rear){
            front = rear = -1;
        }

        //to maintain cyclic nature
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;                    //normal condition                   
        }
        return ans;
    }
};
/*
Sample Input 1:
3 7
1 2 
1 3 
2 
1 4 
1 6 
1 7 
2
Sample Output 1:
True 
True
2
True
True
False
3
*/


//IMPLEMENT DEQUE(DOUBLY ENDED QUEUE)                                (T.C == O(1))   
#include <bits/stdc++.h> 
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check queue is full or not
        if(isFull()){
            return false;
        }
        //1st element to push in queue
        else if(isEmpty()){
            front = rear = 0;
        }
        //cyclic nature
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        //normal condition
        else{
            front--;
        }

        //push element inside the queue
        arr[front] = x;

        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        //check queue is full or not
        if(isFull()){
            return false;
        }

        //1st element to push in queue
        else if (isEmpty()){
            front = rear = 0;
        }

        //cyclic nature
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        //normal condition
        else{
            rear++;                  
        }

        //push element inside the queue
        arr[rear] = x;

        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        //check queue is empty or not
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        //single element is present
        if(front == rear){
            front = rear = -1;
        }

        //cyclic nature
        else if(front == size-1){
            front = 0;
        }
        //normal condition
        else{
            front++;                                      
        }
        return ans;
    }


    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        //check queue is empty or not
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        //single element is present
        if(front == rear){
            front = rear = -1;
        }

        //cyclic nature
        else if(rear == 0){
            rear = size-1;
        }
        //normal condition
        else{
            rear--;                    //normal condition                   
        }
        return ans; 
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];   
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1){
            return true;
        }
        return false;
        
        
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear ==  (front-1) % (size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};
/*
Sample Input 1:
5 7
7
1 10
1 20
2 30
5
4
4
Sample Output 1:
True 
True 
True
True
20
30
10
*/


//QUEUE REVERSAL                               (T.C == O(N))
queue<int> rev(queue<int> q)
{
    stack<int>s;
    
    //element is transfer from queue to stack
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    //element is transfer from stack to queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}
/*
Input:
6
4 3 1 10 2 6

Output: 
6 2 10 1 3 4
*/


// FIRST NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K        (T.C == O(N))
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
                                  
    deque<long long int>dq;
    vector<long long>ans;
    
    //process first window of K size
    for(int i = 0 ; i < K ; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }
    
    //store answer of first K size window
    if(dq.size() > 0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    //process for remaining window
    for(int i = K ; i < N ; i++){
        
        //removal
        if(!dq.empty() && (i-dq.front()) >= K){
            dq.pop_front();
        }
        
        //addition
        if(A[i] < 0){
             dq.push_back(i);
        }
        
        //store answer
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}   
/*
Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
*/


//REVERSE FIRST K ELEMENTS OF QUEUE         (T.C == O(N) , S.C == O(K))   
queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int>s;
    
    //fetch first k elements from queue and put into stack
    for(int i = 0 ; i< k ; i++){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    //fetch elements from stack and put into queue
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    
    //fetch first (n-k) elements from queue and push again to queue
    int t = q.size()-k;
    while(t--){
        int element = q.front();
        q.pop();
        q.push(element);
    }
    return q;
}
/*
Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5
*/


// FIRST NON-REPEATING CHARACTER IN A STREAM
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int>count;
		    queue<char>q;
		    string ans = "";
		    
    		for(int i = 0; i < A.length(); i++){
    		    char ch = A[i];
    		    
    		    //increasing count
    		    count[ch]++;
    		    
    		    //push element in queue
    		    q.push(ch);
    		    
    		    //q.front main algo
    		    while(!q.empty()){
    		        
    		        //repeating character
    		        if(count[q.front()] > 1){
    		            q.pop();
    		        }
    		        else{
    		            //non repeating charcter
    		            ans.push_back(q.front());
    		            break;
    		        }
    		    }
    		    //queue is empty
    		    if(q.empty()){
    		        ans.push_back('#');
    		    }
    		}
		    return ans;
		}
};
/*
Input: A = "aabc"
Output: "a#bb"
*/


//CIRCULAR TOUR                             (T.C == O(N))
// The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int start = 0;
       int balance = 0;
       
       for(int i = 0 ; i < n ; i++){
           balance = balance + p[i].petrol - p[i].distance;
           if(balance < 0){
               deficit = deficit + balance;
               start = i + 1;
               balance = 0;
           }
       }
       if(deficit + balance > 0){
           return start;
       }
       else{
           return -1;
       }
    }
};
/*
Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
*/


//IMPLEMENT STACK USING QUEUE
#include <queue>

class Stack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


//IMPLEMENT QUEUE USING STACK
#include <stack>

class Queue {
private:
    std::stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};


//'K' QUEUE IN AN ARRAY

#include<iostream>
using namespace std;

class kqueue{
    int n;
    int k ;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:
    kqueue(int n , int k){

        //initialization
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i = 0 ; i < k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i = 0 ; i < n ; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        freeSpot = 0;
    }

    void enqueue(int data, int qn){
        
        //overflow
        if(freeSpot == -1){
            cout<<"No empty space to push element"<<endl;
            return;
        }

        //find first free index
        int index = freeSpot;

        //update free spot
        freeSpot = next[index];

        //check whether 1st element to insert
        if(front[qn-1] == -1){
            front[qn -1] = index;
        }
        else{
            //link new element to previous element
            next[rear[qn -1]] = index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn -1] = index;

        //push element
        arr[index] = data;
    }

    int dequeue(int qn){

        //underflow
        if(front[qn -1] == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //front move forward
        front[qn-1] = next[index];

        //free spot manage
        next[index] = freeSpot;
        freeSpot = index;
        
        return arr[index];
    }
};
int main(){
    
    kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
}
/*output
10
20
15
25
Queue is empty
-1
*/


//SUM OF MINIMUM AND MAXIMUM ELEMENTS OF ALL SUBARRAYS OF SIZE 'K'
#include<iostream>
#include<queue>

using namespace std;

int solve(int *arr, int n , int k){
    
    deque<int>maxi;
    deque<int>mini;

    //addition of first k size window
    for(int i = 0 ; i < k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    //for remaining windows
    for(int i = k ; i < n ; i++){
        ans = ans + arr[maxi.front()] + arr[mini.front()];
        //nextwindow
        //removal
        while(!maxi.empty() && (i-maxi.front()) >= k){
            maxi.pop_front();
        }
        while(!mini.empty() && (i-mini.front()) >= k){
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    //take care of last window
    ans = ans + arr[maxi.front()] + arr[mini.front()];
    
    return ans;
}

int main(){
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout<<solve(arr, 7, k)<<endl;

    return 0;
}
/*OUTPUT
18
*/