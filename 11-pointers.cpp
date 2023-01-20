//POINTERS -->> store address

#include<iostream>
using namespace std;

/*
void print(int *p){
    cout<<*p<<endl;
}
void update(int *p){
    // p = p + 1;                                //no change in  main function
    // cout<<"inside "<<p<<endl;
    *p = *p + 1;                               //or((*p)++) for value update
}
int getSum(int *arr , int n){             //int *arr == int arr[]
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum = sum + arr[i];
    }
    return sum;
}
*/
void update( int **p2){
    // p2 = p2 + 1;                                //no change
    // *p2 = *p2 + 1;
    **p2 = **p2 + 1;
}

int main(){
    /*
    int num = 5;
    cout<<"Value : "<<num<<endl;

    //address of operator -> &
    cout<<"Address : "<<&num<<endl;

    //pointer
    int *p = &num;
    cout<<"Address : "<<p<<endl;
    cout<<"Value : "<<*p<<endl;

    double d = 4.67;
    double *p2 = &d;
    cout<<"Address : "<<p2<<endl;
    cout<<"Value : "<<*p2<<endl;

    cout<<"Size of integer : "<<sizeof(num)<<endl;
    cout<<"Size of pointer : "<<sizeof(p)<<endl;
    cout<<"Size of pointer : "<<sizeof(p2)<<endl;

    int i = 6;
    int *p3 = 0;
    p3 = &i;

    cout<<"Address : "<<p3<<endl;
    cout<<"Value : "<<*p3<<endl;


    int a = num;
    cout<<"Before : "<<num<<endl;
    a++;
    cout<<"After : "<<num<<endl;

    int num1 = 8;
    int *p4 = &num;
    cout<<"Before : "<<p4<<endl;
    (p4)++;
    cout<<"After : "<<p4<<endl;

    cout<<"Before : "<<*p4<<endl;
    (*p4)++;
    cout<<"After : "<<*p4<<endl;

    //copying a pointer
    int *q = p;
    cout<<p<<"-"<<q<<endl;
    cout<<*p<<"-"<<*q<<endl;
    */

    //POINTERS WITH ARRAY
    /*
    int arr[10] = {5  , 2 , 6 , 7 };
    cout<<"Address : "<<arr<<endl;
    cout<<"Address : "<<&arr[0]<<endl;
    cout<<"Value : "<<arr[0]<<endl;
    cout<<"Value : "<<*arr<<endl;
    cout<<"Value : "<<*arr+1<<endl;
    cout<<"Value : "<<*(arr)+1<<endl;
    cout<<"Value : "<<*(arr+1)<<endl;
    cout<<"Value : "<<arr[2]<<endl;
    cout<<"Value : "<<*(arr + 2)<<endl;

    int i = 3;
    cout<<"Value : "<<arr[i]<<endl;
    cout<<"Value : "<<i[arr]<<endl;

    int temp[10] = {9 ,8 , 4};
    cout<<"Size of temp(Address) : "<<sizeof(temp)<<endl;
    cout<<"Size of temp(Address) : "<<sizeof(&temp)<<endl;
    cout<<"Size of temp(Value) : "<<sizeof(*temp)<<endl;

    int *ptr = &temp[0];
    cout<<"Size of temp(Address) : "<<sizeof(ptr)<<endl;
    cout<<"Size of temp(Address) : "<<sizeof(&ptr)<<endl;
    cout<<"Size of temp(Value) : "<<sizeof(*ptr)<<endl;
    */

    /*   //& -> (arr vs pointer)
    int a[20] = {1 , 2, 3 , 5 , 7};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<&a<<endl;

    int *p = &a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    */

    /*   // symbolic table name ( arr vs pointer)
    int arr[10];
    // arr = arr + 1;    ===>> error

    int *ptr = &arr[0];
    cout<<ptr<<endl;
    ptr = ptr + 1;
    cout<<ptr<<endl;
    */

    
    //character array vs integer array
    /*
    int arr[5] = { 1 , 2 , 3 , 4 , 5};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl;

    int *p = &arr[0];
    cout<<p<<endl;

    char *c = &ch[0];
    cout<<c<<endl;

    char temp = 'x';
    char *t = &temp;                     //wrong practise
    cout<<t<<endl;                       //random print after x--- till \0
    */


    //FUNCTIONS
    /*
    int value = 6;
    int *p = &value;


    cout<<"Before update : "<<p<<endl;
    cout<<"Before update : "<<*p<<endl;

    update(p);
    cout<<"After update : "<<p<<endl;
    cout<<"After update : "<<*p<<endl;
    */

    //functions and arrays with pointer
    /*
    int arr[5] = {1 , 2 , 3 , 4, 5};
    cout<<"Sum of array : "<<getSum(arr , 5)<<endl;
    cout<<"Sum of array : "<<getSum(arr+3 , 2)<<endl;
    */

    //double pointers
    /*
    int i = 6 ;
    int *p = &i;
    int **p2 = &p;

    cout<<"Address of i : " <<p<<endl;
    cout<<"Address of p: " <<&p<<endl;
    cout<<"Address of p2: " <<&p2<<endl;

    cout<<"Address : "<<*p2<<endl;
    cout<<"Value : "<<**p2<<endl;
    cout<<"Value : "<<*p<<endl;
    cout<<"Value : "<<i<<endl;

    cout<<"Address : "<<&i<<endl;
    cout<<"Address : "<<p<<endl;
    cout<<"Address : "<<*p2<<endl;

    cout<<"Address : "<<&p<<endl;
    cout<<"Address : "<<p2<<endl;
    */

    //functions and arrays with double pointer
    
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<<"Before update : "<<i<<endl;
    cout<<"Before update : "<<p<<endl;
    cout<<"Before update : "<<p2<<endl;
    update(p2);
    cout<<"After update : "<<i<<endl;
    cout<<"After update : "<<p<<endl;
    cout<<"After update : "<<p2<<endl;
    

    return 0;


}

/*OUTPUT
Value : 5
Address : 0x61fef4
Address : 0x61fef4
Value : 5
Address : 0x61fee8
Value : 4.67
Size of integer : 4
Size of pointer : 4
Size of pointer : 4
Address : 0x61fee4
Value : 6
Before : 5
After : 5
Before : 0x61fef4
After : 0x61fef8
Before : -2
After : -1
0x61fef4-0x61fef4
5-5

//POINTERS WITH ARRAY
Address : 0x61fed4
Address : 0x61fed4
Value : 5
Value : 5
Value : 6
Value : 6
Value : 2
Value : 6
Value : 6
Value : 7
Value : 7
Size of temp(Address) : 40
Size of temp(Address) : 4
Size of temp(Value) : 4
Size of temp(Address) : 4
Size of temp(Address) : 4
Size of temp(Value) : 4


0x61fec0
0x61fec0
0x61fec0
0x61fec0
1
0x61febc

0x61fee4
0x61fee8

//character array vs integer array
0x61fef0
abcde
0x61fef0
abcde
xabcde

//functions
Before update : 0x61ff08
Before update : 6
//inside 0x61ff08
After update : 0x61ff08
After update : 7

Sum of array : 15
Sum of array : 9

//double pointers
Address of i : 0x61ff0c
Address of p: 0x61ff08
Address of p2: 0x61ff04

Address : 0x61ff0c
Value : 6
Value : 6
Value : 6

Address : 0x61ff0c
Address : 0x61ff0c
Address : 0x61ff0c

Address : 0x61ff08
Address : 0x61ff08

//update 1st case -> no change
Before update : 5
Before update : 0x61ff08
Before update : 0x61ff04
After update : 5
After update : 0x61ff08
After update : 0x61ff04

//update 2nd case -> &p changes
Before update : 5
Before update : 0x61ff08
Before update : 0x61ff04
After update : 5
After update : 0x61ff0c
After update : 0x61ff04

//update 3rd case -> value changes
Before update : 5
Before update : 0x61ff08
Before update : 0x61ff04
After update : 6
After update : 0x61ff08
After update : 0x61ff04
*/
