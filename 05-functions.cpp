//FUNCTIONS
#include<iostream>
using namespace std;


//POWER (A^B)
/*
int power(int a , int b){
    int ans = 1;
    for(int i = 1 ; i <= b  ; i++){
        ans = ans * a;
    }
    return ans;
}
int main(){
    int a , b;
    cout<<"Enter the value of a and b : "<<endl;
    cin>>a >>b;

    int ans = power(a , b);
    cout<<"Answer is : "<<ans<<endl;

    return 0;
}
*/
/*OUTPUT
Enter the value of a and b : 
3
4
Answer is : 81
*/


//NUMBER IS EVEN OR ODD
/*
bool isEven(int a){
    if( a & 1){
        return 0;
    }
    return 1;
}
int main(){
    int num;
    cout<<"Enter the number : "<<endl;
    cin>>num;

    // int ans = isEven(num);
    // cout<<"answer is : " <<ans<<endl;

    if(isEven(num)){
        cout<<"The number is Even "<<endl;
    }
    else{
        cout<<"The number is Odd "<<endl;
    }

    return 0;
}
*/
/*OUTPUT
// Enter the number : 
// 34
// answer is : 1

Enter the number : 
45
The number is Odd 
*/


//CALCULATE n-C-r
/*
int factorial(int n){
    int fact = 1;
    for(int i = 1 ; i <= n ; i++ ){
        fact = fact * i;
    }
    return fact;
}
int nCr(int n , int r){
    int nume = factorial(n);
    int denom = factorial(r) * factorial(n-r);
    
    int ans = nume / denom;

    return ans;
}
int main(){
    int n , r ;
    cout<<"Enter the value of n and r : " <<endl;
    cin>>n >> r;

    int res = nCr(n , r);
    cout<<"Result is : "<<res<<endl;
}
*/
/*OUTPUT
Enter the value of n and r : 
8
2
Result is : 28
*/


//PRINT COUNTING
/*
int PrintCounting(int n){
    for(int i = 1 ; i <= n ; i++){
        cout<<i<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    cout<<"The counting is : "<<endl;
    PrintCounting(n);

    return 0;
}
*/
/*OUTPUT
Enter the value of n : 
6
The counting is : 
1 2 3 4 5 6
*/   


//PRIME OR NOT
/*
bool isPrime(int n){
    for(int i = 2 ; i < n ; i++ ){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    // int ans = isPrime(n);
    // cout<<ans<<endl;

    if(isPrime(n)){
        cout<<"Is a Prime number"<<endl;
    }
    else{
        cout<<"Is not a Prime number"<<endl;
    }
}
*/
/*OUTPUT
// Enter the value of n : 
// 7
// 1

Enter the value of n : 
8
Is not a Prime number
*/


