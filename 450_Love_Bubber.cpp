//REVERSE THE STRING

#include<iostream>
using namespace std;

string reverseWord(string str){
    int n = str.length();
    for(int i = 0 ; i < n/2 ; i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    cout<<str;
}


//FIND MAXIMUM AND MINIMUM ELEMENT IN AN ARRAY
class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int max = INT_MIN;
    	int min = INT_MAX;
    	int sum = 0;
    	for(int i = 0 ; i < N ; i++){
    	    if(A[i] > max){
    	        max = A[i];
    	    }
    	    if(A[i] < min){
    	        min = A[i];
    	    }
    	}
	    sum = sum +  max + min;
    }
};


//KTH SMALLEST ELEMENT
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>pq;
        
        //step1- make max heap of first k elements
        for(int i = 0 ; i < k ; i++){
            pq.push(arr[i]);
        }
        
        //step2- for rest of elements
        for(int i = k ; i <= r ; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step3- return ans
        int ans = pq.top();
        return ans;
    }
};


//SORT AN ARRAY'S OF 0'S 1'S AND 2'S                                             {T.C = O(N) ,S.C = O(1)}
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int ptr1 = 0, ptr2 = n-1 , i = 0;
        while(i <= ptr2){
            if(a[i] == 0){
                swap(a[i++],a[ptr1++]);
            }
            else if(a[i] == 2){
                swap(a[i],a[ptr2--]);   
            }
            else{                 //a[i] == 1
                i++;
            }
        }
    }
};


//Move all negative numbers to beginning and positive to end with constant extra space
#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b ;
    b = temp;
}
void reArrange(int arr[] , int &n){
    int low = 0 ;
    int high = n-1;
    while(low < high){
        if(arr[low] < 0){
            low++;
        }
        else if(arr[high] > 0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }
}
void displayArray(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {5 , -3, 22 , -24 , 34 , 98 , -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    reArrange(arr,n);
    displayArray(arr,n);
    
}
/*
output
-2 -3 -24 22 34 98 5 
*/


//UNION OF TWO ARRAYS                                                 {T.C = O(N+M), S.C = O(N+M)}
#include<unordered_set>
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int>unionSet;
        
        //insert element of 1st array into unionset/hash
        for(int i = 0 ; i < n ; i++){
            unionSet.insert(a[i]);
        }
        
        //insert element of 2nd array into unionset/hash
        for(int i  = 0 ; i < m ; i++){
            unionSet.insert(b[i]);
        }
        
        return unionSet.size();
    }
};
/*
Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
*/


//INTERSECTION OF TWO SORTED ARRAYS                                    {T.C = O(n + m),S.C= O(min(n,m))}
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int>intersectionSet;
        unordered_set<int>setA(a,a+n);
        
        //insert intersection of element of array in unordered set/hash
        for(int i = 0 ; i < m ; i++){
            if(setA.count(b[i]) > 0){
                intersectionSet.insert(b[i]);
            }
        }
        
        return intersectionSet.size();
    }
};
/*
Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1
*/


//CYCLICALLY ROTATE AN ARRAY BY ONE                                   {T.C = O(N) , S.C = O(1)}
void rotate(int arr[], int n)
{
    //store the last element
    int lastelement = arr[n-1];
    
    for(int i = n-1 ; i > 0 ; i--){
        arr[i] = arr[i-1];
    }
    
    //put last element to first place
    arr[0] = lastelement;
    
}
/*
Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
*/


//MINIMIZE THE HEIGHTS II                                   {T.C = O(N),S.C = O(1)}
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int diff = arr[n-1]-arr[0];
        int mini = 0;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]-k < 0){
                continue;
            }
            maxi = max(arr[n-1]-k ,arr[i-1]+k);
            mini = min(arr[0]+k , arr[i]-k);
            diff = min(diff,(maxi-mini));
        }
        return diff;
    }
};
/*
Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. 
The difference between 
the largest and the smallest is 8-3 = 5.
*/