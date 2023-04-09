#include<iostream>
using namespace std;

//MACROS
#define pi 3.14

int main(){
    
    int r = 5;
    // double pi = 3.14;                            //takes extra memory of 8 bytes
    double area = pi * r * r ;
    cout<<area<<endl;
}


//GLOBAL VARIABLES              ---> BAD PRACTISE
int x = 8;
void a(int &i){
    cout<<"in a "<<x<<endl;
}
void b(int &i){
    cout<<"in b "<<x<<endl;
}
int main(){
    cout<<"in main "<<x<<endl;
    int i = 5;
    a(i);
    b(i);
}

//INLINE FUNCTIONS
inline int getMax(int &a , int&b){
    return (a>b) ? a : b;
}
int main(){
    int a = 1 ;
    int b = 2;

    int ans = 0;

    ans = getMax(a , b);
    cout<<ans<<endl;
    
    a = a + 3;
    b = b + 1;
    ans = getMax(a , b);
    cout<<ans<<endl;
}


//DEFAULT ARGUMENTS
void printArray(int arr[] , int n , int start = 0){
    for(int i = start ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[5] = {1 , 2  , 3 , 4  , 5 };

    printArray(arr , 5 , 2 );
    cout<<endl;
    printArray(arr , 5 );                              //start = 0 (default arg)
}


/*OUTPUT
78.5

in main 8
in a 8
in b 8

2
4

3 4 5 
1 2 3 4 5
*/