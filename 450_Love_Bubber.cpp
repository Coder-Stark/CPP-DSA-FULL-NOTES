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