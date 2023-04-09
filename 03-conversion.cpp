//CONVERSION DECIMAL TO BINARY
// same flow =>    ans = (ans * 10) + digit

// digit = n&10
// reverse flow => ans = (digit * 10^i) + ans
// int bit = n & 1;
// reverse flow => ans = (bit * 10^i) + ans
// n= n>>1

#include<iostream>
#include<math.h>
using namespace std;


int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    int ans = 0 ; 
    int i = 0;
    while(n != 0){
        int bit = n & 1;
        ans = (bit * pow(10 , i)) + ans;
        n = n >> 1;
        i++;
    }
    cout<<"Answer is : "<<ans <<endl;
}
/*OUTPUT
Enter the value of n : 
5
Answer is : 101
*/



//DECIMAL TO BINARY
// INCOMPLETE
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    
    int ans = 0 , i = 0;
    while(n != 0){
        int digit = n % 2;
        n = n/2;
    }
}

// CHAT GPT
#include <iostream>
#include <cmath>
#include <string>

std::string decimalToBinary(int n)
{
    std::string binaryNumber = "";
    int remainder;

    while (n > 0)
    {
        remainder = n % 2;
        n /= 2;
        binaryNumber = std::to_string(remainder) + binaryNumber;
    }
    return binaryNumber;
}

int main()
{
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;
    std::cout << "Binary equivalent of the decimal number " << decimalNumber << " is " << decimalToBinary(decimalNumber) << std::endl;
    return 0;
}




//BINARY TO DECIMAL
int main(){
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 0 , ans = 0;
    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2 , i);
        }
        n = n / 10;
        i++;
    }
    cout<<"Answer is : "<<ans<<endl;
}
/*OUTPUT
Enter the value of n : 
1010
Answer is : 10
*/