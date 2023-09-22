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


//2D DP 
//0-1 KNAPSACK

//RECURSION(TLE)
int solve(vector<int>&weight, vector<int>&value, int index , int capacity){
	//base case
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}
		return 0;
	}

	int include =  0;
	if(weight[index] <= capacity){
		include = value[index] + solve(weight,value,index-1, capacity-weight[index]);
	}
	int exclude = 0 + solve(weight, value, index-1, capacity);

	int ans = max(include, exclude);
	return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//right to left approach
	return solve(weight, value, n-1, maxWeight);
}

//RECURSION + MEMOIZATION
int solveMem(vector<int>&weight, vector<int>&value, int index , int capacity, vector<vector<int>>&dp){
	//base case
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}
		return 0;
	}

	//step-3 
	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	int include =  0;
	if(weight[index] <= capacity){
		include = value[index] + solveMem(weight,value,index-1, capacity-weight[index], dp);
	}
	int exclude = 0 + solveMem(weight, value, index-1, capacity,dp);

	//step-2 store ans in dp
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//right to left approach
	//step-1 create 2D dp array(2 variables are changing in recursion relations
	vector<vector<int>>dp(n,vector<int>(maxWeight+1, -1));         //n = row , vector<int>() = col

	return solveMem(weight, value, n-1, maxWeight,dp);
}

//TABULATION METHOD
int solveTab(vector<int>&weight, vector<int>&value, int n , int capacity){
	//step-1 create 2D dp array with 0 initialization
	vector<vector<int>>dp(n, vector<int>(capacity+1, 0));

	//step-2 analyze base case
	for(int w = weight[0] ; w <= capacity ; w++){
		if(weight[0] <= w){
			dp[0][w] = value[0];
		}
		else{
			dp[0][w] = 0;
		}
	}

	//step-3 take care of remaining recursive call
	for(int index = 1 ; index < n ; index++){
		for(int w = 0 ; w <= capacity ; w++){
			int include =  0;
			if(weight[index] <= w){
				include = value[index] + dp[index-1][w-weight[index]];
			}
			int exclude = 0 + dp[index-1][w];

			//step-2 store ans in dp
			dp[index][w] = max(include, exclude);
		}
	}
	return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTab(weight, value, n, maxWeight);
}
/*
Sample Input:
1 
4
1 2 4 5
5 4 8 6
5
Sample Output:
13
*/


//COMBINATION SUM IV

//RECURSION - (TLE)                                                    {T.C = 2^N(EXPONENTIAL)}
int solve(vector<int>&num, int tar){
    //base case
    if(tar < 0){
        return 0;
    }
    if(tar == 0){
        return 1;
    }

    int ans = 0;
    for(int i = 0 ; i < num.size() ; i++){
        ans = ans + solve(num, tar-num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    return solve(num , tar);
}

//RECURSION + MEMOIZATION                                                    {T.C = O(TAR*N) , S.C = O(N)+O(N)}
int solveMem(vector<int>&num, int tar, vector<int>&dp){
    //base case
    if(tar < 0){
        return 0;
    }
    if(tar == 0){
        return 1;
    }

    //step-3 
    if(dp[tar] != -1){
        return dp[tar];
    }

    //step-2 
    int ans = 0;
    for(int i = 0 ;i < num.size() ;i++){
        ans = ans + solveMem(num, tar-num[i] , dp);
    }
    dp[tar] = ans;
    return dp[tar];
   
}
int findWays(vector<int> &num, int tar)
{
    //step-1 create dp array
    vector<int>dp(tar+1, -1);
    return solveMem(num , tar, dp);
}

//TABULATION                                                               {T.C = O(TAR*N), S.C = O(TAR)}
int solveTab(vector<int>&num, int tar){
    //create dp array
    vector<int>dp(tar+1, 0);

    //analyze base case
    dp[0] = 1;

    //loop
    //traversing from target 1 to tar
    for(int i = 1; i <= tar ; i++){
        //traversing on num vector
        for(int j = 0 ;j < num.size() ; j++){
            if(i-num[j] >= 0){
                dp[i] = dp[i] + dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    return solveTab(num , tar);
}
/*
Sample Input 1 :
2
3 5
1 2 5
2 3
1 2
Sample Output 1 :
9
3
*/


//GET MINIMUM SQUARES

//RECURSION
class Solution{
	public:
	int solve(int n){
	    //base case
	    if(n == 0){
	        return 0;
	    }
	    
	    int ans = n;
	    for(int i = 1 ; i*i <= n ; i++){
	        int temp = i*i;
	        ans = min(ans, 1+solve(n-temp));
	    }
	    return ans;
	}
	int MinSquares(int n)
	{
	    return solve(n);
	}
};

//RECURSION + MEMOIZATION                                            {T.C = O(N*(SQRTN)), S.C = O(N)}
class Solution{
	public:
	int solveMem(int n, vector<int>&dp){
	    //base case
	    if(n == 0){
	        return 0;
	    }
	    
	    //step-3
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    
	    int ans = n;
	    for(int i = 1 ; i*i <= n ; i++){
	        int temp = i*i;
	        ans = min(ans, 1+solveMem(n-temp,dp));
	    }
	    dp[n] = ans;
	    return dp[n];
	}
	int MinSquares(int n)
	{   
	    //step-1 create dp array
	    vector<int>dp(n+1, -1);
	    return solveMem(n, dp);
	}
};
//TABULATION METHOD
class Solution{
	public:
	int solveTab(int n){
	    //create dp array
	    vector<int>dp(n+1, INT_MAX);                  //finding (min) answer
	    
	    //analyze base case
	    dp[0] = 0;
	    
	    //loop
	    for(int i = 1 ; i <= n; i++){                 //dp loop
	        for(int j = 1 ; j*j <= n ; j++){          // actual loop
	            int temp = j*j;
	            if(i-temp >= 0){                      //extra condition to check
	               dp[i] = min(dp[i], 1+dp[i-temp]);
	            }
	        }
	    }
	    return dp[n];
	    
	}
	int MinSquares(int n)
	{   
	    return solveTab(n);
	}
};

/*
Input: N = 100
Output: 1
Explanation: 10 * 10 = 100
*/


//NINJA'S TRIP
//RECURSION                                                   {T.C = O(3^N), S.C = O(N)}
int solve(int n , vector<int>&days, vector<int>&cost, int index){
    //base case
    if(index >= n){
        return 0;
    }

    //1 day pass
    int option1 = cost[0] + solve(n, days, cost, index+1);

    //7 days pass
    int i;
    for(i = index ; i < n && days[i] < days[index] + 7 ; i++);

    int option2 = cost[1] + solve(n, days, cost, i);

    //30 days pass
    for(i = index ; i < n && days[i] < days[index] + 30 ; i++);
    
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));

}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, 0);
}

//RECURSION + MEMOIZATION                                              {T.C = O(N) , S.C = O(N)}
int solveMem(int n , vector<int>&days, vector<int>&cost, int index, vector<int>&dp){
    //base case
    if(index >= n){
        return 0;
    }

    //step-3
    if(dp[index] != -1){
        return dp[index];
    }

    //1 day pass
    int option1 = cost[0] + solveMem(n, days, cost, index+1, dp);

    //7 days pass
    int i;
    for(i = index ; i < n && days[i] < days[index] + 7 ; i++);

    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    //30 days pass
    for(i = index ; i < n && days[i] < days[index] + 30 ; i++);
    
    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    //step-2 store ans in dp
    dp[index] = min(option1, min(option2, option3));

    return dp[index];

}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    //step-1 create dp array
    vector<int>dp(n+1, -1);

    return solveMem(n, days, cost, 0, dp);
}

//TABULATION METHOD                                            {T.C = O(N) , S.C = O(N)}
int solveTab(int n , vector<int>&days, vector<int>&cost){
    //step-1 create dp array with initial 0
    vector<int>dp(n+1, INT_MAX);            //for finding minimum

    //step-2 analyze base case
    dp[n] = 0;

    //step-3 loop
    for(int k = n-1 ; k >= 0 ;k--){
        //1 day pass
        int option1 = cost[0] + dp[k+1];

        //7 days pass
        int i;
        for(i = k ; i < n && days[i] < days[k] + 7 ; i++);

        int option2 = cost[1] + dp[i];

        //30 days pass
        for(i = k ; i < n && days[i] < days[k] + 30 ; i++);
        
        int option3 = cost[2] + dp[i];

        //step-2 store ans in dp
        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];

}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solveTab(n, days, cost);
}

//SPACE OPTIMIZATION                                              {T.C = O(N), S.C = O(1)}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;

    queue<pair<int,int>>week;
    queue<pair<int,int>>month;

    for(int day : days){
        //step-1 remove expired days from week and month
        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }

        //step-2 add cost for current day
        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));

        //step-3 ans update
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}
/*
Sample Input 1:
2
2 
2 5
1 4 25    
7
1 3 4 5 7 8 10
2 7 20
Sample Output 1:
2
11
*/


//LARGEST SQUARE FORMED IN A MATRIX                                                   {T.C = EXP}
class Solution{
public:
    int solve(vector<vector<int>>&mat, int i , int j , int &maxi){
        //base case
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        
        if(mat[i][j] == 1){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi = 0;
        solve(mat, 0 , 0, maxi);
        return maxi;
    }
};

//RECURSION + MEMOIZATION                                          {T.C = O(N*M), S.C = O(N*M)}
class Solution{
public:
    int solveMem(vector<vector<int>>&mat, int i , int j , int &maxi, vector<vector<int>>&dp){
        //base case
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        //step-3 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        //step-2 store ans in dp
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        //step-1 creat dp array
        int maxi = 0;
        vector<vector<int>>dp(n, vector<int>(m , -1));
        solveMem(mat, 0, 0, maxi, dp);
        return maxi;
    }
};

//TABULATION METHOD                                                 {T.C = O(N*M), S.C = O(N*M)}
class Solution{
public:
    int solveTab(vector<vector<int>>&mat,int &maxi){
        
        //step-1 create dp array and initialize with 0
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>dp(row+1, vector<int>(col+1, 0));
        
        //step-2 analyze base case
        //no need
        
        
        //step-3 for loop
        for(int i = row-1 ; i >= 0 ; i--){
            for(int j = col-1 ;j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
                
            }
        }
        return dp[0][0];
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi = 0;
        solveTab(mat,maxi);
        return maxi;
    }
};
/*
Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
*/


//MINIMUM SCORE TRIANGULATION OF POLYGON
//RECURSION                                                          {T.C = O(2^N), S.C = O(N)}
class Solution {
public:

    int solve(vector<int>&v , int i , int j){
        //base case
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1 ; k < j ; k++){                        //loop i+1 to j-1 
            ans = min(ans, v[i]*v[j]*v[k] + solve(v, i , k) + solve(v , k , j));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0 , n-1);
    }
};

//RECURSION + MEMOIZATION                                    {T.C = O(N^3), S.C = O(N^2)}
class Solution {
public:

    int solveMem(vector<int>&v , int i , int j , vector<vector<int>>&dp){
        //base case
        if(i+1 == j){
            return 0;
        }
        //step-3
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i+1 ; k < j ; k++){                        //loop i+1 to j-1 
            ans = min(ans, v[i]*v[j]*v[k] + solveMem(v, i , k, dp) + solveMem(v , k , j, dp));
        }
        //step-2 store ans in dp
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        //step-1 create dp vector
        vector<vector<int>>dp(n,vector<int>(n, -1));
        return solveMem(values, 0 , n-1 , dp);
    }
};

//TABULATION METHOD                                          {T.C = O(N^3), S.C = O(N^2)}
class Solution {
public:

    int solveTab(vector<int>&v){
        int n = v.size();
        //step-1 create dp array with initilize 0
        vector<vector<int>>dp(n, vector<int>(n, 0));

        //step-2 analyze base case
        for(int i = n-1 ;i >= 0 ; i--){
            for(int j = i+2 ; j < n ;j++){
                int ans = INT_MAX;
                for(int k = i+1 ; k < j ; k++){
                    ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        return solveTab(values);
    }
};
/*
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.
*/


//MINIMUM SIDEWAY JUMP
//RECURSION                                                        {T.C = O(3^N) , S.C = O(N^2)}
class Solution {
public:
    int solve(vector<int>&obs , int currLane , int currPos){
        //base case
        int n = obs.size()-1;                                   //obstacles  = lanes + 1
        if(currPos == n){
            return 0;
        }

        //move forward
        if(obs[currPos+1] != currLane){
            return solve(obs, currLane, currPos+1);
        }
        else{
            //sideways jump
            int ans = INT_MAX;
            for(int i = 1 ; i <=3 ; i++){
                if(currLane != i && obs[currPos] != i){
                    ans = min(ans, 1+solve(obs, i, currPos));
                }
            }
            return ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2 , 0);
    }
};

//RECURSION + MEMOIZATION                                             {T.C = O(N) , S.C = O(N)}
class Solution {
public:
    int solveMem(vector<int>&obs , int currLane , int currPos, vector<vector<int>>&dp){
        //base case
        int n = obs.size()-1;                                   //obstacles  = lanes + 1
        if(currPos == n){
            return 0;
        }

        //step-3 
        if(dp[currLane][currPos] != -1){
            return dp[currLane][currPos];
        }

        //move forward
        if(obs[currPos+1] != currLane){
            return solveMem(obs, currLane, currPos+1, dp);
        }
        else{
            //sideways jump
            int ans = INT_MAX;
            for(int i = 1 ; i <=3 ; i++){
                if(currLane != i && obs[currPos] != i){
                    ans = min(ans, 1+solveMem(obs, i, currPos, dp));
                }
            }
            //step-3 store ans in dp
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        //step-1 create dp array
        int n = obstacles.size();
        vector<vector<int>>dp(4, vector<int>(n, -1));

        return solveMem(obstacles, 2 , 0, dp);
    }
};
/*
Input: obstacles = [0,1,2,3,0]
Output: 2 
Explanation: The optimal solution is shown by the arrows above. There are 2 side jumps (red arrows).
Note that the frog can jump over obstacles only when making side jumps (as shown at point 2).
*/


//REDUCING DISHES
//RECURSION                                                            {T.C = O(2^N) , S.C = O(N)}
class Solution {
public:
    int solve(vector<int>&satis , int index , int time ){
        //base case
        if(index == satis.size()){
            return 0;
        }

        int include = satis[index]*(time+1) + solve(satis, index+1, time+1);
        int exclude = 0 +  solve(satis, index+1, time);

        return max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort the vector
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction , 0 , 0);                  //index = 0 , time = 0
    }
};

//RECURSION + MEMOIZATION                                              {T.C = O(N^2) , S.C = O(N^2)}
class Solution {
public:
    int solveMem(vector<int>&satis , int index , int time , vector<vector<int>>&dp ){
        //base case
        if(index == satis.size()){
            return 0;
        }
        //step-3
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int include = satis[index]*(time+1) + solveMem(satis, index+1, time+1, dp);
        int exclude = 0 +  solveMem(satis, index+1, time, dp);

        //step-2 store ans in dp array
        dp[index][time] =  max(include, exclude);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        //sort the vector
        sort(satisfaction.begin(), satisfaction.end());
        //step-1 create dp array 
        vector<vector<int>>dp(n+1, vector<int>(n+1 , -1));            
        return solveMem(satisfaction , 0 , 0 , dp);                  //index = 0 , time = 0
    }
};

//TABULATION METHOD                                                  {T.C = O(N^2) , S.C = O(N^2)}
class Solution {
public:
    int solveTab(vector<int>&satis){
        int n = satis.size();
        //step-1 create dp vector with initialize 0
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        //step-2 analyze base case
        //no need;

        //step 3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int time = index ; time >= 0 ; time--){
                int include = satis[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0 +  dp[index+1][time];

                dp[index][time] =  max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort the vector
        sort(satisfaction.begin(), satisfaction.end());

        return solveTab(satisfaction);   
    }
};

//SPACE OPTIMIZATION                                                     {T.C = O(N^2) , S.C = O(N)}
class Solution {
public:
    int solveSO(vector<int>&satis){
        int n = satis.size();

        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);

        //step 3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int time = index ; time >= 0 ; time--){
                int include = satis[index]*(time+1) + next[time+1];       //dp[index+1][time+1] = next
                int exclude = 0 +  next[time];

                curr[time] =  max(include, exclude);                      //dp[index][time] = curr[time]
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort the vector
        sort(satisfaction.begin(), satisfaction.end());

        return solveSO(satisfaction);   
    }
};
/*
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
*/


//LONGEST INCREASING SUBSEQUENCE
//RECURSION              (TLE)
class Solution
{
    public:
    int solve(int n , int a[] , int curr , int prev){
        //base case
        if(curr == n){
            return 0;
        }
        
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solve(n , a , curr+1 , curr);
        }
        int exclude = 0 + solve(n , a , curr+1 , prev);
        
        return max(include , exclude);
    }
    int longestSubsequence(int n, int a[])
    {
       return solve(n , a , 0 , -1);                   //curr = 0 , prev = -1
    }
};

//RECURSION + MEMOIZATION                                         {T.C = O(N^2) , S.C = O(N^2)}
class Solution
{
    public:
    int solveMem(int n , int a[] , int curr , int prev, vector<vector<int>>&dp){
        //base case
        if(curr == n){
            return 0;
        }
        
        //step-3 
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int include = 0;
        if(prev == -1 || a[curr] > a[prev]){
            include = 1 + solveMem(n , a , curr+1 , curr, dp);
        }
        int exclude = 0 + solveMem(n , a , curr+1 , prev, dp);
        
        //step-2 store ans in dp
        dp[curr][prev+1] =  max(include , exclude);                  //prev+1 for valid i.e prev == -1
        return dp[curr][prev+1];
    }
    int longestSubsequence(int n, int a[])
    {
        //step-1 creat a dp array
        vector<vector<int>>dp(n, vector<int>(n , -1));          //col = n+1 = -1 to n-1 
        return solveMem(n , a , 0 , -1 , dp);                   //curr = 0 , prev = -1
    }
};

//TABULATION METHOD                                              {T.C = O(N^2) , S.C = O(N^2)}
class Solution
{
    public:
    int solveTab(int n , int a[]){
        //step-1 create dp vector initialize with 0
        vector<vector<int>>dp(n+1, vector<int>(n+1 , 0));
        
        //step-2 analyze base case
        //no need
        
        //step-3 loop
        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){
                int include = 0 ;
                if(prev == -1 || a[curr] > a[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int longestSubsequence(int n, int a[])
    {
        return solveTab(n , a);
    }
};

//SPACE OPTIMIZATION 

//DP WITH BINARY SEARCH                                            {T.C = O(N*LOGN), S.C = O(N)}
class Solution {
public:
    int solveOptimal(int n, int a[]) {
        //base case
        if(n == 0){
            return 0;
        }
        
        vector<int>ans;
        ans.push_back(a[0]);
        
        for(int i = 1 ; i < n ; i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just big element
                int index = lower_bound(ans.begin(), ans.end() , a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

    int longestSubsequence(int n, int a[]) {
        return solveOptimal(n, a);
    }
};
/*
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
*/


//MAXIMUM HEIGHT BY STACKING CUBOIDS                                            {T.C = O(N^2) , S.C = O(N)}
class Solution { 
public:
    bool check(vector<int>base, vector<int>newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solveLIS(int n , vector<vector<int>>&a){
        vector<int>currRow(n+1, 0);
        vector<int>nextRow(n+1, 0);

        for(int curr = n-1 ; curr >= 0 ; curr--){
            for(int prev = curr-1 ; prev >= -1 ; prev--){
                int include = 0 ;
                if(prev == -1 || check(a[curr], a[prev])){
                    include = a[curr][2] + nextRow[curr+1];
                }
                int exclude = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //step-1 sort all dimensions of all cuboids
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }

        //step-2 sort all cuboids basis of w or l
        sort(cuboids.begin(), cuboids.end());

        //step-2 use LIS(longest increasing subsequence)
        return solveLIS(cuboids.size(), cuboids);
    }
};

/*
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
*/


//PIZZA WIHT 3N SLICES (SIMILAR TO HOUSE ROBERY)
//RECURSION
class Solution {
public:
    int solve(int index , int endIndex , vector<int>&slices, int n){
        if(n == 0 || index > endIndex){
            return 0;
        }

        int include = slices[index] + solve(index+2, endIndex, slices, n-1);
        int exclude = 0 + solve(index+1, endIndex, slices, n);

        return max(include, exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0 , k-2 , slices, k/3);             //starting index(included) ending index(excluded)
        int case2 = solve(1 , k-1 , slices ,k/3);             //starting index(excluded) ending index(included)
        return max(case1 , case2);
    }
};

//RECURSION + MEMOIZATION                                                 {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    int solveMem(int index , int endIndex , vector<int>&slices, int n , vector<vector<int>>&dp){
        if(n == 0 || index > endIndex){
            return 0;
        }

        //step-3
        if(dp[index][n] != -1 ){
            return dp[index][n];
        }

        int include = slices[index] + solveMem(index+2, endIndex, slices, n-1, dp);
        int exclude = 0 + solveMem(index+1, endIndex, slices, n , dp);

        //step-2 store ans in dp 

        dp[index][n] =  max(include, exclude);
        return dp[index][n];
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        //step-1 create dp array
        vector<vector<int>>dp1(k, vector<int>(k, -1));
        int case1 = solveMem(0 , k-2 , slices, k/3, dp1);             //starting index(included) ending index(excluded)

        vector<vector<int>>dp2(k, vector<int>(k, -1));
        int case2 = solveMem(1 , k-1 , slices ,k/3, dp2);             //starting index(excluded) ending index(included)
        return max(case1 , case2);
    }
};

//TABULATION METHOD                                                     {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    int solveTab(vector<int>&slices){
        int k = slices.size();
        //step-1 create dp array 0
        vector<vector<int>>dp1(k+2,vector<int>(k+2 , 0) );          //k+2 to abort index out
        vector<vector<int>>dp2(k+2, vector<int>(k+2, 0));

        //step-2 analyze base case
        //no need
        for(int index = k-2 ; index >= 0 ; index--){
            for(int n = 1 ; n <= k/3 ; n++ ){
                int include = slices[index] + dp1[index+2][n-1];
                int exclude = 0 + dp1[index+1][n];

                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index = k-1 ; index >= 1 ; index--){
            for(int n = 1 ; n <= k/3 ; n++ ){
                int include = slices[index] + dp2[index+2][n-1];
                int exclude = 0 + dp2[index+1][n];

                dp2[index][n] = max(include, exclude);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1 , case2);
    }
    int maxSizeSlices(vector<int>& slices) {
        return solveTab(slices);
    }
};

//SPACE OPTIMIZATION

/*
Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.
*/


//DP - DISTINCT WAYS PATTERN
//DICE THROW 
//RECURSION
class Solution {
  public:
    int solve(int faces , int dice , int target){
        //base case
        if((target < 0) || (target == 0 && dice != 0) || (target != 0 && dice == 0) ){
            return 0;
        }
        if(target == 0 && dice == 0){
            return 1;
        }
        
        //loop
        long long ans = 0;
        for(int i = 1 ; i <= faces ; i++){
            ans = ans + solve(faces , dice-1 , target - i);
        }
        return ans;
    }
    long long noOfWays(int M , int N , int X) {
        return solve(M, N, X);
    }
};

//RECURSION + MEMOIZATION                                                   {T.C = O(M*N*X), S.C = O(N*X)}
class Solution {
  public:
    long long solveMem(int faces , int dice , int target, vector<vector<long long>>&dp){
        //base case
        if((target < 0) || (target == 0 && dice != 0) || (target != 0 && dice == 0) ){
            return 0;
        }
        if(target == 0 && dice == 0){
            return 1;
        }
        
        //step-3
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        
        //loop
        long long ans = 0;
        for(int i = 1 ; i <= faces ; i++){
            ans = ans + solveMem(faces , dice-1 , target - i, dp);
        }
        //step-2 store ans in dp
        dp[dice][target] = ans;
        return dp[dice][target];
    }
    long long noOfWays(int M , int N , int X) {
        //step-1 create a dp vector
        vector<vector<long long>>dp(N+1, vector<long long>(X+1 , -1));
        return solveMem(M, N, X, dp);
    }
};

//TABULATION METHOD                                                   {T.C = O(M*N*X), S.C = O(N*X)}
class Solution {
  public:
    long long solveTab(int f , int d , int t){
        //step-1 create dp array 0
        vector<vector<long long >>dp(d+1, vector<long long>(t+1, 0));
        
        //step-2 analyze base case
        dp[0][0] = 1;
        
        //step-3 loop
        for(int dice = 1 ; dice <= d ; dice++){
            for(int target = 1 ; target <= t ; target++){
                long long ans = 0;
                for(int i = 1 ; i <= f ; i++){
                    if(target-i >= 0){
                        ans = ans + dp[dice-1][target-i];
                    }
                }
                dp[dice][target] = ans;
            }
        }
        return dp[d][t];
    }
    long long noOfWays(int M , int N , int X) {
        return solveTab(M, N, X);
    }
};

//SPACE OPTIMIZATION                                                       {T.C = O(M^N*X), S.C = O(X)}
class Solution {
  public:
    long long solveTab(int f , int d , int t){
        //step-1 create dp array 0
        vector<long long> prev(t+1, 0);
        vector<long long> curr(t+1, 0);
        
        //step-2 analyze base case
        prev[0] = 1;
        
        //step-3 loop
        for(int dice = 1 ; dice <= d ; dice++){
            for(int target = 1 ; target <= t ; target++){
                long long ans = 0;
                for(int i = 1 ; i <= f ; i++){
                    if(target-i >= 0){
                        ans = ans + prev[target-i];
                    }
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return prev[t];
    }
    long long noOfWays(int M , int N , int X) {
        return solveTab(M, N, X);
    }
};
/*
Input:
M = 6, N = 3, X = 12
Output:
25
Explanation:
There are 25 total ways to get
the Sum 12 using 3 dices with
faces from 1 to 6.
*/


//PARTITION EQUAL SUBSET SUM
//RECURSION
class Solution{
public:
    bool solve(int n , int arr[] , int index , int target){
        //base case
        if((index >= n) || (target < 0)){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        
        bool include = solve(n, arr, index+1 , target - arr[index]);
        bool exclude = solve(n , arr , index+1 , target);
        
        return include or exclude;
    }
    
    int equalPartition(int n, int arr[])
    {
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            total = total + arr[i];
        }
        if(total & 1){                        //odd no.
            return 0;
        }
        int target = total/2;
        
        return solve(n , arr, 0 , target);      //0 = index
    }
};

//RECURSION + MEMOIZATION                                                                {T.C = O(N*TOTAL) , S.C = (N*TOTAL)}
class Solution{
public:
    bool solveMem(int n , int arr[] , int index , int target ,vector<vector<int>>&dp){
        //base case
        if((index >= n) || (target < 0)){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        
        //step-3 
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        bool include = solveMem(n, arr, index+1 , target - arr[index] , dp);
        bool exclude = solveMem(n , arr , index+1 , target ,dp);
        
        //step-2 store ans in dp
        dp[index][target] = include or exclude;
        return dp[index][target];
    }
    
    int equalPartition(int n, int arr[])
    {
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            total = total + arr[i];
        }
        if(total & 1){                        //odd no.
            return 0;
        }
        int target = total/2;
        
        //step-1 create dp vector
        vector<vector<int>>dp(n, vector<int>(target+1 , -1));
        return solveMem(n , arr, 0 , target , dp);      //0 = index
    }
};

//TABULATION METHOD                                                                      {T.C = O(N*TOTAL) , S.C = (N*TOTAL)}
class Solution{
public:
    bool solveTab(int n , int arr[], int total){
        
        //step-1 create dp array 0
        vector<vector<int>>dp(n+1, vector<int>(total+1 , 0));
        
        //step-2 analyze base case
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;        
        }
        
        //loop
        for(int index = n-1 ; index >= 0  ; index--){
            for(int target = 0 ; target <= total/2 ; target++){
                bool include = 0;
                if(target - arr[index] >= 0){
                    include = dp[index+1][target-arr[index]];
                }
                bool exclude = dp[index+1][target];
                
                dp[index][target] = include or exclude;
            }
        }
        return dp[0][total/2];
    }
    
    int equalPartition(int n, int arr[])
    {
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            total = total + arr[i];
        }
        if(total & 1){                        //odd no.
            return 0;
        }
        
        return solveTab(n , arr , total);
    }
};

//SPACE OPTIMIZATION                                                                {T.C = O(N*TOTAL) , S.C = (TOTAL)}
class Solution{
public:
    bool solveTab(int n , int arr[], int total){
    
        vector<int>curr(total+1, 0);
        vector<int>next(total+1, 0);
            
        curr[0] = 1;
        next[0] = 1;

        //loop
        for(int index = n-1 ; index >= 0  ; index--){
            for(int target = 0 ; target <= total/2 ; target++){
                bool include = 0;
                if(target - arr[index] >= 0){
                    include = next[target-arr[index]];
                }
                bool exclude = next[target];
                
                curr[target] = include or exclude;
            }
            next = curr;
        }
        return next[total/2];
    }
    
    int equalPartition(int n, int arr[])
    {
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            total = total + arr[i];
        }
        if(total & 1){                        //odd no.
            return 0;
        }
        
        return solveTab(n , arr , total);
    }
};
/*
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
*/


//MINIMUM SWAPS TO MAKE SEQUENCES INCREASING
//RECURSION
class Solution {
public:
    int solve(vector<int>&nums1, vector<int>&nums2 , int index, bool swapped){
        //base case
        if(index == nums1.size()){
            return 0;
        }

        int ans = INT_MAX;                                       //finding minimum ans
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped){
            swap(prev1, prev2);
        }

        //no swap
        if(nums1[index] > prev1 &&  nums2[index] > prev2){
            ans = solve(nums1, nums2, index+1, 0);
        }

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans , 1 + solve(nums1, nums2, index+1, 1));
        }

        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);                           //insert -1 in beginning of array
        nums2.insert(nums2.begin(),-1);

        bool swapped = 0;
        return solve(nums1, nums2, 1, swapped);                   //index = 1;
    }
};

//RECURSION + MEMOIZATION                                                            {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveMem(vector<int>&nums1, vector<int>&nums2 , int index, bool swapped, vector<vector<int>>&dp){
        //base case
        if(index == nums1.size()){
            return 0;
        }

        //step-3
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int ans = INT_MAX;                                       //finding minimum ans
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        //catch
        if(swapped){
            swap(prev1, prev2);
        }

        //no swap
        if(nums1[index] > prev1 &&  nums2[index] > prev2){
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        }

        //swap
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans , 1 + solveMem(nums1, nums2, index+1, 1, dp));
        }

        //step-2 store ans in dp
        dp[index][swapped] = ans;
        return dp[index][swapped];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);                           //insert -1 in beginning of array
        nums2.insert(nums2.begin(),-1);

        bool swapped = 0;
        //step-1 create dp vector
        int n = nums1.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));             //n = size, 2 = bool = 0 / 1
        return solveMem(nums1, nums2, 1, swapped, dp);                   //index = 1;
    }
};

//TABULATION METHOD(NOT WORKED)                                                          {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveTab(vector<int>&nums1, vector<int>&nums2){
        int n = nums1.size();
        //step-1 create dp vector initialize with 0
        vector<vector<int>>dp(n+1 , vector<int>(2, 0));             //n+1  to remove segmentation fault
        
        //step-2 analyze base case
        //no need

        //step-2 loop
        for(int index = n-1 ; index >= 1 ; index--){
            for(int swapped = 1 ; swapped >= 0 ; swapped++){

                int ans = INT_MAX;                                       //finding minimum ans
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                //catch
                if(swapped){
                    swap(prev1, prev2);
                }

                //no swap
                if(nums1[index] > prev1 &&  nums2[index] > prev2){
                    ans = dp[index+1][0];
                }

                //swap
                if(nums1[index] > prev2 && nums2[index] > prev1){
                    ans = min(ans , 1 + dp[index+1][1]);
                }

                //step-2 store ans in dp
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);                           //insert -1 in beginning of array
        nums2.insert(nums2.begin(),-1);

        return solveTab(nums1, nums2);
    }
};

//SPACE OPTIMIZATION                                                                 {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int solveSO(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int swapCount = 0;
        int noSwapCount = 0;
        int currSwap = 0;
        int currNoSwap = 0;

        //step-2 loop
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {

                int ans = INT_MAX; //finding minimum ans
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                //catch
                if (swapped) {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                //no swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = noSwapCount;
                }

                //swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + swapCount);
                }

                if (swapped) {
                    currSwap = ans;
                } else {
                    currNoSwap = ans;
                }
            }
            swapCount = currSwap;
            noSwapCount = currNoSwap;
        }
        return min(swapCount, noSwapCount);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1); //insert -1 in beginning of array
        nums2.insert(nums2.begin(), -1);

        return solveSO(nums1, nums2);
    }
};

/*
Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.
*/


//DP + HASHING CONCEPTS PATTERN
//LONGEST ARITHMETIC PROGRESSION
//RECURSION
class Solution{   
public:
    int solve(int index , int diff , int a[]){
        //backward check
        //base case
        if(index < 0){
            return 0;
        }
        
        int ans = 0;
        for(int j = index-1 ; j >= 0 ; j--){
            if(a[index]-a[j] == diff){
                ans = max(ans, 1+ solve(j, diff, a));
            }
        }
        return ans;
    }
    int lengthOfLongestAP(int a[], int n) {
        if(n <= 2){                           //chosen element count 
            return n;
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                ans = max(ans, 2 + solve(i , a[j]-a[i] , a));
            }
        }
        return ans;
    }
};

//RECURSION + MEMOIZATION (NOT WORKING)                                                 {T.C = O(N^2), S.C = O(N^2)}
class Solution{   
public:
    int solveMem(int index , int diff , int a[] , unordered_map<int,int> dp[]){
        //backward check
        //base case
        if(index < 0){
            return 0;
        }
        
        //step-3
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans = 0;
        for(int j = index-1 ; j >= 0 ; j--){
            if(a[index]-a[j] == diff){
                ans = max(ans, 1+ solveMem(j, diff, a, dp));
            }
        }
        
        //step-2 store ans in dp
        dp[index][diff] = ans;
        return dp[index][diff];
    }
    int lengthOfLongestAP(int a[], int n) {
        if(n <= 2){                           //chosen element count 
            return n;
        }
        
        //step-1 create dp unordered map vector
        unordered_map<int,int>dp[n+1];
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                ans = max(ans, 2 + solveMem(i , a[j]-a[i] , a , dp));
            }
        }
        
        return ans;
    }
};

//TABULATION METHOD (NOT WORKING)                                                      {T.C = O(N^2), S.C = O(N^2)}
class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
        if(n <= 2){                           //chosen element count 
            return n;
        }
        
        int ans = 0;
        unordered_map<int,int>dp[n+1];
        for(int i = 1; i < n ;i++){
            for(int j = 0 ; j < i ;j++){
                int diff = a[i]-a[j];
                int cnt = 1;
                
                //check if answer is already present
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1+cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
/*
Input:
N = 6
set[] = {1, 7, 10, 13, 14, 19}
Output: 4
Explanation: The longest arithmetic 
progression is {1, 7, 13, 19}.
*/


//LONGEST ARITHMETIC SUBSEQUENCE OF GIVEN DIFFERENCE                                                         {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;

        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int temp = arr[i]-difference;
            int tempAns= 0;

            //check answer exist for temp already or not
            if(dp.count(temp)){
                tempAns = dp[temp];
            }

            //current answer update
            dp[arr[i]] = 1 + tempAns;

            //ans update
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};
/*
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].
*/


//UNIQUE BINARY SEARCH TREES
//RECURSION
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            ans = ans + numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};

//RECURSION + MEMOIZATION                                                              {T.C = O(N^2) , S.C = O(N)}
class Solution {
public:
    int solveMem(int n , vector<int>&dp){

        if(n <= 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        //root node
        for(int i = 1 ; i <= n ; i++){
            ans = ans + solveMem(i-1, dp)*solveMem(n-i, dp);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numTrees(int n) {
        //step-1 create dp vector
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);
    }
};

//TABULATION METHOD                                                           {T.C = O(N^2) , S.C = O(N)}
class Solution {
public:
    int solveTab(int n){
        //step-1 create dp vector initialize 0
        vector<int>dp(n+1, 0);

        //step-2 analyze base case
        dp[0] = dp[1] = 1;

        //step-3 loop
        //no. of nodes
        for(int i = 2 ; i <= n ; i++){
            //root nodes
            for(int j = 1 ; j <= i ; j++){
                dp[i] = dp[i] + dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        return solveTab(n);
    }
};
/*
Input: n = 3
Output: 5
*/


//GUESS NUMBER HIGHER OR LOWER
//RECURSION
class Solution {
public:
    int solve(int start, int end){
        //base case
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;                                 //finding minimum loss
        for(int i = start ; i <= end ; i++){
            ans = min(ans, i + max(solve(start,(i-1)), solve(i+1, end)));    //max = finding maximum profit
        }
        return ans;
    }
    int getMoneyAmount(int n) {
        return solve(1 , n);                           //range = 1 to n
    }
};

//RECURSION + MEMOIZATION                                                               {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    int solveMem(int start, int end, vector<vector<int>>&dp){
        //base case
        if(start >= end){
            return 0;
        }

        //step-3 
        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;                                 //finding minimum loss
        for(int i = start ; i <= end ; i++){
            ans = min(ans, i + max(solveMem(start,(i-1), dp), solveMem(i+1, end, dp)));    //max = finding maximum profit
        }
        //step-2 store ans in dp 
        dp[start][end] = ans;
        return dp[start][end];
    }
    int getMoneyAmount(int n) {
        //step-1 create dp vector
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveMem(1 , n, dp);                           //range = 1 to n
    }
};

//TABULATION METHOD                                                                     {T.C = O(N^2), S.C = O(N^2)}
class Solution {
public:
    int solveTab(int n){
        //step-1 create dp vector initialize 0
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));            //n+2 to remove run time error

        //step-2 analyze base case
        // no need

        //step-3 loop
        for(int start = n ; start >= 1 ; start--){
            for(int end = start ; end <= n ; end++){
                if(start == end){
                    continue;
                }
                else{
                    int ans = INT_MAX;                                 //finding minimum loss
                    for(int i = start ; i <= end ; i++){
                        ans = min(ans, i + max(dp[start][i-1], dp[i+1][end]));    //max = finding maximum profit
                    }
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];                                                //put same as main function
    }
    int getMoneyAmount(int n) {
        return solveTab(n);                           //range = 1 to n
    }
};
/*
Input: n = 10
Output: 16
*/


//MINIMUM COST TREE FROM LEAF VALUES
//RECURSION
class Solution {
public:
    int solve(vector<int>&arr, map<pair<int,int>,int>&maxi, int left , int right){
        //leaf node
        if(left == right){
            return 0;
        }

        int ans = INT_MAX;                                        //finding minimum ans
        for(int i = left ; i < right ; i++){                      // i< right last partition not valid
            ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
        }
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;

        for(int i = 0 ; i < arr.size() ; i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1 ; j < arr.size() ; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        return solve(arr, maxi, 0 , arr.size()-1);                       //0 to n index
    }
};

//RECURSION + MEMOIZATION                                                             {T.C = O(N^3), S.C = (N^3)}
class Solution {
public:
    int solveMem(vector<int>&arr, map<pair<int,int>,int>&maxi, int left , int right , vector<vector<int>>&dp){
        //leaf node
        if(left == right){
            return 0;
        }

        //step-3
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;                                        //finding minimum ans
        for(int i = left ; i < right ; i++){                      // i< right last partition not valid
            ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solveMem(arr, maxi, left, i ,dp) + solveMem(arr, maxi, i+1, right, dp));
        }
        //step-2 store ans in dp
        dp[left][right] = ans;
        return dp[left][right];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        //step-1 create dp vector
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for(int i = 0 ; i < n ; i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1 ; j < arr.size() ; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        return solveMem(arr, maxi, 0 , n-1 , dp);                       //0 to n index
    }
};
/*
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
*/


//BUY AND SELL STOCK PATTERN
//BEST TIME TO BUY AND SELL STOCK  I                                                  {T.C = O(N), S.C = O(1)}
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i = 1 ; i < prices.size() ; i++){                                    //i = 1 , sell on 1st day (0) is not allowed
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


//BEST TIME TO BUY AND SELL STOCK II
//On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of 
//the stock at any time. However, you can buy it then immediately sell it on the same day.
//RECURSION
class Solution {
public:
    int solve(int index, int buy, vector<int>&prices){
        if(index == prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(index+1, 0, prices);
            int skipKaro = 0 + solve(index+1, 1, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solve(index+1, 1, prices);
            int skipKaro = 0 + solve(index+1, 0, prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);                //index = 0 , buy = 1
    }
};

//RECURSION + MEMOIZATION                                                                 {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveMem(int index, int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }

        //step-3 if ans already present print return it
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1, 0, prices, dp);
            int skipKaro = 0 + solveMem(index+1, 1, prices,dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solveMem(index+1, 1, prices, dp);
            int skipKaro = 0 + solveMem(index+1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        //step-2 store ans in dp vector
        dp[index][buy] = profit;
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        //step-1 create dp vector
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));       //col = 2 (0 or 1)
        return solveMem(0, 1, prices, dp);                //index = 0 , buy = 1
    }
};

//TABULATION METHOD                                                                      {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveTab(vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<vector<int>>dp(n+1, vector<int>(2, 0));

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + dp[index+1][0];
                    int skipKaro = 0 + dp[index+1][1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = +prices[index] + dp[index+1][1];
                    int skipKaro = 0 + dp[index+1][0];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};

//SPACE OPTIMIZATION                                                                    {T.C = O(N), S.C = O(1)}
class Solution { 
public:
    int solveSO(vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<int>curr(2, 0);
        vector<int>next(2,0);

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = +prices[index] + next[1];
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);
    }
};
/*
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/


//BEST TIME TO BUY AND SELL STOCK III
/*Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
//RECURSION
class Solution {
public:
    int solve(int index, int buy, vector<int>&prices, int limit){
        //base case
        int n = prices.size();
        if(index == n || limit == 0){
            return 0;
        }
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(index+1, 0 , prices, limit);
            int skipKaro = 0 + solve(index+1, 1 , prices, limit);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solve(index+1, 1, prices, limit-1);
            int skipKaro = 0 + solve(index+1, 0, prices, limit);
            profit = max(sellKaro , skipKaro);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices, 2);                  //index = 0 , buy = 1, limit = 2
    }
};

//RECURSION + MEMOIZATION                                                                  {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveMem(int index, int buy, vector<int>&prices, int limit ,  vector<vector<vector<int>>>&dp){
        //base case
        int n = prices.size();
        if(index == n || limit == 0){
            return 0;
        }

        //step-3 if ans already present print it
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1, 0 , prices, limit, dp);
            int skipKaro = 0 + solveMem(index+1, 1 , prices, limit, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solveMem(index+1, 1, prices, limit-1, dp);
            int skipKaro = 0 + solveMem(index+1, 0, prices, limit, dp);
            profit = max(sellKaro , skipKaro);
        }

        //step-2 store ans in dp
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //step-1 create dp vector
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2, vector<int>(3, -1)));      //row = n , col = 2  , entry (limit) = 3 (at most 2 = 0 , 1 , 2)
        return solveMem(0, 1, prices, 2 , dp);                  //index = 0 , buy = 1, limit = 2
    }
};

//TABULATION METHOD                                                                         {T.C = O(N), S.C = O(N)}
class Solution {
public:
    int solveTab(vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2, vector<int>(3, 0)));      //row = n , col = 2  , entry (limit) = 3 (at most 2 = 0 , 1 , 2)

        //step-2 analyze base case
        // no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <=2 ; limit++){                             //limit= 0 already handeled
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skipKaro = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = +prices[index] + dp[index+1][1][limit-1];
                        int skipKaro = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro , skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};

//SPACE OPTIMIZATION                                                                  {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int solveSO(vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<vector<int>>curr(2, vector<int>(3, 0));
        vector<vector<int>>next(2, vector<int>(3, 0));

        //step-2 analyze base case
        // no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <=2 ; limit++){                     //limit= 0 already handeled
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = +prices[index] + next[1][limit-1];
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro , skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        return solveSO(prices);
    }
};
/*
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/


//BEST TIME TO BUY AND SELL STOCK IV(same as above)
/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
//RECURSION
class Solution {
public:
    int solve(int index, int buy, vector<int>&prices, int limit){
        //base case
        int n = prices.size();
        if(index == n || limit == 0){
            return 0;
        }
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(index+1, 0 , prices, limit);
            int skipKaro = 0 + solve(index+1, 1 , prices, limit);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solve(index+1, 1, prices, limit-1);
            int skipKaro = 0 + solve(index+1, 0, prices, limit);
            profit = max(sellKaro , skipKaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 1, prices, k);                  //index = 0 , buy = 1, limit = k
        
    }
};

//RECURSION + MEMOIZATION
class Solution {
public:
    int solveMem(int index, int buy, vector<int>&prices, int limit ,  vector<vector<vector<int>>>&dp){
        //base case
        int n = prices.size();
        if(index == n || limit == 0){
            return 0;
        }

        //step-3 if ans already present print it
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1, 0 , prices, limit, dp);
            int skipKaro = 0 + solveMem(index+1, 1 , prices, limit, dp);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = +prices[index] + solveMem(index+1, 1, prices, limit-1, dp);
            int skipKaro = 0 + solveMem(index+1, 0, prices, limit, dp);
            profit = max(sellKaro , skipKaro);
        }

        //step-2 store ans in dp
        dp[index][buy][limit] = profit;
        return dp[index][buy][limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //step-1 create dp vector
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2, vector<int>(k+1, -1)));      //row = n , col = 2  , entry (limit) = k+1 
        return solveMem(0, 1, prices, k , dp);
    }
};

//TABULATION METHOD
class Solution {
public:
    int solveTab(int k, vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2, vector<int>(k+1, 0)));      //row = n , col = 2  , entry (limit) = k+1

        //step-2 analyze base case
        // no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <= k ; limit++){                             //limit= 0 already handeled
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skipKaro = 0 + dp[index+1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = +prices[index] + dp[index+1][1][limit-1];
                        int skipKaro = 0 + dp[index+1][0][limit];
                        profit = max(sellKaro , skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
        int solveSO(int k, vector<int>&prices){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        vector<vector<int>>next(2, vector<int>(k+1, 0));

        //step-2 analyze base case
        // no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int limit = 1 ; limit <=k ; limit++){                     //limit= 0 already handeled
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = 0 + next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    }
                    else{
                        int sellKaro = +prices[index] + next[1][limit-1];
                        int skipKaro = 0 + next[0][limit];
                        profit = max(sellKaro , skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
         return solveSO(k, prices);
    }
};


//ANOTHER APPROACH (OPERATION / TRANSACTION)
//RECURSION
class Solution {
public:
    int solve(int index, int operationNo, int k , vector<int>&prices){
        int n = prices.size();
        if(index == n || operationNo == 2*k){
            return 0;
        }
        
        int profit = 0;
        if(operationNo % 2 == 0){                            //even = buy allow
            int buyKaro = -prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipKaro = 0 + solve(index+1, operationNo, k, prices);
            profit = max(buyKaro, skipKaro);
        }
        else{                                                //odd = sell allow
            int sellKaro = +prices[index] + solve(index+1, operationNo+1, k, prices);
            int skipKaro = 0 + solve(index+1, operationNo , k , prices);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k, prices);                         //index = 0, operationNo = 0
    }
};

//RECURSION + MEMOIZATINO                                                                       {T.C = O(N*K), S.C = O(N*K)}
class Solution {
public:
    int solveMem(int index, int operationNo, int k , vector<int>&prices, vector<vector<int>>&dp){
        int n = prices.size();
        if(index == n || operationNo == 2*k){
            return 0;
        }
        
        //step-3 if ans already present return it
        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }
        int profit = 0;
        if(operationNo % 2 == 0){                            //even = buy allow
            int buyKaro = -prices[index] + solveMem(index+1, operationNo+1, k, prices , dp);
            int skipKaro = 0 + solveMem(index+1, operationNo, k, prices,dp);
            profit = max(buyKaro, skipKaro);
        }
        else{                                                //odd = sell allow
            int sellKaro = +prices[index] + solveMem(index+1, operationNo+1, k, prices, dp);
            int skipKaro = 0 + solveMem(index+1, operationNo , k , prices, dp);
            profit = max(sellKaro, skipKaro);
        }

        //step-2 store ans in dp
        dp[index][operationNo] = profit;
        return dp[index][operationNo];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //step-1 create dp vector
        vector<vector<int>>dp(n, vector<int>(2*k, -1));             //col = operation = 2*k
        return solveMem(0, 0, k, prices, dp);                         //index = 0, operationNo = 0
    }
};

//TABULATION METHOD                                                                         {T.C = O(N*K), S.C = O(N*K)}
class Solution {
public:
    int solveTab(int k, vector<int>& prices) {
        int n = prices.size();
        // Step 1: Create dp vector and initialize to 0
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        // Step 2: Analyze base case
        // No need to initialize base case in this approach

        // Step 3: Loop
        for (int index = n - 1; index >= 0; index--) {
            for (int operationNo = 0; operationNo < 2 * k; operationNo++) {
                int profit = 0;
                if (operationNo % 2 == 0) { // Even = buy allowed
                    int buyKaro = -prices[index] + dp[index + 1][operationNo + 1];
                    int skipKaro = dp[index + 1][operationNo];
                    profit = max(buyKaro, skipKaro);
                } else { // Odd = sell allowed
                    int sellKaro = prices[index] + dp[index + 1][operationNo + 1];
                    int skipKaro = dp[index + 1][operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][operationNo] = profit;
            }
        }

        return dp[0][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveTab(k, prices);
    }
};

//SPACE OPTIMIZATION                                                                     {T.C = O(N*K), S.C = O(K)}
class Solution { 
public:
    int solveSO(int k, vector<int>& prices) {
        int n = prices.size();
        // Step 1: Create dp vector and initialize to 0
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        vector<int>curr(2*k+1, 0);
        vector<int>next(2*k+1, 0);

        // Step 2: Analyze base case
        // No need to initialize base case in this approach

        // Step 3: Loop
        for (int index = n - 1; index >= 0; index--) {
            for (int operationNo = 0; operationNo < 2 * k; operationNo++) {
                int profit = 0;
                if (operationNo % 2 == 0) { // Even = buy allowed
                    int buyKaro = -prices[index] + next[operationNo + 1];
                    int skipKaro = next[operationNo];
                    profit = max(buyKaro, skipKaro);
                } else { // Odd = sell allowed
                    int sellKaro = prices[index] + next[operationNo + 1];
                    int skipKaro = next[operationNo];
                    profit = max(sellKaro, skipKaro);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveSO(k, prices);
    }
};
/*
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/


//BEST TIME TO BUY AND SELL STOCK V (same as II)                                                                    {T.C = O(N) , S.C = O(1)}
/*You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
*/
//SPACE OPTIMIZATION
class Solution {
public:
    int solveSO(vector<int>&prices, int fee){
        int n = prices.size();
        //step-1 create dp vector initialize 0
        vector<int>curr(2, 0);
        vector<int>next(2,0);

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int index = n-1 ; index >= 0 ; index--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = 0 + next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = +prices[index] + next[1]- fee;                //pay transaction fee
                    int skipKaro = 0 + next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveSO(prices, fee);
    }
};
/*
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/


//LONGEST COMMON SUBSEQUECE
//RECURSION
class Solution {
public:
    int solve(string &a, string&b, int i , int j){
        //base case
        if(i == a.length() || j == b.length()){
            return 0;
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a, b , i+1, j+1);
        }
        else{
            ans = max(solve(a, b, i+1, j) , solve(a, b, i, j+1));
        }
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0 , 0);                        //i = 0 , j = 0
    }
};

//RECURSION + MEMOIZATION                                                                {T.C = O(N*M) , S.C = O(N*M)}
class Solution {
public:
    int solveMem(string &a, string&b, int i , int j, vector<vector<int>>&dp){
        //base case
        if(i == a.length() || j == b.length()){
            return 0;
        }

        //step-3 if ans already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveMem(a, b , i+1, j+1, dp);
        }
        else{
            ans = max(solveMem(a, b, i+1, j, dp) , solveMem(a, b, i, j+1, dp));
        }

        //step-2 store ans in dp
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solveMem(text1, text2, 0 , 0, dp);                        //i = 0 , j = 0
    }
};

//TABULATION METHOD                                                                {T.C = O(N*M) , S.C = O(N*M)}
class Solution {
public:
    int solveTab(string &a, string&b){
        //step-1 create dp vector initialize 0
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1 , 0));

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int i = a.length()-1 ; i >= 0 ; i--){
            for(int j = b.length()-1 ; j >= 0 ;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1, text2);
    }
};

//SPACE OPTIMIZATION                                              {T.C = O(N*M) , S.C = O(min(N, M))}
class Solution {
public:
    int solveSO(string &a, string&b){
        //step-1 create dp vector initialize 0
        vector<int>curr(b.length()+1, 0);
        vector<int>next(b.length()+1, 0);

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int i = a.length()-1 ; i >= 0 ; i--){
            for(int j = b.length()-1 ; j >= 0 ;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveSO(text1, text2);
    }
};
/*
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
*/


//LONGEST PALINDROMIC SUBSEQUENCE(same as above)
//SPACE OPTIMIZATION                                                              {T.C = O(N*M) , S.C = O(min(N, M))}
class Solution {
public:
    int solveSO(string &a, string&b){
        //step-1 create dp vector initialize 0
        vector<int>curr(b.length()+1, 0);
        vector<int>next(b.length()+1, 0);

        //step-2 analyze base case
        //no need

        //step-3 loop
        for(int i = a.length()-1 ; i >= 0 ; i--){
            for(int j = b.length()-1 ; j >= 0 ;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        return solveSO(s, revStr);
    }
};
/*
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/


//EDIT DISTANCE
//RECURSION
class Solution {
public:
    int solve(string &a, string &b, int i , int j){
        //base case
        if(i == a.length()){
            return b.length()-j;                             //resedue string as it is
        }
        if(j == b.length()){
            return a.length()-i;
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1);
        }
        else{
            //insert
            int insertAns = 1 + solve(a, b, i, j+1);

            //delete
            int deleteAns = 1 + solve(a, b, i+1, j);

            //replace
            int replaceAns = 1 + solve(a, b, i+1, j+1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);                            //i = 0 , j = 0
    }
};

//RECURSION + MEMOIZATION                                                       {T.C = O(N*M), S.C = O(N*M)}
class Solution {
public:
    int solveMem(string &a, string &b, int i , int j, vector<vector<int>>&dp){
        //base case
        if(i == a.length()){
            return b.length()-j;                             //resedue string as it is
        }
        if(j == b.length()){
            return a.length()-i;
        }

        //step-3 if answer already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = solveMem(a, b, i+1, j+1, dp);
        }
        else{
            //insert
            int insertAns = 1 + solveMem(a, b, i, j+1, dp);

            //delete
            int deleteAns = 1 + solveMem(a, b, i+1, j, dp);

            //replace
            int replaceAns = 1 + solveMem(a, b, i+1, j+1,dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        //step-2 store ans in dp
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        //step-1 create dp vector
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solveMem(word1, word2, 0, 0, dp);                            //i = 0 , j = 0
    }
};

//TABULATION METHOD                                                                 {T.C = O(N*M), S.C = O(N*M)}
class Solution {
public:
    int solveTab(string &a, string &b){
        //step-1 create dp vector initialize 0
        int n = a.length();
        int m = b.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        //step-2 analyze base case
        for(int j = 0 ; j < b.length() ; j++){
            dp[a.length()][j] = b.length() - j;
        }
        for(int i = 0 ; i < a.length() ; i++){
            dp[i][b.length()] = a.length() - i;
        }

        //step-3 loop
        for(int i = a.length()-1 ; i >= 0 ; i--){
            for(int j = b.length()-1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //insert
                    int insertAns = 1 + dp[i][j+1];

                    //delete
                    int deleteAns = 1 + dp[i+1][j];

                    //replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {

        return solveTab(word1, word2);                            //i = 0 , j = 0
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    int solveSO(string &a, string &b){
        //step-1 create dp vector initialize 0
        int n = a.length();
        int m = b.length();

        vector<int>curr(m+1, 0);
        vector<int>next(m+1, 0);

        //step-2 analyze base case
        for(int j = 0 ; j < b.length() ; j++){
            next[j] = b.length() - j;
        }

        //step-3 loop
        for(int i = a.length()-1 ; i >= 0 ; i--){
            for(int j = b.length()-1 ; j >= 0 ; j--){

                //catche here from base case
                curr[b.length()] = a.length() - i;

                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    //insert
                    int insertAns = 1 + curr[j+1];

                    //delete
                    int deleteAns = 1 + next[j];

                    //replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        return solveSO(word1, word2);                            //i = 0 , j = 0
    }
};
/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/


//MAXIMAL AREA(RECTANGLE)                                                       {T.C = O(N*(N+M)), S.C = O(N)}
class Solution {
public:
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<int>histogram(matrix[0].size(), 0);

        for(int i =  0 ; i < matrix.size() ; i++){
            //to create histogram array
            for(int j = 0 ; j < histogram.size() ; j++){
                if(matrix[i][j] == '1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};
/*
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
*/


//WILD CARD MATCHING
//RECURSION
class Solution {
public:
    bool solve(string &s, string &p, int i , int j){
        //base case
        if(i < 0 && j < 0){                                         //both string exhaust
            return true;
        }
        if(i >= 0 && j < 0){                                        //pattern string exhaust
            return false;
        }
        if(i < 0 && j >= 0){                                        //sample string exhaust
            for(int k = 0 ; k < j ; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        //match
        if(s[i] == p[j] || p[j] == '?'){
            return solve(s, p, i-1, j-1);
        }
        else if(p[j] == '*'){
            //2 case
            return (solve(s, p, i-1, j) || solve(s, p, i, j-1));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return solve(s, p, s.length()-1, p.length()-1);               //reverse traversal
    }
};

//RECURSION + MEMOIZATION                                                       {T.C = O(N*M), S.C = O(N*M)}
class Solution {
public:
    bool solveMem(string &s, string &p, int i , int j, vector<vector<int>>&dp){
        //base case
        if(i < 0 && j < 0){                                         //both string exhaust
            return true;
        }
        if(i >= 0 && j < 0){                                        //pattern string exhaust
            return false;
        }
        if(i < 0 && j >= 0){                                        //sample string exhaust
            for(int k = 0 ; k <= j ; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        //step-3 if ans already present return it
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //match                         //step-2 store ans in dp
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            //2 case
            return dp[i][j] = (solveMem(s, p, i-1, j, dp) || solveMem(s, p, i, j-1, dp));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        //step-1 create dp vector
        vector<vector<int>>dp(n, vector<int>(m, -1));

        return solveMem(s, p, s.length()-1, p.length()-1 , dp);               //reverse traversal
    }
};
/*
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/