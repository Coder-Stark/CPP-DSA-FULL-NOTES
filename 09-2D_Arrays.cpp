//2D- ARRAYS

#include<iostream>
#include<climits>
using namespace std;

/*
//SEARCH IN 2D ARRAY
bool isPresent(int a[][4] , int target , int i , int j){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(a[i][j] == target){
                return 1;
            }
        }
    }
    return 0;
}

//PRINT ROW WISE SUM
void rowWiseSum(int a[][4] , int i , int j){
    for(int i = 0 ; i < 3 ; i++){
        int sum = 0 ;
        for(int j = 0 ; j < 4 ; j++){
            sum += a[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

//PRINT COLUMN WISE SUM
void colWiseSum(int a[][4] , int i , int j){
    for(int j = 0 ; j < 4 ; j++){
        int sum = 0 ;
        for(int i = 0 ; i < 3 ; i++){
            sum += a[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

//LARGEST ROW SUM INDEX
int largestRowSumIndex(int a[][4] , int i , int j){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int i = 0 ; i < 3 ; i++){
        int sum = 0;
        for(int j = 0 ; j < 4 ; j++){
            sum += a[i][j];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = i;
        }
    }
    cout<<"The maximum sum is : "<<maxi<<endl;
    return rowIndex;
}
int main(){
    int a[3][4];
    // int a[3][4] = {{1 , 2 , 3 , 4 } , {2 , 3 , 4 , 5} , {3 , 4 , 5 , 6} };
    
    cout<<"Enter the elements of 2D array  : "<<endl;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin>>a[i][j];
        }
    }

    cout<<"The array element are : "<<endl;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int target;
    cout<<"Enter the target element to find : "<<endl;
    cin>>target;

    if(isPresent(a , target , 3 , 4 )){
        cout<<"The element is present "<<endl;
    }
    else{
        cout<<"The element is absent "<<endl;
    }

    cout<<"The row wise sum is : "<<endl;
    rowWiseSum(a , 3 , 4);

    cout<<"The column wise sum is : "<<endl;
    colWiseSum(a , 3 , 4);

    int ls = largestRowSumIndex(a , 3 , 4);
    cout<<"Maximum row sum is at index : " <<ls<<endl;


    return 0;
}
*/
/*OUTPUT
Enter the elements of 2D array  : 
1 2 3 4 5 6 7 8 9 10 11 12

The array element are : 
1 2 3 4
5 6 7 8
9 10 11 12 

Enter the target element to find :
10
The element is present 

The row wise sum is :
10 26 42

The column wise sum is :
15 18 21 24

The maximum sum is : 42
Maximum row sum is at index : 2
*/

  
//PRINT LIKE A WAVE
/*
#include<vector>

vector<int> wavePrint(vector<vector<int>>a , int nRow , int mCol){
    vector<int>ans;
    for(int col = 0 ; col < mCol ; col++){
        if(col & 1){
            //odd index -> bottom to up
            for(int row = nRow - 1 ; row >= 0 ; row--){
                ans.push_back(a[row][col]);
            }
        }
        else{
            //even index -> top to bottom
            for(int row = 0 ; row < nRow ; row++){
                ans.push_back(a[row][col]);
            }
        }
    }
    return ans;
}
*/


//SPIRAL PRINT
/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0 ;
        int total = row*col;

        //index initiallisation
        int startRow = 0;
        int endRow = row - 1;
        int startCol = 0 ; 
        int endCol = col - 1;

        while(count < total ){

            //print starting row
            for(int i = startCol ; count < total && i <= endCol ; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            //print ending col
            for(int i = startRow ; count < total && i <= endRow ; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            //print ending Row
            for(int i = endCol ; count < total && i >= startCol ; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            //print starting col
            for(int i = endRow ; count < total && i >= startRow ; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};
*/


//SEARCH IN 2D MATRIX
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = row * col - 1;

        int mid = s + (e-s)/2;

        while(s <= e){
            int element = matrix[mid/col][mid%col];
            if(element == target){
                return 1;
            }
            else if(element < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e - s)/2;
        }
        return 0;
    }
};
*/


//SEARCH IN 2D MATRIX (2)
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col-1;

        while(rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];
            if(element == target){
                return 1;
            }
            else if(element < target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};
*/
