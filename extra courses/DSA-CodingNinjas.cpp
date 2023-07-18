#include <bits/stdc++.h> 
using namespace std;

//ARRAYS

//MAXIMUM SUBARRAY SUM 
//BRUTE FORCE                                                                {T.C = O(N^2), S.C = O(1)}
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum = sum + arr[j];
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
//(KADANE'S ALGO)                                                            {T.C = O(N), S.C = O(1)}
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxi = 0;
    for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
/*
Sample Input 1 :
9
1 2 7 -4 3 2 -10 9 1
Sample Output 1 :
11
*/


//FLIP BITS                                                                   {T.C = O(N), S.C = O(1)}
#include <bits/stdc++.h> 
int flipBits(int* arr, int n) {
    int oneCount = 0;
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        //before flipping count
        if (arr[i] == 1) {
            oneCount++;
        } 
        //after flipping
        int val = (arr[i] == 0) ? 1 : -1;
        sum = sum + val;
        maxi = max(maxi, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return oneCount + maxi;
}
/*
Sample Input 1 :
3
5
1 0 0 1 0
4
1 1 1 0
5
0 0 1 0 0
Sample Output 1 :
4
4
4
*/


//MAXIMUM SUBARRAY SUM AFTER K CONCATENATION                                          {T.C = O(N*K), S.C = O(1)}
#include <bits/stdc++.h> 
long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
	//using kadane's algo
	long long sum = 0; 
	long long maxi = INT_MIN;
	
	for(int i = -1 ; i < n*k-1 ; i++){
		if(sum < 0){
			sum = 0;
		}
		sum += arr[(i+1)%n];
		maxi = max(maxi , sum);
	}
	return maxi;
}
/*
Sample Input 1 :
2
2 3
1 3
3 2
1 -2 1
Sample Output 1 :
12
2
*/


//MAXIMUM SUM RECTANGLE                                                  {T.C = O(N*M^2), S.C = O(N)}
int kadane(vector<int>& arr, int n) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m) {
    vector<int> sum(n, 0);
    int maxSum = INT_MIN;
    for (int cStart = 0; cStart < m; cStart++) {
        for (int cEnd = cStart; cEnd < m; cEnd++) {
            for (int row = 0; row < n; row++) {
                sum[row] += arr[row][cEnd];
            }
            int currSum = kadane(sum, n);
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        for (int row = 0; row < n; row++) {
            sum[row] = 0; // reset the sum array for the next column range
        }
    }
    return maxSum;
}
/*

Sample Input 2
1
4 5
1 2 -1 -4 -20
-8 -3  4 2 1
3  8 10 1 3
-4 -1 1 7 -6
Sample Output 2
29
*/


//SORT 0's 1's and 2's                                                     {T.C = O(N), S.C = O(1)}
void sort012(int *arr, int n)
{  
   int low =0;
   int mid = 0;
   int high = n-1;
   // while(mid <= high){
   for(int i = 0 ; i < n ; i++){
      if(arr[mid] == 0){
         swap(arr[mid], arr[low]);
         low++;
         mid++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{   //mid == 2
         swap(arr[mid], arr[high]);
         high--;
      }
   }
}
/*
Sample Input 1 :
2
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2
Sample Output 1 :
0 0 1 1 2 2
0 1 1 1 2 2 2
*/


//QUICKSORT USING THE DUTCH NATIONAL FLAG ALGORITHM                                                  {T.C = O(N*LOGN), S.C = O(LOGN)}
void dutchNationalFlag(vector<int>&arr, int s, int &midLeft, int &midRight, int e){
    int pivot = arr[s];
    int mid = s;
    while( mid <= midRight){
        if(arr[mid] < pivot){
            swap(arr[mid], arr[midLeft]);
            mid++;
            midLeft++;
        }
        else if(arr[mid] == pivot){
            mid++;
        }
        else{
            swap(arr[mid], arr[midRight]);
            midRight--;
        }
    }
}
void quickSort(vector<int>&arr, int s, int e){
    if(s >= e){
        return;
    }
    int midLeft = s;
    int midRight = e;

    dutchNationalFlag(arr, s , midLeft, midRight, e);

    quickSort(arr, s , midLeft-1);
    quickSort(arr, midRight+1, e);
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
    int s = 0;
    int e = arr.size()-1;
    quickSort(arr, s, e);
    return arr;
}
/*
Sample Input 1 :
2
5
4 2 1 4 2
5
5 2 7 3 5
Sample Output 1:
1 2 2 4 4
2 3 5 5 7
*/


//SEARCH IN ROTATED SORTED ARRAY
//BRUTE FORCE (LINEAR SEARCH)                                                                {T.C = O(N), S.C = O(1)}
int search(int* arr, int n, int key) {
   for(int i = 0 ; i < n ; i++){
      if(arr[i] == key){
         return i;
      }
   }
   return -1;
}

//BINARY SEARCH                                                                              {T.C = O(LOGN), S.C = O(1)}
int search(int* arr, int n, int key) {
   int lo = 0;
   int hi = n-1;
   while(lo <= hi){
      int mid = lo + (hi - lo)/2;
      if(arr[mid] == key){
         return mid;
      }
      //left part sorted
      if(arr[lo] <= arr[mid]){
         if(arr[lo] <= key && key <= arr[mid]){
            hi = mid-1;
         }
         else{
            lo = mid+1;
         }
      }
      //right part sorted
      else{   
         if(arr[mid] <= key && key <= arr[hi]){
            lo = mid+1;
         }
         else{
            hi = mid-1;
         }
      }
   }
   return -1;
}
/*
Sample Input 1:
4
2 5 -3 0
2
5
1
Sample Output 1:
1
-1
*/


//FORM A TRIANGLE
//BRUTE  FORCE                                                                               {T.C = O(N^3) , S.C = O(1)}
bool check(int a, int b, int c){
    if((a+b > c) && (b+c > a) && (a+c > b)){
        return true;
    }
    return false;
}
bool possibleToMakeTriangle(vector<int> &arr)
{   
    int n = arr.size();
    bool ans = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for(int k = j+1; k < n ; k++){
                if(arr[i] > 0 && arr[j] > 0 && arr[k] > 0){
                    ans = check(arr[i], arr[j], arr[k]);
                }
                if(ans == true){
                    return true;
                }
            }
        }
    }
    return false;
}  
//using triangle property in single loop                                                {T.C = O(N*LOGN), S.C = O(1)}
bool possibleToMakeTriangle(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0 ; i <= n-3 ; i++){
        if((arr[i]+arr[i+1] > arr[i+2]) && (arr[i]+arr[i+2] > arr[i]) && (arr[i+1]+arr[i+2] > arr[i])){
            return true;
        }
    }
    return false;
}
/*
Sample Input 2:
2
5
12 3 7 4 28
4
7 12 9 20
Sample Output 2:
NO
YES
*/