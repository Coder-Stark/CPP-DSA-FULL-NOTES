//SORTING ALGORITHIM (SELECTION , BUBBLE , INSERTION)
#include<iostream>
using namespace std;


//SELECTION SORT
void seclectionSort(int a[] , int n){
    for(int i = 0 ; i < n-1 ; i++){
        int minIndex = i;
        for(int j = i+1; j < n ; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        swap(a[minIndex] , a[i]);
    }
}
void PrintArray(int a[] , int n){
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the elemeent of an array : "<<endl;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }

    seclectionSort(a , n);
    cout<<"The sorted array after selection sort is : "<<endl;
    PrintArray(a , n);
}
/*OUTPUT
Enter the size of an array : 
7
Enter the elemeent of an array : 
1 9 2 0 3 5 2
The sorted array after selection sort is : 
0 1 2 2 3 5 9
*/


//BUBBLE SORT
void bubbleSort(int a[] , int n){
    for(int i = 1 ; i < n; i++){
        bool swapped = false;                   //for optimisation of bestcase (O(n))
        for(int j = 0; j < n-i ; j++){
            if(a[j] > a[j+1]){
                swap(a[j] , a[j+1]);
                swapped = true;                  //for optimisation of bestcase (O(n))
            }
        }
        if(swapped == false){                     //for optimisation of bestcase (O(n))
            break;
        }
    }
}
void PrintArray(int a[] , int n){
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the elemeent of an array : "<<endl;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }

    bubbleSort(a , n);
    cout<<"The sorted array after bubble sort is : "<<endl;
    PrintArray(a , n);
}
/*OUTPUT
Enter the size of an array : 
7
Enter the elemeent of an array : 
1 9 2 0 3 8 3 
The sorted array after bubble sort is : 
0 1 2 3 3 8 9
*/


//INSERTION SORT
void insertionSort(int a[] , int n){
    for(int i = 1 ; i < n; i++){
        int temp = a[i];
        int j;
        for(j = i-1 ; j >= 0 ; j--){
            if(a[j] > temp){
                //shift
                a[j+1] = a[j];
            }
            else{
                break;
            }
        }
        a[j+1] = temp;
    }
}
void PrintArray(int a[] , int n){
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the elemeent of an array : "<<endl;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }

    insertionSort(a , n);
    cout<<"The sorted array after insertion sort is : "<<endl;
    PrintArray(a , n);
}
/*OUTPUT
Enter the size of an array : 
7
Enter the elemeent of an array : 
10 1 7 4 8 2 11
The sorted array after insertion sort is : 
1 2 4 7 8 10 11
*/
