//DYNAMIC PROGRAMMING (DP)
/*
2 APPROACHES
->TOP DOWN == RECURSION + MEMOIZATION
->BOTTOM UP == TABULATION
  ->SPACE OPTIMIZATION
*/

//NTH FIBONACCI SERIES                                   {T.C = O(N)+O(N)= O(N), S.C = O(N)}
#include<bits/stdc++.h>
#include<vector>
using namespace std;

//TOP DOWN APPROACH
int fib(int n, vector<int>&dp){
    //base case
    if(n <= 1){
        return n;
    }

    //step-3
    if(dp[n] != -1){
        return dp[n];
    }

    //step-2
    dp[n] = fib(n-1, dp)+ fib(n-2, dp);
    return dp[n];
}
int main()
{
    int n ;
    cin>>n;

    //step-1
    vector<int>dp(n+1);
    for(int i = 0 ; i <= n ; i++){
        dp[i] = -1;
    }

    cout<<fib(n, dp)<<endl;

    return 0;
}

//BOTTOM UP APPROACH                                       {T.C = O(N), S.C = O(N)}
int main()
{
    int n ;
    cin>>n;

    //step-1
    vector<int>dp(n+1);

    //step-2
    dp[0] = 0; 
    dp[1] = 1;

    //step-3
    for(int i = 2 ;i <=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;

    return 0;
}
//SPACE OPTIMIZATION                                        {T.C = O(N), S.C = O(1)}
int main()
{
    int n ;
    cin>>n;

    int prev1 = 1; 
    int prev2 = 0;
    
    //case handle if n == 0
    if(n == 0){
        return prev2; 
    }

    for(int i = 2 ;i <=n ; i++){
        //shift logic
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1<<endl;

    return 0;
}
/*
Sample Input 1:
6
Sample Output 1:
8
*/


//MIN COST CLIMBING STAIRS
//TOP DOWN APPROACH = RECURSION + MEMOIZATION                                     {T.C = O(N), S.C = O(N) + O(N) = O(N)}
class Solution {
public:
    int solve(vector<int>&cost , int n , vector<int>&dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        //step-3 
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //step-1 create dp array
        vector<int>dp(n+1, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};

//BOTTOM UP = TABULATION                                                          {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //step-1 create dp array
        vector<int>dp(n+1);

        //step-2 base case analyse
        dp[0] = cost[0];
        dp[1] = cost[1];

        //for loop for rest of elements
        for(int i = 2 ; i < n ; i++ ){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

//SPACE OPTIMIZATION                                                               {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev1 = cost[1];
        int prev2 = cost[0];

        for(int i = 2 ; i < n ; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};
/*
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/


//MINIMUM ELEMENTS                                                   {T.C = O(X*N), S.C = O(X)}
//TABULATION METHOD
int minimumElements(vector<int> &num, int x)
{
    //create dp array
    vector<int>dp(x+1, INT_MAX);
    
    //analyze base case
    dp[0] = 0;

    //loop 
    for(int i = 1 ; i <= x ; i++){
        //solve every amount figure from 1 to x 
        for(int j = 0; j < num.size() ; j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX){
        return -1;
    }
    return dp[x];
}
/*
Sample Input 1 :
2
3 7
1 2 3
1 0
1
Sample Output 1 :
0
3
*/


//MAXIMUM SUM OF NON ADJACANT ELEMENT                                                      {T.C = O(N), S.C = O(N)}
//TABULATION METHOD
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //step-1 create dp array
    vector<int>dp(n, 0);

    //step-2 base case
    dp[0] = nums[0];

    //step-2 loop
    for(int i = 1 ; i < n ; i++){          //loop from second element
        int incl = dp[i-2] + nums[i];    
        int excl = dp[i-1] + 0;
        dp[i] = max(incl , excl);
    }
    return dp[n-1];
}
//SPACE OPTIMIZATION                                                                       {T.C = O(N), S.C = O(1)}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //step-1 create dp array
    int prev2 = 0;
    int prev1 = nums[0];

    //step-2 loop
    for(int i = 1 ; i < n ; i++){          //loop from second element
        int incl = prev2 + nums[i];    
        int excl = prev1 + 0;

        int ans = max(incl , excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
/*
Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11
*/


//HOUSE ROBBER II                                                              {T.C = O(N), S.C = O(1)}
//SPACE OPTIMIZATION
long long int solve(vector<int> &nums){
    int n = nums.size();
    //step-1 create dp array
    long long int prev2 = 0;
    long long int prev1 = nums[0];

    //step-2 loop
    for(int i = 1 ; i < n ; i++){          //loop from second element
        long long int incl = prev2 + nums[i];    
        long long int excl = prev1 + 0;

        long long int ans = max(incl , excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();

    if(n == 1){
        return valueInHouse[0];
    }
    //create vector
    vector<int>first,second;
    // vector<int>second;

    //initialize vector
    for(int i = 0 ; i < n ; i++){
        if(i != n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(first), solve(second));
}
/*
Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4
*/


//CUT INTO SEGMENTS / ROD CUTTING PROBLEM
//RECURSION + MEMOIZATION                                                      {T.C = O(N), S.C = O(N) + O(N) = O(N)}
#include<limits.h>
int solveMem(int n , int x , int y , int z , vector<int>&dp){
	//base case
	if(n == 0){
		return 0;
	}
	if(n < 0){
		return INT_MIN;
	}

	//step-3
	if(dp[n] != -1){
		return dp[n];
	}

	//step-2 store ans in dp
	int a = solveMem(n-x, x, y, z, dp) + 1;
	int b = solveMem(n-y, x, y, z, dp) + 1;
	int c = solveMem(n-z, x, y, z, dp) + 1;

	dp[n] = max(a, max(b,c));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	
	//create dp array
	vector<int>dp(n+1, -1);
	int ans = solveMem(n, x , y , z , dp);
	if(ans < 0){
		return 0;
	}
	else{
		return ans;
	}
}

//TABULATION METHOD                                                               {T.C = O(N), S.C = O(N)}
int solveTab(int n , int x , int y , int z){
	vector<int>dp(n+1, INT_MIN);
	dp[0] = 0;

	for(int i = 1 ; i <= n ; i++){
		if(i-x >= 0){
			dp[i] = max(dp[i], dp[i-x] + 1);
		}
		if(i-y >= 0){
			dp[i] = max(dp[i], dp[i-y] + 1);
		}
		if(i-z >= 0){
			dp[i] = max(dp[i], dp[i-z] + 1);
		}
	}
	if(dp[n] < 0){
		return 0;
	}
	else{
		return dp[n];
	}
}
int cutSegments(int n, int x, int y, int z) {
	return solveTab(n, x, y, z);
}
/*
Sample Input 1:
2
7 5 2 2
8 3 3 3
Sample Output 1:
2
0
*/


//COUNT DERANGEMENTS
#define MOD 1000000007
#include<vector>

//RECURSION - TLE                                                               {T.C = O(2^N), S.C = O(N)}
long long int countDerangements(int n) {
    //base case
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    int ans = (((n-1)%MOD) * ((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)))%MOD;

    return ans;
}

//RECURSION + MEMOIZATION                                                       {T.C = O(N), S.C = O(N)+O(N)= O(N)}
long long int solveMem(int n, vector<long long int>&dp){
    //base case
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    //step-3
    if(dp[n] != -1){
        return dp[n];
    }

    //step-2 store ans in dp array
    dp[n] = (((n-1)%MOD) * ((solveMem(n-1, dp)%MOD) + (solveMem(n-2,dp)%MOD)))%MOD;

    return dp[n];
}
long long int countDerangements(int n){

    //step-1 create dp array
    vector<long long int>dp(n+1, -1);

    return solveMem(n, dp);
}

//TABULATION METHOD                                                           {T.C = O(N), S.C = O(N)}
long long int solveMem(int n){

    vector<long long int>dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3 ; i <= n ; i++){
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;

        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n){

    return solveMem(n);
}

//SPACE OPTIMIZATION                                                         {T.C = O(N), S.C = O(1)}
long long int solveMem(int n){

    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3 ; i <= n ; i++){
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((i-1) * sum) % MOD;

        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}
long long int countDerangements(int n){

    return solveMem(n);
}
/*
Sample Input 2:
2
1
4
Sample Output 2:
0
9
*/


//NINJA AND THE FENCE 
#include <bits/stdc++.h> 
#define MOD 1000000007

//RECURSION
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;                   //1LL 64 bit integer multiplication
}
int solve(int n ,int k){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return  add(k,mul(k,k-1));                                 //k+k(k-1)
    }

    // solve(n) = solve((n-2)*(k-1)) + solve((n-1)*(k-1))
    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    return solve(n,k);
}

//RECURSION + MEMOIZATION
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;                   //1LL 64 bit integer multiplication
}
int solveMem(int n ,int k,vector<int>&dp){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return  add(k,mul(k,k-1));                                 //k+k(k-1)
    }

    //step-2 
    if(dp[n] != -1){
        return dp[n];
    }
    //step-3 storne ans in dp array
    // solve(n) = solve((n-2)*(k-1)) + solve((n-1)*(k-1))
    dp[n] = add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    //step-1 create dp array
    vector<int>dp(n+1, -1);
    return solveMem(n,k,dp);
}

//TABULATION METHOD
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}
int solveTab(int n ,int k){
    vector<int>dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));

    for (int i = 3; i <= n; i++) {
      dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
    return solveTab(n,k);
}

//SPACE OPTIMIZATION
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}
int solveSO(int n ,int k){
    int prev2 = k;
    int prev1 = add(k,mul(k,k-1));

    for (int i = 3; i <= n; i++) {
      int ans = add(mul(prev2, k-1), mul(prev1, k-1));
      prev2 = prev1;
      prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
    return solveSO(n,k);
}

/*
Sample Input 2 :
2
2 4
4 2
Sample Output 2 :
16
10
*/