//REFERENCE VARIABLES

#include<iostream>
using namespace std;

void update1(int n){
    n++;
}

void update2(int &n){
    n++;
}

//bad practise
// int &fun(int a){
//     int num = 0;
//     int &ans = num;
//     return ans;
// }

int getSum(int *arr , int n2){
    int sum = 0;
    for(int i = 0 ; i < n2 ; i++){
        sum = sum + arr[i];
    }
    return sum;
}
int main(){
    int i = 5;
    
    //create reference variable
    int &j = i;

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;
    
    int n = 7;
    cout<<"Before "<<n <<endl;
    update1(n);
    cout<<"After "<<n<<endl;
    
    cout<<"Before "<<n<<endl;
    update2(n);
    cout<<"After "<<n<<endl;
    
    // fun(n);
    
    //heap memory allocation
    char ch = 'a';
    cout<<sizeof(ch)<<endl;
    
    char * c = &ch;
    cout<<sizeof(c)<<endl;
    
    //variable size array
    int n2;
    cout<<"Enter the size of an array : "<<endl;
    cin>>n2;
    int *arr = new int[n2];
    
    cout<<"Enter the elements of an array : "<<endl;
    for(int i = 0 ; i < n2 ; i++){
        cin>>arr[i];
    }
    
    
    int ans = getSum(arr , n2);
    cout<<"The sum of array is : "<<ans<<endl;


    //2D - Array using heap
    
    
    //for sqare matrix
    int n3;
    cout<<"Enter the no. of rows and columns of array ; "<<endl;
    cin>>n3;
    
    //creating 2D array
    int **arr3 = new int*[n3];
    for(int i = 0 ; i < n3 ; i++){
        arr3[i] = new int[n3];
    }
    
    //Taking input
    cout<<"Taking input : "<<endl;
    for(int i = 0 ; i < n3 ; i++){
        for(int j = 0 ; j < n3 ; j++){
            cin>>arr3[i][j];
        }
    }
    
    //output
    cout<<"The Output is : "<<endl;
    for(int i = 0 ; i < n3 ; i++){
        for(int j = 0 ; j < n3 ; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //2D array for diffrent rows and columns
    int row ;
    cout<<"Enter the no. of rows : "<<endl;
    cin>>row;
    
    int col;
    cout<<"Enter the no. of col ; "<<endl;
    cin>>col;
    
    //create 2D array
    int **arr4 = new int*[row];
    for(int i = 0 ; i < col ; i++){
        arr4[i] = new int[col];
    }
    
    //taking input
    cout<<"Enter the rows and col elements : "<<endl;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin>>arr4[i][j];
        }
    }
    //Output
    cout<<"Enter the rows and col elements : "<<endl;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cout<<arr4[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memory
    for(int i = 0 ; i < row ; i++){
        delete []arr4[i];
    }

    delete []arr4;
  
}


/*OUTPUT
5
6
7

Before 7
After 7

Before 7
After 8
1
8

Enter the size of an array : 
5
Enter the elements of an array : 
1 2 3 4 5 
The sum of array is : 15


//2D array for same no. of rows and cols(square matrix)
Enter the no. of rows and columns of array ; 
3
Taking input : 
1 2 3 4 5 6 7 8 9
The Output is : 
1 2 3 
4 5 6 
7 8 9 

//2D array for different no. of rows and cols
Enter the no. of rows : 
3
Enter the no. of col ; 
4
Enter the rows and col elements : 
1 2 3 4 
5 6 7 8 
2 3 4 5 
Enter the rows and col elements : 
1 2 3 4 
5 6 7 8 
2 3 4 5 
*/