//INTRO TO C++
#include <bits/stdc++.h>
using namespace std;

//FIND AREA OF RECTANGLE
int main() {
    int L;
    cin>>L;
    int B;
    cin>>B;

    cout<<L*B;

    return 0;
}
/*
Sample Input 1:
4 20
Sample Output 1:
80
*/


//PRINT NAME AND AGE
int main() {
    string name;
    cin>>name;
    int age;
    cin>>age;
    cout <<"The name of the person is "<<name<<" and the age is " <<age<<".";

    return 0;
}
/*
Sample Input 1:
Ali
30
Sample Output 1:
The name of the person is Ali and the age is 30.
*/


//SWAP TWO NUMBERS
pair < int, int > swap(pair < int, int > swapValues) {
    int temp = swapValues.first;
    swapValues.first = swapValues.second;
    swapValues.second = temp;

    return swapValues;
}
/*
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
*/


//CALCULATE SIMPLE INTEREST
int main() {
    int p; 
    cin>>p;
    float r;
    cin>>r;
    int t;
    cin>>t;

    cout<<int((p*r*t)/100);

    return 0;
}
/*
Sample Input 1:
2000
2.2
4
Sample Output 1:
176
*/


//FIND CHARACTER CASE
int main() {
    char ch;
    cin>>ch;

    if(ch >= 'A' && ch <= 'Z'){
        cout<<"1";
    }
    else if(ch >= 'a' && ch <= 'z'){
        cout<<"0";
    }
    else{
        cout<< "-1";
    }
}
/*
Sample Input 1 :
v
Sample Output 1 :
0
*/


//TOTAL SALARY
int main() {
    int basic;
    cin>> basic;

    char grade;
    cin>> grade;

    float hra = 0.2*basic;
    float da = 0.5*basic;
    float allow;

    if(grade == 'A'){
        allow = 1700;
    } 
    else if(grade == 'B'){
        allow = 1500;
    }
    else{
        allow = 1300;
    }

    float pf = 0.11*basic;

    int ans = round(basic + hra + da + allow - pf);

    cout << ans;

    return 0;
}
/*
Sample Input 1 :
10000 A
Sample Output 1 :
17600
*/


//LARGEST OF THREE NUMBERS
int main() {
    int a, b, c;
    cin>>a>>b>>c;

    if(a > b && a > c){
        cout<<a;
    }    
    else if(b > a && b > c){
        cout<<b;
    }
    else{
        cout<<c;
    }

    return 0;
}
/*
Sample Input 1 :
4 6 1
Sample Output 1 :
6
*/


//FIND QUARDANT OF COORDINATE POINT
int main() {
    int x,y;
    cin>>x>>y;
    if(x != 0 && y == 0){
        cout<<"x axis";
    }
    else if( x == 0 && y != 0){
        cout<<"y axis";
    }
    else if( x == 0 && y == 0){
        cout<<"Origin";
    }
    else if(x > 0 && y > 0){
        cout<<"1st Quadrant";
    }
    else if(x < 0 && y > 0){
        cout<<"2nd Quadrant";
    }
    else if(x < 0 && y < 0){
        cout<<"3rd Quadrant";
    }
    else {
        cout<<"4th Quadrant";
    }

    return 0;
}
/*
Sample Input 1 :
5 100
Sample Output 1 :
1st Quadrant
*/


//SUM OF EVEN NUMBERS TILL N
int main() {
    int n;
    cin>>n;

    int sum = 0;
    for(int i = 0 ; i <= n ; i += 2){
        sum = sum + i;
    }
    cout<<sum;
}
/*
Sample Input 1 :
 6
Sample Output 1 :
12
*/