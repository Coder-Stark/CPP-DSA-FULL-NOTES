//SORTING ALGORITHIM (SELECTION , BUBBLE , INSERTION, MERGE SORT)
#include<bits/stdc++.h>
using namespace std;


//SELECTION SORT                                                       {T.C = O(N^2), S.C = O(1)}
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


//BUBBLE SORT                                                                       {T.C = O(N^2), S.C - O(1)}
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


//INSERTION SORT                                                                 {T.C = O(N^2), S.C = O(1)}
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


//MERGE SORT                                                                             {T.C = O(N*LOGN), S.C = O(N)}
void merge(vector<int>&arr, int low , int mid , int high){
    vector<int>temp;
    int left = low;                               //[low -------mid]
    int right = mid+1;                            //[mid+1 --- high]
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        //right is smaller
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    //put anser in array
    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i-low];
    }
}
void mS(vector<int>&arr, int low , int high){
    if(low == high){
        return;
    }
    int mid = (low+high)/2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low , mid , high);
}
void mergeSort(vector < int > & arr, int n) {
    mS(arr, 0, n-1);                          //index 0 to n-1
}
/*
Sample Input 1 :
2
7
3 4 1 6 2 5 7
4
4 3 1 2
Sample Output 1 :
1 2 3 4 5 6 7
1 2 3 4
*/


//QUICK SORT                                                           {T.C = O(N*LOGN), S.C = O(N)}                                          

//HEAP SORT                                                            {T.C = O(N*LOGN), S.C = O(1)}

//COUNTING SORT                                                        {T.C = O(N + K), S.C = O(N+K)}

//RADIX SORT                                                            {T.C = O(N*K), S.C = O(N+K)}

//BUCKET SORT                                                           {T.C = O(N+K), S.C = O(N)}