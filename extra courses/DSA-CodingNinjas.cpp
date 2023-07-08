#include <bits/stdc++.h> 
using namespace std;

//ARRAYS

//MAXIMUM SUBARRAY SUM (KADANE'S ALGO)                                      {T.C = O(N), S.C = O(1)}
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