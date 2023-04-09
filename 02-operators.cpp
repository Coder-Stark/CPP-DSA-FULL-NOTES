//BITWISE OPERATOR , FOR LOOP , 

#include<iostream>
using namespace std;


int main(){
    int a = 4;
    int b = 6;

    cout<<"a : "<<a<<endl;
    cout<<"b : " <<b<<endl;

    cout<<"(a&b) : "<<(a&b)<<endl;
    cout<<"(a|b) : "<<(a|b)<<endl;
    cout<<"(~a) : "<<(~a)<<endl;
    cout<<"(~b) : "<<(~b)<<endl;
    cout<<"(a^b) : "<<(a^b)<<endl;

    // left-sift 
    cout<<"(19<<1) : "<<(19<<1)<<endl;
    cout<<"(19<<2) : "<<(19<<2)<<endl;

    // right-sift 
    cout<<"(17>>1) : "<<(17>>1)<<endl;
    cout<<"(17>>2) : "<<(17>>2)<<endl;

    int i = 8;
    cout<<"(i++) : "<<(i++)<<endl;
    cout<<"(++i) : "<<(++i)<<endl;
    cout<<"(i--) : "<<(i--)<<endl;
    cout<<"(--i) : "<<(--i)<<endl;
    
}
/*OUTPUT
a : 4
b : 6

(a&b) : 4
(a|b) : 6
(~a) : -5
(~b) : -7
(a^b) : 2

(19<<1) : 38
(19<<2) : 76

(17>>1) : 8
(17>>2) : 4

(i++) : 8
(++i) : 10
(i--) : 10
(--i) : 8
*/


//FOR LOOP
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    cout<<"Printing the count from 1 to n : "<<endl;

    for(int i = 1 ; i <= n ; i++){
        cout<<i<<" ";
    }
}
/*OUTPUT
Enter the value of n : 
5
Printing the count from 1 to n : 
1 2 3 4 5
*/


int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int sum = 0;
    for(int i = 0 ; i <= n ; i++ ){
        sum = sum + i;
    }
    cout<<"sum of numbers from 1 to n : "<<sum<<endl;
}
/*OUTPUT
Enter the value of n : 
100
sum of numbers from 1 to n : 5050
*/


int main(){
    int n ; 
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int a = 0 ;
    int b = 1;
    cout<<"Fibonaccin Series of first n numbers : "<<endl;
    cout<<a<<" "<<b<<" ";
    for(int i = 1 ; i <= n ; i++){
        int nextNumber = a + b;
        cout<<nextNumber<<" ";
        a = b;
        b = nextNumber;
    }
}
/*OUTPUT
Enter the value of n : 
10
Fibonaccin Series of first n numbers : 
0 1 1 2 3 5 8 13 21 34 55 89
*/


int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    bool isPrime = 1;
    for(int i = 2 ; i < n ; i++){
        if( n % i == 0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime == 0){
        cout<<"is not a Prime Number"<<endl;
    }
    else{
        cout<<"is a Prime Number"<<endl;
    }
}
/*OUTPUT
Enter the value of n : 
11
is a Prime Number*/

