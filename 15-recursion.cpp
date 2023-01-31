//RECURSION

#include<iostream>
using namespace std;

/*
int fact(int n){
    //base case
    if(n == 0){
        return 1;
    } 
    int chotti = fact(n-1);
    int badi = n * chotti;

    //or
    // return n*fact(n-1);

    return badi;
}
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    int ans = fact(n);
    cout<<ans<<endl;
}
*/


/*
int power(int n){
    //base Case
    if(n==0){
        return 1;
    }
    int choti = power(n-1);
    int badi = 2 * choti;

    return badi;
    //or
    //return 2*power(n-1);
}
int main(){
    int n;
    cout<<"Enter the value of  (2^n) n : "<<endl;
    cin>>n;

    int ans = power(n);
    cout<<ans<<endl;
}
*/


/*
void count(int n){
    //base case
    if(n == 0){
        return; 
    }
    cout<< n <<endl;

    //RR
    count(n-1);

    cout<< n <<endl;              //print in increasing order 


}
int main(){
    int n;
    cout<<"Enter the value of  n : "<<endl;
    cin>>n;

    count(n);

}
*/


/*
void reachHome(int src , int dest){

    cout<<"source "<<src<<" dest "<<dest<<endl;

    //base case
    if(src == dest){
        cout<<"pahuch gaya "<<" ";
        return;
    }
    
    //processing
    src++;

    //Recursive call
    reachHome(src , dest);
}
int main(){
    int dest = 10;
    int src = 1;

    reachHome(src , dest);
}
*/


//FIBONACCI NUMBER
/*
class Solution {
public:
    int fib(int n) {
        //base case
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        //Recursive call
        int ans = fib(n-1) + fib(n-2);

        return ans;
    }
};
*/

//COUNT WAYS TO REACH THE N-TH STAIRS (CS)
/*
int countDistinctWayToClimbStair(long long nStairs){

    //base case
    if(nStairs < 0){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }

    //Recursive call
    int ans = countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs - 2);

    return ans;
}
int main(){
    long long nStairs;
    cout<<"Enter the no. of ways to climb : "<<endl;
    cin>>nStairs;

    int ans = countDistinctWayToClimbStair(nStairs);
    cout<<ans<<endl;

    return 0;
}
*/


//SAY DIGITS
/*
void sayDigits(int n , string arr[]){
    //base case
    if(n==0){
        return;
    }

    //processing
    int digit = n % 10;
    n = n / 10;

    //RR
    sayDigits(n,arr);

    cout<<arr[digit]<<" ";
}
int main(){
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;

    cout<<"The numbers in words : "<<endl;
    sayDigits(n,arr);
}
*/


//ARRAY IS SORTED OR NOT and GET SUM OF ARRAY ELEMENT (RECURSION)
/*
bool isSorted(int a[],int n){

    //base case
    if(n==0 || n == 1){
        return 1;
    }
    if( a[0] > a[1]){
        return 0;
    }
    else{
        bool remainingPart = isSorted(a+1 , n-1);
        return remainingPart;
    }
}
int getSum(int a[] , int n){

    //base case
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return a[0];
    }

    int remainingPart= getSum(a+1,n-1);
    int totalSum = a[0] + remainingPart;
    return totalSum;
}
int main(){
    int a[7] = {1 , 2 , 3 , 5 , 6, 8 , 9};
    int n = 7;

    bool ans = isSorted(a , n);

    if(ans){
        cout<<"Array is sorted "<<endl;
    }
    else{
        cout<<"Array is unsorted "<<endl;
    }

    int ans2 = getSum(a , n);
    cout<<"Array sum is : "<<ans2<<endl;
}
*/


//LINEAR SEARCH
/*
bool linearSearch(int a[] , int n , int k){

    //base case
    if(n==0){
        return 0;
    } 

    if(a[0] == k){
        return 1;
    }
    else{
        int remainingPart = linearSearch(a+1 , n-1 , k);
        return remainingPart;
    }
}
int main(){
    int a[7] = {1 , 2 , 3 , 5 , 6, 8 , 9};
    int n = 7;
    int k = 2;

    bool ans = linearSearch(a , n , k);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
}
*/


//BINARY SEARCH
/*
bool binarySearch(int a[] ,int s , int e , int k){
    int mid = s + (e-s)/2;
    
    //base case
    if(s > e){
        return 0;
    }
    
    if(a[mid] == k){
        return 1;
    }
    else if(a[mid] > k){
        int remainingPart = binarySearch(a , s , mid-1 , k);
        return remainingPart;
    }
    else{
        int remainingPart = binarySearch(a , mid + 1 , e , k);
        return remainingPart;
    }
}
int main(){
    int a[7] = {1 , 2 , 3 , 5 , 6, 8 , 9};
    int n = 7;
    int k = 8;

    bool ans = binarySearch(a , 0 , 6 , k);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
}
*/


//REVERSE STRING 
/*
void reverse(int i , int j , string &s){

    //base case
    if(i > j ){
        return ;
    }

    swap(s[i],s[j]);
    i++,j--;
    
    //RR
    reverse(i,j,s);
}
int main(){
    string s = "shivam";



    reverse(0 , s.length()-1,s);

    cout<<"String after reverse : "<<endl;
    cout<<s<<endl;

}
*/


/*
bool checkPalindrome(int i , int j , string &s){

    //base case
    if(i > j){
        return 1;
    }
    if(s[i] != s[j]){
        return 0;
    }
    else{
        //RR
        return checkPalindrome(i+1 , j-1 , s);
    }
}
int main(){
    string s = "aabbccbbaa";
    bool ans = checkPalindrome(0, s.length()-1,s);

    if(ans){
        cout<<"Its a Palindrome "<<endl;
    }
    else{
        cout<<"Not a Palindrome "<<endl;
    }
}
*/


//FIND POWER
/*
int power(int a , int b){
    //base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    //RR
    int ans = power(a , b/2);

    if(b % 2 == 0){
        //for even
        return ans * ans;
    }
    else{
        //for odd
        return a * ans * ans;
    }
}
int main(){
    int a , b;
    cout<<"Enter the value of a and b : "<<endl;
    cin>>a>>b;

    int ans = power(a , b);
    cout<<"The ans is : "<<ans<<endl;

}
*/


//BUBBLE SORT
/*
int bubbleSort(int a[], int n){
    //base case
    if(n==0 || n == 1){
        return 1 ;
    }
    
    for(int i = 0 ; i < n-1 ; i++){
        if(a[i] > a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    bubbleSort(a , n-1);
}
int main(){
    int a[6] = {1 , 9 , 3 , 8 , 5 , 7};

    bubbleSort(a , 6);

    cout<<"Array after sorting (bubble) : "<<endl;
    for(int i = 0 ; i < 6 ; i++){
        cout<<a[i]<<" ";
    }
}
*/


//MERGE SORT
/*
void merge(int *a , int s , int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //create 2 arrays
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i = 0 ; i < len1 ; i++){
        first[i] = a[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i = 0 ; i < len2 ; i++){
        second[i] = a[mainArrayIndex++];
    }

    //merge 2 sorted array 
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            a[mainArrayIndex++] = first[index1++];
        }
        else{
            a[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        a[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        a[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}
void mergeSort(int *a , int s , int e){
    //base case
    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;
    //RR
    //left part sorting
    mergeSort(a , s , mid);
    
    //right part sorting
    mergeSort(a , mid+1 , e);

    //merge two sorted array
    merge(a , s , e);

}
int main(){
    int a[9] = {1 , 4 , 2 , 6 , 9 , 34 , 64 , 25 , 23};
    int n = 9;

    mergeSort(a , 0 , n-1);

    cout<<"Array after sorting (merge) : "<<endl;
    for(int i = 0 ; i < n ; i++ ){
        cout<<a[i]<<" ";
    }
}
*/


//QUICK SORT
/*
int partition(int a[] , int s , int e){
    int pivot = a[s];

    int cnt = 0;
    for(int i = s+1 ; i <= e ; i++){
        if(a[i] <= pivot){
            cnt++;
        }
    }

    //place pivot at right place
    int pivotIndex = s + cnt;
    swap(a[pivotIndex],a[s]);

    //for left and right arrays of pivot
    int i = s , j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(a[i++],a[j--]);
        }
    }

    return pivotIndex;
}
void quickSort(int a[] , int s , int e){
    //base case 
    if(s >= e){
        return ;
    }

    //partition    
    int p = partition(a , s , e);

    //left part sorting
    quickSort(a ,s, p-1);

    //right part sorting
    quickSort(a ,p+1 , e);

}
int main(){
    int a[9] = {1 , 4 , 2 , 6 , 9 , 34 , 64 , 25 , 23};
    int n = 9;

    quickSort(a , 0 , n-1);

    cout<<"Array after sorting (quick) : "<<endl;
    for(int i = 0 ; i < n ; i++ ){
        cout<<a[i]<<" ";
    }
}
*/

//SUBSETS
/*
class Solution {
private:
    void solve(vector<int>nums , vector<int>output , int index , vector<vector<int>> &ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return ;
        }

        //exclude
        solve(nums , output, index+1 , ans);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums , output, index+1 , ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        int index = 0; 
        vector<vector<int>> ans;

        solve(nums , output , index , ans);

        return ans;
    }
};
*/

//SUBSEQUENCES OF STRING
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string str , string output , int index , vector<string> &ans){
	//base case
	if(index >= str.length()){
		if(output.length() > 0){
			ans.push_back(output);
		}
		return;                   
	}

	//exclude
	solve(str , output , index+1 , ans);

	//include
	char element = str[index];
	output.push_back(element);
	solve(str , output , index+1 , ans);

}
vector<string> subsequences(string str){
	string output = "";
	int index = 0;
	vector<string>ans;

	solve(str , output , index , ans);
	return ans;
	
}
*/


//LETTER COMBINATIONS OF A PHONE NUMBER
/*
class Solution {
private : 
    void solve(string digits , string output , int index , vector<string> &ans , string mapping[]){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0 ; i <  value.length() ; i++){
            output.push_back(value[i]);
            solve(digits ,output , index+1 , ans , mapping);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        int index = 0;  

        if(digits.length() == 0){
            return ans;
        }

        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits , output , index , ans , mapping);
        return ans;
    }
};
*/


// PERMUTATIONS
/*
class Solution {
private:
    void solve(vector<int> nums  , int index , vector<vector<int>> &ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int i = index ; i < nums.size() ; i++){
            swap(nums[index], nums[i]);
            solve(nums , index+1 , ans);
            
            //backtracking
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums , index , ans);
        return ans;
    }
};
*/


//RAT IN MAZE PROBLEM
/*
#include<vector>
#include<algorithm>

bool isSafe(int x , int y , int n , vector<vector<int>>&visited , vector<vector<int>> &m){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] ==0) && m[x][y] == 1){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> &m , int n  , vector<string> &ans , int x , int y , vector<vector<int>> &visited , string path){

    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    //4 choices we have up,down,left,right
    //up
    int newx = x-1;
    int newy = y;
    if(isSafe(newx , newy ,n , visited , m)){
        path.push_back('U');
        solve(m , n , ans , newx , newy , visited , path);
        path.pop_back();
    }
    //dow
    int newx = x+1;
    int newy = y;
    if(isSafe(newx , newy ,n ,  visited , m)){
        path.push_back('D');
        solve(m , n , ans , newx , newy , visited , path);
        path.pop_back();
    }
    //left
    int newx = x;
    int newy = y-1;
    if(isSafe(newx , newy ,n , visited , m)){
        path.push_back('L');
        solve(m , n , ans , newx , newy , visited , path);
        path.pop_back();
    }
    //right
    int newx = x;
    int newy = y+1;
    if(isSafe(newx , newy ,n , visited , m)){
        path.push_back('R');
        solve(m , n ,ans , newx , newy , visited , path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string>findPath(vector<vector<int>>&m , int n){
    vector <string>ans;

    if(m[0][0] == 0){
        return ans;
    }
    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = m;
    //initialize with 0
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            visited[i][j] == 0;
        }
    }

    string path = "";
    solve(m , n  ,ans , srcx , srcy , visited , path);
    sort(ans.begin() , ans.end());
    return ans;

}
*/

/*OUTPUT
Enter the value of n : 
5
120

Enter the value of  (2^n) n : 
6
64

Enter the value of  n :
6
6 5 4 3 2 1
1 2 3 4 5 6

source 1 dest 10
source 2 dest 10
source 3 dest 10
source 4 dest 10
source 5 dest 10
source 6 dest 10
source 7 dest 10
source 8 dest 10
source 9 dest 10
source 10 dest 10
pahuch gaya

Enter the no. of ways to climb : 
5
8

Enter the number : 
413
The numbers in words : 
four one three

Array is sorted 
Array sum is : 34

Present

Present

String after reverse : 
mavihs

Its a Palindrome 

Enter the value of a and b : 
2
6
The ans is : 64

Array after sorting (bubble) : 
1 3 5 7 8 9

Array after sorting (merge) : 
1 2 4 6 9 23 25 34 64

Array after sorting (merge) : 
1 2 4 6 9 23 25 34 64

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Input:
1 
abc
Output:
a ab abc ac b bc c

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

