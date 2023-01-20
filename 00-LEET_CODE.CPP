#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;


//SUBTRACT THE PRODUCT AND SUM OF THE DIGIT
/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int product = 1;
    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        product = product * digit;
        sum = sum + digit;

        n = n/10;
    }
    int subtract = product - sum;
    cout<<"Subtract the product ands sum of digit : "<<subtract<<endl;
}
*/
/*OUTPUT
Enter the value of n :
25
Subtract the product ands sum of digit : 3
*/


//NUMBER OF 1 BITS
/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int count = 0;
    while(n != 0){
        if(n & 1){
            count++;
        }
        n = n>>1;
    }
    cout<<"number of 1 bits in n : " <<count;
}
*/
/*OUTPUT WRONG
(expected)
Enter the value of n :
11111000000
number of 1 bits in n :
5
*/


// REVERSE INTEGER
// for simple case (in range)
/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int ans = 0 , digit = 0;
    while(n != 0){
        digit = n % 10;
        ans = (ans * 10) + digit;
        n = n/10;
    }
    cout<<"Reverse of integer : "<<ans<<endl;
}
*/
/*OUTPUT
Enter the value of n :
5678
Reverse of integer : 8765
*/

// for exception case ( out range)
/*
int main(){
    int n;
    cout<<"Enter the valueo of n : "<<endl;
    cin>>n;
    int ans = 0 , digit = 0;
    while(n != 0){
        digit = n % 10;
        if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
            return 0;
        }
        ans = (ans * 10) + digit;
        n = n/10;
    }
    cout<<"Reverse of integer : "<<ans<<endl;
}
*/
/*OUTPUT
Enter the valueo of n :
123456789
Reverse of integer : 987654321
*/

// COMPLIMENT OF BASE 10 INTEGER
/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int ans = 0 , mask = 0;
    //edge case
    if(n == 0){
        return 1;
    }
    while(n != 0){
        mask = (mask << 1) | 1;
        n = n >> 1;
    }
    ans = (~n) & mask;
    cout<<"Compliment of base 10 integer : "<<ans<<endl;
}
*/
/*OUTPUT (EXPECTED)
Enter the value of n :
5
Compliment of base 10 integer : 2
*/

// POWER OF 2
/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int ans = 0 , i;
    for( i = 0 ; i <= 30 ; i++ ){
        ans = pow(2 , i);
        if(ans == n){
            cout<<"True"<<endl;
        }
    }
    cout<<"False"<<endl;
}
*/
/*OUTPUT
Enter the value of n :
8
True
*/


//REVERSE ARRAY BY VECTOR
/*
#include<vector>

vector<int>reverse(vector<int>v){
    int s = 0 ;
    int e = v.size() - 1;
    while(s <= e){
        swap(v[s] , v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int>v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v;

    v.push_back(11);
    v.push_back(1);
    v.push_back(21);
    v.push_back(3);
    v.push_back(41);

    cout<<"array before reverse : "<<endl;
    print(v);

    vector<int>ans = reverse(v);
    cout<<"array after reverse : "<<endl;
    print(ans);
}
*/
/*OUTPUT
array before reverse : 
11 1 21 3 41 
array after reverse :
41 3 21 1 11
*/



//REVERSE ARRAY  AFTER POSITION M BY VECTOR
/*
#include<vector>

vector<int> reverse(vector<int>v , int m){
    int s = m+1 ;
    int e = v.size() - 1;
    while(s <= e){
        swap(v[s] , v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int>v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v;
    int m;
    cout<<"Enter the position from which reverse array : "<<endl;
    cin>>m;

    v.push_back(11);
    v.push_back(1);
    v.push_back(21);
    v.push_back(3);
    v.push_back(41);

    cout<<"array before reverse : "<<endl;
    print(v);

    vector<int>ans = reverse(v , m);
    cout<<"array after reverse : "<<endl;
    print(ans);
}
*/

/*OUTPUT
Enter the position from which reverse array : 
2
array before reverse : 
11 1 21 3 41
array after reverse :
11 1 21 41 3
*/


//MERGE TO SORTED ARRAY IN SINGLE ARRAY
/*
void merge(int a[] ,int n , int b[] , int m , int c[]){
    int i = 0 ; 
    int j = 0 ;
    int k = 0 ;
    while( i < n && j < m){
        if(a[i] < b[j]){
            c[k] = a[i];
            i++;
            k++;
        }
        else{
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while(i < n){
        c[k] = a[i];
        i++;
        k++;
    }
    while(j < m){
        c[k] = b[j];
        j++;
        k++;
    }
}
void printArray(int ans[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int a[5] = { 1 , 3, 5 , 7 , 9};
    int b[3] = {2 , 4 , 6};
    int c[8] = {0};


    cout<<"Array after merge is : "<<endl; 
    merge(a , 5 , b , 3 , c);
    printArray(c , 8);

    return 0;
}
*/
/*OUTPUT
Array after merge is : 
1 2 3 4 5 6 7 9
*/


//MOVE ZEROES
/*
void moveZeroes(int a[] , int n){

    //move all nonzero to left

    int nonZero = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] != 0){
            swap(a[i] , a[nonZero]);
            nonZero++;
        }
    }
}
void printArray(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }


    cout<<"Zeroes at the right side : "<<endl;
    moveZeroes(a , n);
    printArray(a , n);

    return 0;
    
}
*/
/*OUTPUT
Enter the size of an array : 
7
Enter the element of an array : 
1 0 3 0 4 0 6   
Zeroes at the right side : 
1 3 4 6 0 0 0
*/


//ROTATE ARRAY
/*
void rotateArray(int a[] , int k){
    int temp[k];
    for(int i = 0 ; i < k; i++){
        temp[(i + k) % k]  = a[i];
    }
    a = temp;
}
void printArray(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    int k;
    cout<<"Enter the key from which array rotate : "<<endl;
    cin>>k;

    cout<<"Rotated array : "<<endl;
    rotateArray(a , k);
    printArray(a , n);

    return 0;
    
}
*/
/*OUTPUT(expected)
Enter the size of an array : 
7
Enter the element of an array : 
1 2 3 4 5 6  7
Enter the key from which array rotate : 
3
Rotated array : 
4 5 6 7 1 2 3 
*/


//CHECK ARRAY IS SORTED AND ROTATED
/*
bool checkSortedRotated(int a[] , int n){
    int count = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(a[i-1] > a[i]){
            count++;
        }
    }
    if(a[n-1] > a[0]){
        count++;
    }
    return count <= 1;
}
int main(){
    int n;
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Check array is sorted and rotated : "<<endl;
    cout<<checkSortedRotated(a , n);

    return 0;
    
}
*/
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
3 4 5 1 2
Check array is sorted and rotated : 
1
*/


//SUM OF TWO ARRAYS
/*
#include<vector>

vector<int>reverse(vector<int>v){
    int s = 0 ; 
    int e = v.size() - 1;
    while(s < e){
        swap(v[s++],v[e--]);
    }
    return v;
}
vector<int>findArraySum(vector<int>a , int n , vector<int>b , int m){
    int i = n-1;
    int j = m-1;
    vector<int>ans;
    int carry = 0;
    while(i >= 0 && j >= 0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    //1st case
    while(i>=0){
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    //2nd case
    while(j>=0){
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    //3rd case
    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return reverse (ans);
}
void print(vector<int>v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>a;
    
    int n = a.size();
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    
    print(a);

    vector<int>b;

    int m = b.size();
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
    b.push_back(9);
    b.push_back(0);

    print(b);

    cout<<"sum of two arrays : "<<endl;
    vector<int>ans = findArraySum(a , n , b  , m);
    print(ans);

}
*/
/*OUTPUT(expected)
1 2 3 4 5 
6 7 8 9 0
sum of two arrays :
8 0 2 3 5 
*/