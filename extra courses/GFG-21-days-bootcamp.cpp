//GFG 21 DAYS BOOTCAMP == FUNDAMENTAL OF DSA
#include<bits/stdc++.h>
#include<vector>

using namespace std;

//PRINT FIRST N FIBONACCI SERIES                            {T.C = O(N),S.C = O(N)}
class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long>fib(n);          // int v[n]
        fib[0] = fib[1] = 1;           // not handle if n(no. of element) = 1
        
        //cache                           
        // fib[0]= 1;
        // if(n > 1){
        //     fib[1] = 1;
        // }
        
        for(int i = 2 ; i < n ;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib;
    }
};
/*
Input:
N = 7
Output: 1 1 2 3 5 8 13
*/


//MAJORITY ELEMENT(MOORE'S VOTING ALGORITM)                        {T.C = O(N),S.C = O(1)}        //variable size < vector/array
class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        //using MOORE'S ALGORITHM
        int c = 1 ; int val = a[0];
        for(int i = 1 ; i < size ; i++){            //iterate from second element
            if(a[i] == val){
                c++;
            }
            else{
                c--;
                if(c == 0){
                    val = a[i];
                    c = 1;
                }
            }
        }
        //check valid answer or not
        c = 0;
        for(int i = 0 ; i < size ; i++){
            if(a[i] == val){
                c++;
            }
        }
        if(c > size/2){
            return val;
        }
        else{
            return -1;
        }
    }
};
/*
Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
*/


//SORT AN ARRAY OF 0'S 1'S AND 2'S                                         {T.C = O(N), S.C = O(1)}
//DUTCH NATIONAL FLAG ALGORITHM
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n-1;
        
        while(mid <= high){
            if(a[mid] == 0){
                swap(a[mid], a[low]);
                low++;
                mid++;
            }
            else if(a[mid] == 1){
                mid++;
            }
            else{                           //a[i] = 2
                swap(a[mid] , a[high]);
                high--;
            }
        }
    }
};
/*
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
*/


//COUNT THE SUBARRAYS HAVING PRODUCT LESS THEN K                         {T.C = O(N), S.C = O(1)}
//SLIDING WINDOW APPROACH
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long pro = 1;
        int l = 0;
        int r = 0;
        int count = 0;
        
        while(r < n){
            pro = pro * a[r];
            while(l < n && pro >= k){
                pro = pro/a[l];
                l++;
            }
            if(pro < k){
                count = count + (r-l+1);
            }
            r++;
        }
        return count;
    }
};
/*
Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
*/


//MINIMUM NUMBER OF JUMPS                                                 {T.C = O(N), S.C = O(1)}
class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int far = 0;                 //far == maximum reachable index
        int curr = 0;
        int jumps = 0;
        
        for(int i = 0 ; i < n-1 ; i++){  //check till second last index(last element is not check for jump)
            far = max(far, i + arr[i]);
            if(curr == i){
                jumps++;
                curr = far;
            }
        }
        if(curr < n-1){
            return -1;
        }
        else{
            return jumps;
        }
    }
};
/*
Input :
N = 6
arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.
*/


//INTERSECTION OF TWO SORTED LINK LIST                                                  {T.C = O(N+M) , S.C = O(N+M)} //N,M = SIZE OF LL
// The structure of the Linked list Node is as follows:
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


Node* findIntersection(Node* l1, Node* l2)
{
    Node* head = NULL;
    Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            l1 = l1->next;
        } 
        else if (l1->data > l2->data) {
            l2 = l2->next;
        } 
        else {  // l1->data == l2->data
            if (head == NULL) {
                head = tail = new Node(l1->data);
            } 
            else {
                tail->next = new Node(l1->data);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    return head;
}
/*
Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
*/


//REVERSE A LINK LIST                                                  {T.C = O(N), S.C = O(1)}
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node * prev = NULL;
        Node * curr = head;
        Node * next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
/*
Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
*/


//CHECK IF LINKED LIST IS PALINDROME                                                   {T.C = O(N), S.C = O(1)}
#include<vector>
class Solution{
    private:
    bool checkPalindrome(vector<int>arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    public:
    bool isPalindrome(Node * head){
        vector<int>arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);

    }
};
/*
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
*/


//PARANTHESIS CHECKER                                                           {T.C = O(X), S.C = O(X)} X = SIZE OF STRING
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool cmp(char o , char c){
        if(o == '{' && c == '}'){
            return 1;
        }
        if(o == '[' && c == ']'){
            return 1;
        }
        if(o == '(' && c == ')'){
            return 1;
        }
        return 0;
    }
    bool ispar(string x)
    {
        stack<char>s;
        int n = x.size();
        
        for(int i = 0 ; i < n ; i++){
            if(x[i] == '{' || x[i] == '[' || x[i] == '('){
                s.push(x[i]);
            }
            else{
                if(s.empty() || cmp(s.top(),x[i]) == 0){
                    return 0;
                }
                s.pop();
            }
        }
        if(s.empty()){
            return 1;
        }
        return 0;
    }
};
/*
Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balanced pairs, with 0 number of 
unbalanced bracket.
*/


//MAXIMUM OF ALL SUBARRAYS OF SIZE K                                       {T.C = O(N) , S.C = O(K)} N = SIZE OF ARRAY , K = SIZE OF SUBARRAY
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
        deque<int>dq;
        
        for(int i = 0 ;i < k ; i++){
            while(!dq.empty() && (arr[dq.back()] <= arr[i] )){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i = k; i < n ;i++){
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() && (dq.front() <= (i-k))){
                dq.pop_front();
            }
            while(!dq.empty() && (arr[dq.back()] <= arr[i])){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};
/*
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
*/


//BINARY SEARCH                                             {T.C = O(LOGN), S.C = O(1)}
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
        
            if(arr[mid] == k){
                return mid;
            }
            else if(arr[mid] > k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};
/*
Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.
*/


//BITONIC POINT                                          {T.C = O(LOGN), S.C = O(1)}
class Solution{
public:
	
	int findMaximum(int a[], int n) {
	    int low = 0;
	    int high = n-1;
	    
	    while(low <= high){
	        int mid = (low + high)/2;
	        if(mid > 0 && mid < n-1){          //non corner elements
                if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
                    return a[mid];
                }
                else if(a[mid] > a[mid-1]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
	        }
	        else{                              //corner elements
	            if(mid == 0){
	                return max(a[0], a[1]);    //ateleast 2 elemeents in an array
	            }
	            else if(mid == (n-1)){
	                return max(a[n-2], a[n-1]);
	            }
	        }
	    }
	    return -1;
	}
};
/*
Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
*/


//MINIMIZE THE SUM OF PRODUCT                              //{T.C = O(NLOGN) , S.C = O(1)}
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        long long int ans = 0;
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        for(int i = 0 ; i < n ; i++){
            ans = ans + a[i]*b[i];
        }
        return ans;
    }
};
/*
Input:
N = 3 
A[] = {3, 1, 1}
B[] = {6, 5, 4}
Output:
23 
Explanation:
1*6+1*5+3*4 = 6+5+12
= 23 is the minimum sum
*/


//MINIMUM PLATFORMS                                              {T.C = O(NLOGN), S.C = O(N)}
class Solution{
public:
    int findPlatform(int arr[], int dep[], int n)          //arr = arrival , dep = departure
    {
        // Sort the arrival and departure times in ascending order
        sort(arr, arr + n);
        sort(dep, dep + n);
    
        int platforms = 1;  // At least one platform is required
        int maxPlatforms = 1;  // Keep track of the maximum number of platforms needed
    
        int arrivalIndex = 1;
        int departureIndex = 0;
    
        while (arrivalIndex < n && departureIndex < n) {
            if (arr[arrivalIndex] <= dep[departureIndex]) {
                platforms++;  // Increment the number of platforms needed
                maxPlatforms = max(maxPlatforms, platforms);
                arrivalIndex++;
            } else {
                platforms--;  // Reduce the number of platforms needed
                departureIndex++;
            }
        }
        return maxPlatforms;
    }
};
/*
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
*/


//CHOCOLATE DISTRIBUTION PROBLEM                                             {T.C = O(NLOGN), S.C = O(1)}
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){

        sort(a.begin(),a.end());
        
        int start = 0;
        int end = 0;
        long long minD = INT_MAX;
        
        for(int i = 0 ; i+m-1 < n ; i++){
            long long diff = a[i+m-1] - a[i];
            if(diff < minD){
                minD = diff;
                start = i;
                end = i+m-1;
            }
        }
        return minD;
    }   
};
/*
Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.
*/


//TRIPLET SUM IN ARRAY
//BRUTE FORCE                                   {T.C = O(N^3), S.C = O(1)}
class Solution {
public:
    bool find3Numbers(int A[], int n, int X) {
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (A[i] + A[j] + A[k] == X) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//TWO POINTER APPROACH                         {T.C = O(N^2) , S.C = O(1)}
class Solution {                                                   
public:
    bool find3Numbers(int A[], int n, int X) {
        int l , r;
        sort(A, A+n);
        
        for(int i = 0 ; i < n-2 ; i++){
            l = i+1;
            r = n-1;
            
            while(l < r){
                if(A[i] + A[l] + A[r] == X){
                    return true;
                }
                else if(A[i] + A[l] + A[r] < X){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return false;
    }
};
/*
Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 1
*/


//POWER OF NUMBERS  (exponential algorithm)                                  {T.C = O(LOGN), S.C = O(LOGN)}
#define mod 1000000007

class Solution{
    public:
    //You need to complete this fucntion
    long long fexp(int x , int y){
        long long ans;
        //base case
        if(x == 0){
            return 0;
        }
        if(y == 0){
            return 1;
        }
        
        
        if(y % 2 == 0){
            //even
            ans = fexp(x, y/2);
            ans = ((ans)%mod*(ans)%mod)%mod;
        }
        else{
            //odd
            ans = ((x)%mod*(fexp(x, y-1))%mod)%mod;
        }
        return (ans+mod)%mod;
    }
    long long power(int N,int R)
    {
       return fexp(N, R);
        
    }
};
/*
Input:
N = 12
Output: 864354781
Explanation: The reverse of 12 is 21and 1221 when divided by 1000000007 gives remainder as 864354781.
*/


//PERMUTAIONS OF GIVEN STRINGS                                                                  {T.C = O(N! * N), S.C = O(N! * N)}
class Solution {
public:
    set<string> st;
    string s;

    void rec(int i) {
        if (i == s.size()) {
            st.insert(s);
        } else {
            for (int j = i; j < s.size(); j++) {
                swap(s[i], s[j]);
                rec(i + 1);
                swap(s[i], s[j]);
            }
        }
    }

    vector<string> find_permutation(string S) {
        s = S;
        rec(0);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

//CHATGPT
class Solution {
public:
    vector<string> find_permutation(string S) {
        vector<string> permutations;
        backtrack(S, 0, permutations);
        return permutations;
    }

    void backtrack(string& s, int start, vector<string>& permutations) {
        if (start == s.size() - 1) {
            permutations.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            swap(s[start], s[i]);
            backtrack(s, start + 1, permutations);
            swap(s[start], s[i]);
        }
    }
};

/*
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/


//HACKEREARTH(GOOGLE PRACTISE)
//FIND CLOSEST NUMBER OF ZERO
int Solve (int N, vector <int> A) {
    int closest = INT_MAX;
    int closestValue = INT_MAX;

    for(int i = 0 ; i < N ; i++){
        int diff = abs(A[i]);
        if(diff < closest || (diff == closest && A[i] > closestValue)){
            closest = diff;
            closestValue = A[i];
        }
    }
    return closestValue;
}