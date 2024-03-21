//BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;


//01. SINGLE NUMBER                                                                            {T.C = O(N), S.C = O(1)}
/*
brute force we use use set or map and if count == 1 return element 
optimal = use bit manipulation take xor of each element with each element if it same then it would be cancel out(0) otherwise return xorans
Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {             //xor = different element != 0 else 0 
        int xorAns = 0;
        for(int i = 0 ; i < nums.size(); i++){
            xorAns = xorAns^nums[i];
        }
        return xorAns;
    }
};
/*
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/


//02. SINGLE NUMBER III                                         {T.C = O(N), S.C = O(1)}
/*
first find xor of all element then we get 2 xor's element now we have to seperte it for this we have
to first calculate rightmostset bit then divide two grps of xor seperately (set bit or not).
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0); // Initialize the answer vector with two elements

        int xorAns = 0;
        
        // Step 1: Get the XOR of all elements
        for (int num : nums) {
            xorAns ^= num;
        }
        
        // Step 2: Find the rightmost set bit
        int rightmostSetBit = 1;
        while ((rightmostSetBit & xorAns) == 0) {
            rightmostSetBit <<= 1;
        }
        
        // Step 3 & 4: Divide into two groups and XOR separately
        for (int num : nums) {
            if ((num & rightmostSetBit) == 0) {
                ans[0] ^= num; // XOR for the group where the bit is not set
            } else {
                ans[1] ^= num; // XOR for the group where the bit is set
            }
        }
        
        return ans;
    }
};
/*
Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]
*/