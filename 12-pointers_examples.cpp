//POINTERS EXAMPLES

#include<iostream>
using namespace std;

void update(int *ptr7){
    *ptr7 = (*ptr7) * 2;
}
void increament(int **p9){
    ++(**p9);
}
int main(){

    int f1 = 8 ; 
    int s1 = 18;
    int *p = &s1;
    *p = 9;
    cout<<f1<<" "<<s1<<endl;

    int f2 = 5;
    int *p2 = &f2;
    int *q2 = p2;
    (*q2)++;
    cout<<f2<<endl;

    int f3 = 8;
    int *p3 = &f3;
    cout<<(*p3)++<<" ";
    cout<<f3<<endl;

    int *p4 = 0;
    int f4 = 110;
    *p4 = f4;                                  //error -- segmentation fault(wrong initialization)
    cout<<*p4<<endl;

    int f5 = 8;
    int s5 = 11;
    int *t5 = &s5;
    f5 = *t5;               
    *t5 = *t5 + 2;
    cout<<f5<<" "<<s5<<endl;

    float f6 = 12.5;
    float s6 = 21.5;
    float *p6 = &f6;
    (*p6)++;
    *p6 = s6;
    cout<<*p6<<" "<< f6 <<" "<< s6 <<endl;

    int arr[5];
    int *ptr0;
    cout<<sizeof(arr)<<" "<<sizeof(ptr0)<<endl;

    int arr2[] = {11 , 21 , 13 , 14};
    cout<<*(arr2)<<" "<<*(arr2 + 1)<<endl;

    int arr3[6] = {11 , 12 , 31};
    cout<<arr<<" "<<&arr<<endl;

    int arr4[6] = {11 ,21 , 13};
    cout<<(arr+1)<<endl;

    int arr5[6] = {11 , 21 , 31};
    int *ptr = arr5;
    cout<<ptr[2]<<endl;                         //same as *(p+2)

    int arr6[] = {11 , 12 , 13 , 14 , 15};
    cout<<*(arr6)<<" "<<*(arr6 + 3)<<endl;

    // int arr7[] = {11 , 21 , 31 , 41};
    // int *ptr2 = arr7++;                         //error -- symbol table name in array cant change
    // cout<<*ptr<<endl;

    char ch = 'a';
    char *ptr3 = &ch;
    ch++;
    cout<<*ptr3<<endl;

    char arr8[] = "abcde";
    char *ptr4 = &arr8[0];
    cout<<ptr4<<endl;

    char arr9[] = "abcde";
    char *ptr5 = &arr9[0];
    ptr5++;
    cout<< ptr5 <<endl;

    char str[] = "shivam";
    char *ptr6 = str;
    cout<<str[0]<<" "<<ptr6[0]<<endl;

    int i = 10;
    update(&i);
    cout<<i<<endl;

    int f7 = 110;
    int *p7 = &f7;
    int **q7 = &p7;
    int s7 = (**q7)++ + 9;
    cout<<f7<<" "<<s7<<endl;

    int f8 = 100;
    int *p8 = &f8;
    int **q8 = &p8;
    int s8 = ++(**q8);
    int *r8 = *q8;
    ++(*r8);
    cout<< f8 << " "<< s8<<endl; 

    int f9 = 110;
    int *p9 = &f9;
    increament(&p9);
    cout<< f9 <<endl;


    return 0;
}

/*OUTPUT
8 9
6
8 9
//error -- segmentation fault(wrong initialization)
11 13
21.5 21.5 21.5

20 4
11 21
0x61fe9c 0x61fe9c
0x61fea0
31
11 14
//error -- symbol table name in array cant change
b
abcde
bcde
s s
20
111 119
102 101
111
*/