//SWITCH

#include<iostream>
using namespace std;

//calculator using switch
int main(){
    int a , b;
    char op;
    cout<<"Enter the value of a : "<<endl;
    cin>>a;
    cout<<"Enter the value of b : "<<endl;
    cin>>b;
    cout<<"Enter the operation : "<<endl;
    cin>>op;

    switch(op){
        case '+':cout<<(a+b)<<endl;
                break;
        case '-':cout<<(a-b)<<endl;
                break;
        case '*':cout<<(a*b)<<endl;
                break;
        case '/':cout<<(a/b)<<endl;
                break;
        case '%':cout<<(a%b)<<endl;
                break;
        default :cout<<"Enter valid operation " <<endl;
                break;
    }
}
/*OUTPUT
Enter the value of a : 
8
Enter the value of b : 
34
Enter the operation : 
+
42
*/

//NUMBER OF NOTES REQUIRED OF 100 , 50 , 20 , 1
int main(){
    int n1 , n20 , n50 , n100;
    n1 = n20 = n50 = n100 = 0;
    int amount;
    cout<<"Enter the amount : "<<endl;
    cin>>amount;
    switch(amount >= 100){
        case 1:
            n100 = amount / 100;
            amount -= n100 * 100;
        break;
    }
    switch(amount >= 50){
        case 1:
            n50 = amount /50;
            amount -= n50 * 50;
        break;
    }
    switch(amount >= 20){
        case 1:
            n20 = amount / 20;
            amount -= n20 * 20;
    }
    switch(amount >= 1){
        case 1:
            n1 = amount / 1;
            amount -= n1 * 1;
    }

    cout<<"100 notes : "<<n100<<endl;
    cout<<"50 notes : "<<n50<<endl;
    cout<<"20 notes : "<<n20<<endl;
    cout<<"1 notes : "<<n1<<endl;
}
/*OUTPUT
Enter the amount : 
1330
100 notes : 13
50 notes : 0
20 notes : 1
1 notes : 10
*/