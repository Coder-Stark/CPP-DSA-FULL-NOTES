//GREEDY ALGORITHMS
#include<bits/stdc++.h>
using namespace std;

//N MEETINGS IN ONE ROOM                                             {T.C = O(N*LOGN), S.C = O(N)}
class Solution
{
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        
        for(int i = 0 ; i < n ; i++){
            pair<int,int>p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count = 1;
        int ansEnd = v[0].second;
        for(int i = 1 ; i < n ; i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};
/*
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/


//SHOPE IN CANDY STORE                                                        {T.C = O(N*LOGN), S.C = O(1)}
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        //sort the array
        sort(candies, candies+n);
        
        //for minimum ans
        int mini = 0;
        int buy = 0;
        int free = n-1;
        
        while(free >= buy){
            mini = mini + candies[buy];
            buy++;
            free = free-k;
        }
        
        //for maximum ans
        int maxi = 0;
        buy = n-1;
        free = 0;
        
        while(free <= buy){
            maxi = maxi + candies[buy];
            buy--;
            free = free+k;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        return ans;
    }
};
/*
Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7

Explanation:
As according to the offer if you buy 
one candy you can take at most two 
more for free. So in the first case, 
you buy the candy which costs 1 and 
takes candies worth 3 and 4 for free, 
also you buy candy worth 2 as well.
So min cost : 1+2 =3.
In the second case, you can buy the 
candy which costs 4 and takes candies 
worth 1 and 2 for free, also you need 
to buy candy worth 3 as well. 
So max cost : 3+4 =7.*/


//CHECK IF IT IS POSSIBLE TO SURVIVE ON ISLAND                                        {T.C = O(1), T.C = O(1)}
class Solution{
public:
    //N – The maximum unit of food you can buy each day.
    //S – Number of days you are required to survive.
    //M – Unit of food required each day to survive.
    int minimumDays(int s, int n, int m ){          
        int sunday = s/7;
        int buyingDays = s-s/7;
        int totalFood = s*m;
        int ans = 0;
        if(totalFood % n == 0){
            ans = totalFood/n;
        }
        else{
            ans = totalFood/n + 1;
        }
        // s == 1 , m == 1
        if(ans <= buyingDays){
            return ans;
        }
        else{
            return -1;
        }
    }
};
/*
Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to 
buy a box on the first day (Monday), 
it’s sufficient to eat from this box up to 
8th day (Monday) inclusive. Now, on the 9th 
day (Tuesday), you buy another box and use 
the chocolates in it to survive the 9th and 
10th day.
*/


//REVERSE WORDS IN A GIVEN STRING                                             {T.C = O(N), S.C = O(N)}
class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string ans = "";                               //store actual ans
        string temp = "";                              //store reversed word
        
        for(int i = s.length()-1 ; i >= 0 ; i--){
            if(s[i] == '.'){
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp = "";
            }
            else{
                temp.push_back(s[i]);
            }
        }
        //handle 1 word which have no (.) {first word}
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        return ans;
    } 
};
/*
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
*/


//CHOCOLATE DISTRIBUTION PROBLEM                                         {T.C = O(N*LOGN), S.C = O(1)}
class Solution{                                                            
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        
        int i = 0;
        int j = m-1;
        
        int mini = INT_MAX;
        
        while(j < a.size()){
            int diff = a[j]-a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
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


//MINIMUM COST OF ROPES                                                   {T.C = O(N*LOGN), S.C = O(N)}
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        //create minheap using priority queue
        priority_queue<long long , vector<long long>,greater<long long>>pq;      //PQ creation o(nlogn)
        for(int i = 0 ; i < n ; i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            pq.push(sum);
            cost = cost + sum;
        }
        return cost;
    }
};
/*
Input:
n = 5
arr[] = {4, 2, 7, 6, 9}
Output: 
62 
Explanation:
First, connect ropes 4 and 2, which makes
the array {6,7,6,9}. Cost of
this operation 4+2 = 6. Next, add ropes 
6 and 6, which results in {12,7,9}. 
Cost of this operation 6+6 = 12.
Then, add 7 and 9, which makes the array {12,16}. 
Cost of this operation 7+9 = 16. And
finally, add these two which gives {28}.
Hence, the total cost is 6 + 12 + 16 + 
28 = 62.
*/


//HUFFMAN ENCODING                                                  {T.C = O(N*LOGN), S.C = O(N)}
class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
class cmp{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution
{
	public:
	    void traverse(Node* root, vector<string>&ans, string temp){
	        //base case
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	        traverse(root->left, ans, temp+'0');
	        traverse(root->right, ans, temp+'1');
	    }
		vector<string> huffmanCodes(string s,vector<int> f,int n)
		{
		    //create mini priority queue
		    priority_queue<Node*, vector<Node*>, cmp>pq;
		    //put all character of string in pq
		    for(int i = 0 ; i < n ; i++){
		        Node* temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size() > 1){
		        Node* left = pq.top();
		        pq.pop();
		        Node* right = pq.top();
		        pq.pop();
		        
		        Node* newNode = new Node(left->data + right->data);
		        newNode->left = left ;
		        newNode->right = right;
		        pq.push(newNode);
		    }
		    //single element is left (root)
		    Node* root = pq.top();
		    vector<string>ans;
		    string temp = "";
		    traverse(root, ans, temp);
		    
		    return ans;
		}
};
/*
S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
*/


//FRACTIONAL KNAPSACK                                                     {T.C = O(N*LOGN), S.C = O(N)}
struct Item{
    int value;
    int weight;
};
//-----------------------------------------------------------------------------------------------
class Solution
{
    public:
    static bool cmp(pair<double, Item>a, pair<double, Item>b){
        return a.first > b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //create vector {v/w, Item<v , w>}
        vector<pair<double, Item>>v;
        for(int i = 0 ; i < n ; i++){
            double perUnitValue = (1.0* arr[i].value / arr[i].weight);
            pair<double, Item>p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }
        
        //sort vector
        sort(v.begin(), v.end(), cmp);
        
        double totalValue = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i].second.weight > W){                        //v[i].second == accesses the second element (the Item object) of the pair.
                //fractional part
                totalValue = totalValue + W * v[i].first;     // w * v/w
                W = 0;
            }
            else{
                //full part
                totalValue = totalValue + v[i].second.value;
                W = W - v[i].second.weight;
            }
        }
        return totalValue;
    }
};
/*
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
*/