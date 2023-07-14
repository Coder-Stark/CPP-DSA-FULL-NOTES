// ARRAYS 

#include<bits/stdc++.h>
#include<climits>
using namespace std;


//PRINT ARRAY 
int printArray(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int a[5] = {2 , 3, 54, 4 , 21};
    cout<<"The array element are : "<<endl;
    printArray(a , 5);
}
/*OUTPUT
The array element are : 
2 3 54 4 21 
*/


// MAX AND MIN ELEMENT IN ARRAY
int getMax(int a[] , int n){
    // int max = INT_MIN;
    // for(int i = 0 ; i < n ; i++){
    //     if(a[i] > max){
    //         max = a[i];
    //     }
    // }
    // return max;

    int Maximum = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        Maximum = max(Maximum , a[i]);
    }
    return Maximum;
}
int getMin(int a[] , int n){
    // int min = INT_MAX;
    // for(int i = 0 ; i < n ; i++){
    //     if(a[i] < min){
    //         min = a[i];
    //     }
    // }
    // return min;

    int Minimum = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        Minimum = min(Minimum , a[i]);
    }
    return Minimum;
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

    cout<<"Maximum elemeent in array : "<<getMax(a , n)<<endl;
    cout<<"Minimum elemeent in array : "<<getMin(a , n)<<endl;
}
/*OUTPUT
// Enter the size of an array : 
// 6
// Enter the element of an array : 
// 1 3 2 5 9 3 
// Maximum elemeent in array : 9
// Minimum elemeent in array : 1

Enter the size of an array : 
6
Enter the element of an array : 
-8 3 -1 0 45 6
Maximum elemeent in array : 45
Minimum elemeent in array : -8
*/


//SUM OF AN ARRAY ELEMENTS
int ArraySum(int a[] , int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum = sum + a[i];
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];

    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }

    cout<<"Sum of array elements is : "<<ArraySum(a , n)<<endl;
}
/*OUTPUT
Enter the size of an array : 
7 
Enter the element of an array : 
1 2 3 4 5 6 7 
Sum of array elements is : 28
*/



//LINEAR SEARCH
bool LinearSearch(int a[] ,int n ,int key){
    for(int i = 0 ; i < n ; i++){
        if(a[i] == key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    
    int key;
    cout<<"Enter the key element to search : "<<endl;
    cin>>key;

    // cout<<LinearSearch(a  , n , key);

    int found = LinearSearch( a , n , key);
    if(found){
        cout<<"key is present"<<endl;
    }
    else{
        cout<<"Key is absent";
    }

    return 0;
}
/*OUTPUT
Enter the size of an array : 
6
Enter the element of an array : 
1 3 6 8 0 2 
Enter the key element to search : 
6
// 1

key is present
*/



//REVERSE ARRAY ELEMENT
void Reverse(int a[] , int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        swap(a[start] , a[end]);
        start++;
        end--;
    }
}
void PrintArray(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Reverse of array : "<<endl;
    Reverse(a , n);
    PrintArray(a , n);

    return 0;
}
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
1 2 3 4 5
Reverse of array : 
5 4 3 2 1
*/



//SWAP ALTERNATE
void swap(int a[] , int n){
    for(int i = 0 ; i < n ; i = i+2){
        if(a[i+1] < n){
            swap(a[i] , a[i+1]);
        }
    }
}
void PrintArray(int a[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Array after alternate swap "<<endl;
    swap(a , n);
    PrintArray(a , n);
}
/*OUTPUT
Enter the size of an array : 
9
Enter the element of an array : 
1 2 3 4 5 6 7 8 9 
Array after alternate swap 
2 1 4 3 6 5 8 7 9
*/



//FIND UNIQUE ELEMENT IN ARRAY 
int FindUnique(int a[] , int n){
    int ans = 0;

    //XOR all elements
    for(int i = 0 ; i < n ; i++){
        ans = ans^a[i];
    }
    return ans;
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Unique no. is : "<<FindUnique(a , n)<<endl;

    return 0;

}
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
1 2 3 2 1 
Unique no. is : 3
*/



//FIND DUPLICATE ELEMENT IN ARRAY 
int FindDuplicate(int a[] , int n){
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = ans^a[i];
    }
    for(int i = 1 ; i < n ; i++){
        ans = ans^i;
    }
    return ans;
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Duplicate no. is : "<<FindDuplicate(a , n)<<endl;

    return 0;

}
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
1 2 3 4 4
Duplicate no. is : 4
*/



//ARRAY INTERSECTION
int findIntersection(int a[] , int b[] , int n , int m){
    int i = 0 , j = 0 , ans = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            return ans;
            i++;
            j++;
        }
        else if(a[i] > b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}
int main(){
    int n , m  ; 
    cout<<"Enter the size of array a : "<<endl;
    cin>>n;
    cout<<"Enter the size of array b : "<<endl;
    cin>>m;

    int a[100] , b[100];
    cout<<"Enter the element of an array a : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    cout<<"Enter the element of an array b : "<<endl;
    for(int j = 0 ; j < m ; j++){
        cin>>b[j];
    }

    cout<<"Find Intersection : "<<findIntersection(a , b , n , m)<<endl;
}
/*OUTPUT(EXPECTED)
Enter the size of array a : 
5
Enter the size of array b : 
5
Enter the element of an array a : 
1 2 3 4 5 
Enter the element of an array b : 
2 3 4 6 7 
Find Intersection : 2 3 4 
*/



//PAIR SUM
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>>ans;
   for(int i = 0 ; i < arr.size() ; i++){
      for(int j = i+1 ; j < arr.size() ; j++){
         if(arr[i] + arr[j] == s){
            vector<int>temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i], arr[j]));
            ans.push_back(temp);
         }
      }
   }
   sort(ans.begin(), ans.end());
   return ans;
}
/*
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
*/

//TRIPLET SUM / 3SUM                                                    {T.C = O(N*LOGN), S.C = O(N)}
vector<vector<int>> findTriplets(vector<int>& arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == K) {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[l]);
                    temp.push_back(arr[r]);
                    ans.push_back(temp);

                    while (l < r && arr[l] == arr[l + 1]) {
                        l++;
                    }
                    while (l < r && arr[r] == arr[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                } else if (sum < K) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    return ans;
}
/*
Sample Input 1:
1
5
10 5 5 5 2
12
Sample Output 1:
5 5 2
*/


//SORT 0'S AND 1'S
void SortOne(int a[] , int n){
    int left = 0;        //i , j = left  , right
    int right = n-1;
    while(left < right){
        while(a[left] == 0 && left < right){
            left++;
        }
        while(a[right] == 1 && left < right){
            right--;
        }
        swap(a[left] , a[right]);
        left++;
        right--;
    }

}
void PrintArray(int a[] ,  int n){
    for(int i = 0 ; i < n; i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int n ; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Sorted array of  0's and 1's is  : "<<endl;
    SortOne(a , n);
    PrintArray(a , n);

    return 0;

}
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
1 0 1 0 0
Sorted array of  0's and 1's is  : 
0 0 0 1 1
*/

//BINARY SEARCH
int BinarySearch(int a[] , int n , int key){
    int start = 0;
    int end = n-1;
    // int mid = (start + end )/2 ;             in 1 case fail ( -2^31-1 to 2^31-1)
    int mid = start + (end - start)/2;
    while(start <= end){
        if(a[mid] == key){
            return mid;
        }
        if(a[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        // mid = (start + end) / 2;
        mid = start + (end - start)/2;
    }
    return -1;
}
int main(){
    int n , key; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Enter the key element to find : "<<endl;
    cin>>key;

    cout<<"key element is found at index : "<<BinarySearch(a , n , key)<<endl;


    return 0;

}
/*OUTPUT
Enter the size of an array : 
7
Enter the element of an array : 
1 3 6 9 23 56 12
Enter the key element to find : 
56
key element is found at index : 5
*/


//FIRST AND LAST POSITION OF ELEMENT IN SORTED ARRAY
int FirstOccurance(int a[] , int n , int key){
    int s = 0;
    int e = n-1;
    int mid = s + (e -s)/2;
    int ans = -1;
    while(s <= e){
        if(a[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(a[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int LastOccurance(int a[] , int n , int key){
    int s = 0;
    int e = n-1;
    int mid = s + (e -s)/2;
    int ans = -1;
    while(s <= e){
        if(a[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(a[mid] < key){
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int main(){
    int n , key; 
    cout<<"Enter the size of an array : "<<endl;
    cin>>n;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Enter the key element to find : "<<endl;
    cin>>key;

    cout<<"First key element is found at index : "<<FirstOccurance(a , n , key)<<endl;
    cout<<"Last key element is found at index : "<<LastOccurance(a , n , key)<<endl;

    cout<<"Total occurance of an element is : "<<(LastOccurance(a , n , key) - FirstOccurance(a , n , key) + 1 )<<endl;


    return 0;

}
/*OUTPUT
Enter the size of an array : 
7
Enter the element of an array : 
1 2 4 4 4 4 4  
Enter the key element to find : 
4
First key element is found at index : 2
Last key element is found at index : 6
Total occurance of an element is : 5
*/


//PEAK INDEX IN MOUNTAIN ARRAY
int PeakIndex(int a[] , int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(a[mid] < a[mid + 1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
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

    cout<<"Peak Index in Mountain Array is : "<<PeakIndex(a , n)<<endl;

    return 0;
}
/*OUTPUT
Enter the size of an array : 
7
Enter the element of an array : 
1 2 3 5 3 2 0 
Peak Index in Mountain Array is : 3
*/


//FIND PIVOT IN AN ARRAY
int GetPivot(int a[] , int n){
    int s = 0; 
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(a[mid] >= a[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
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

    cout<<"Pivot Index in Array is : "<<GetPivot(a , n)<<endl;

    return 0;
}
/*OUTPUT
Enter the size of an array : 
5
Enter the element of an array : 
8 10 17 1 3 
Pivot Index in Array is : 3
*/


//SEARCH IN ROTATED SORTED ARRAY
int GetPivot(int a[] , int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s < e){
        if(a[mid] >= a[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}
int BinarySearch(int a[] , int s , int e , int key){
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    while(start <= end){
        if(a[mid] == key){
            return mid;
        }
        if(a[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
int FindPosition(int a[] , int n, int key){
    int pivot = GetPivot(a , n);
    if(key >= a[pivot] && key <= a[n-1]){
        return BinarySearch(a , pivot , n-1 , key);
    }
    else{
        return BinarySearch(a , 0 , pivot-1 , key );
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
    int key;
    cout<<"Enter the key element to search : "<<endl;
    cin>>key;

    cout<<"Search in Rotated Sorted Array is : "<<FindPosition(a , n , key)<<endl;

    return 0;
}
/*OUTPUT
Enter the size of an array : 
7
Enter the element of an array : 
4 5 6 0 1 2 3 
Enter the key element to search : 
0
Search in Rotated Sorted Array is : 3
*/


//SQUARE ROOT USING BINARY SEARCH (morePricise function use to find precise value )
long long int SqrtInteger(int n){
    int s = 0;
    int e = n;
    long long int mid = s + (e - s)/2;
    long long int ans = -1;

    while(s <= e){
        long long int square = mid * mid;
        if(square == n){
            return mid;
        }
        else if (square < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
double morePrecise(int n , int precision , int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i = 0 ; i < precision ; i++){
        factor = factor/10;
        
        for(double j = ans ; j * j < n ; j = j + factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the value to find its sqareroot : "<<endl;
    cin>>n;

    int tempSol = SqrtInteger(n);
    cout<<"not precise Square root of n : "<<tempSol<<endl;

    double perSol = morePrecise(n , 3 , tempSol);
    cout<<"Very Precide Square root of n : "<<perSol<<endl;

    return 0;
}
/*OUTPUT
Enter the value to find its sqareroot : 
37
not precise Square root of n : 6
Very Precide Square root of n : 6.082
*/


//BOOK ALLOCATION PROBLEM
//n = no. of books ,, m = no. of students
/*Allocate the book to m students such that Maximum no. of pages assigned to a student is minimum value*/
int isPossible(int a[] , int n , int m , int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0 ; i < n ; i++){
        if(pageSum + a[i] <= mid){
            pageSum += a[i];
        }
        else{
            studentCount++;
            if(studentCount > m || a[i] > mid){
                return false;
            }
            pageSum = a[i];
        }
    }
    return true;
}
int allocateBooks(int a[] ,int n ,int m){
    int s = 0;
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        sum += a[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s)/2;
    while(s <= e){
        if(isPossible(a , n , m , mid)){
            ans = mid;
            e  = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int main(){
    int n; 
    cout<<"Enter the no. of books : "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the no. of students : "<<endl;
    cin>>m;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"Allocate the book to m students such that"<<endl;
    cout<<"Maximum no. of pages assigned to a student is minimum value : "<<allocateBooks(a , n , m)<<endl;


    return 0;
}
/*OUTPUT
Enter the no. of books : 
4
Enter the no. of students : 
2
Enter the element of an array : 
10 20 30 40 
Allocate the book to m students such that
Maximum no. of pages assigned to a student is 
minimum value : 60
*/


//PAINTERS PARTITION PROBLEM


//AGGRESIVE COW PROBLEM
//n = no. of stalls , k = aggressive cows
//put the cow to the stall , such that the minimum distance between two of them is as large as possible,
//Return largest minimum distance
#include<algorithm>
/*
bool isPossible(int a[] ,int n , int k , int mid){
    int cowCount = 1;
    int lastPos = a[0];
    for(int i = 0 ; i < n ; i++){
        if(a[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = a[i];
        }
    }
    return false;
}
int aggressiveCow(int a[] , int n , int k){

    sort(a , a+n);

    int s = 0;
    int maxi = -1;
    for(int i = 0 ; i < n ; i++){
        maxi = max(maxi , a[i]);
    }
    int e = maxi;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(isPossible(a , n , k , mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
int main(){
    int n; 
    cout<<"Enter the no. of stalls : "<<endl;
    cin>>n;

    int k;
    cout<<"Enter the no. of aggressive cows : "<<endl;
    cin>>k;

    int a[100];
    cout<<"Enter the element of an array : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    cout<<"the minimum distance between two of them is as large as possible"<<endl;
    cout<<"Return largest minimum distance : "<<aggressiveCow(a , n , k)<<endl;


    return 0;
}
*/
/*OUTPUT
Enter the no. of stalls :
5
Enter the no. of aggressive cows : 
2
Enter the element of an array : 
4 2 1 3 6 
the minimum distance between two of them is as large as possible
Return largest minimum distance : 5
*/