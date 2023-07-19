//HASHING
//max hash[n] = {0}   -- > n = 1e6 (inside main function)
//max hash[n];        -- > n = 1e7  (globally)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    
    //precompute
    int hash[13] = {0};                    //initize hash array with 0
    for(int i = 0 ; i < n ;i++){
        hash[arr[i]] += 1;
    }
    
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        
        //fetch
        cout<<hash[num]<<" ";
    }
    return 0;
}
/*
input
5
1 3 2 1 3
5
1 4 2 3 12 
output
2 0 1 2 0                            //count of elements
*/
