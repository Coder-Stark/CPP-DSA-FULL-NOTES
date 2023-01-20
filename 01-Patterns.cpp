// PATTERNS

#include<iostream>
using namespace std;

/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n ){
        int j = 1 ;
        while(j <= n){
            cout<<" * ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
 *  *  *  * 
 *  *  *  * 
 *  *  *  * 
 *  *  *  *
*/


/*
int main(){
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin >>n;
    int i = 1;
    while(i <= n ){
        int j = 1;
        while(j <= n){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }

}
*/
/*OUTPUT
Enter the value of n : 
4
1111
2222
3333
4444
*/


/*
int main(){
    int n ;
    cout<<"Enter the value of n :"<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n :
4
1234
1234
1234
1234
*/ 


/*
int main(){
    int n ;
    cout<<"Enter the value of n ; "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            cout<<n-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n ; 
4
4321
4321
4321
4321
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    int count = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
3
123
456
789
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<" * ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
 * 
 *  *
 *  *  *
 *  *  *  *
*/

/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
1
22
333
4444
*/


/*
int main(){
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 0;
    int count = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4

1
2 3
4 5 6
7 8 9 10
*/


/*
int main(){
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int count = i;  
        int j = 1;
        while(j <= i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
1 
2 3
3 4 5
4 5 6 7 
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<<(i-j+1);
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
1
21
321
4321
*/


/*
int main(){
    int n ;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            char ch = ('A' + i - 1);
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
A A A A 
B B B B 
C C C C
D D D D
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <=n ){
        int j = 1;
        while(j <= n){
            char ch = 'A' + j -1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
3
A B C 
A B C
A B C
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    char value = 'A'; 
    while(i <= n){
        int j = 1;
        while(j <= n){
            cout<<value++<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
3
A B C 
D E F
G H I
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            char ch = ( 'A' + i + j - 2 );
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
3
A B C 
B C D 
C D E
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            char ch = ('A'+i -1 );
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
3
A 
B B
C C C
*/


/*
int  main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    char value = 'A';
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout<< value++<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
A 
B C
D E F
G H I J
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            char ch = ('A' + i + j -2);
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
A 
B C
C D E
D E F G
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j = 1;
        char value = 'A' + n -i;
        while(j <= i){
            cout<<value++<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
D 
C D
B C D
A B C D
*/




/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        int j =1 ;
        while(j <= i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
*
**
***
****
*/

/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = n;
    while(i >= 1){
        int j =1 ;
        while(j <= i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i--;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
****
***
**
*
*/


/*
int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;
    int i = 1;
    while( i <= n){
        
        //for print spaces
        int space = n - i;
        while(space){
            cout<<" ";
            space--;
        }

        //for print stars
        int j = 1;
        while(j <= i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the value of n : 
4
   *
  **
 ***
****
*/


/*
int main(){
    int n ;
    cout<<"Enter the vlaue of n : "<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        //for print space
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
    
        //for print 1st triangle
        int j = 1;
        while(j <= i){
            cout<<j;
            j++;
        }

        //for print 2nd triangle
        int start = i -1;
        while(start){
            cout<<start;
            start--;
        }
        cout<<endl;
        i++;
    }
}
*/
/*OUTPUT
Enter the vlaue of n : 
4
   1
  121
 12321
1234321
*/