//MATHS FOR DSA

#include<iostream>
using namespace std;


//CHECK PRIME
/*
bool isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i = 2 ; i < n ; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;

    cout<<"The number is prime or not : "<<isPrime(n);

    return 0;
}
*/
/*OUTPUT
Enter the number : 
11
The number is prime or not : 1
*/


//COUNT PRIMES
/*
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool>prime(n+1 , true);
        prime[0] = prime[1] = false;

        for(int i = 2 ; i < n ; i++){
            if(prime[i]){
                count++;
                for(int j = 2 * i ; j < n ; j = j+i){
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};
*/


//GCD
/*
int gcd(int a , int b){
    if(a == 0)
    return b;

    if(b == 0);
    return a;

    while(a != b){
        if(a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}
int main(){
    int a , b;
    cout<<"Enter the 1st no. : "<<endl;
    cin>>a;

    cout<<"Enter the 2nd no. : "<<endl;
    cin>>b;

    int ans = gcd(a , b);
    cout<<"gcd of  2 no. is : "<<ans<<endl;

    return 0;
}
*/


//MODULAR EXPONENTIATION
/*
int modularExponetiation(int x , int n , int m){
    int res = 1;

    while(n > 0){
        if(n & 1){
            res = (1LL * (res) * (x)%m)%m;
        }
        x = ((x)%m * (x)%m)%m;
        n = n>>1;
    }
    return res;
}
*/

//pigeon hole principle
//catalon number
//inclusion - exclusion principle