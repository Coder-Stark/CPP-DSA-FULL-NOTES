//BACKTRACKING

#include <bits/stdc++.h> 

//RAT IN A MAZE PROBLEM                                        {T.C =  O(4^(n^2)) S.C = O(N*N)}
bool isSafe(int newx, int newy ,vector<vector<bool>>&vis,vector < vector < int >> & arr,int n ){
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (vis[newx][newy] != 1) && arr[newx][newy] == 1){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x , int y ,vector < vector < int >> & arr, int n,vector<string>&ans,vector<vector<bool>>&vis,string path ){
    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //4-movements (D, L , R , U)
    //Down - x+1,y
    vis[x][y] = 1;
    if(isSafe(x+1,y,vis,arr,n)){

        solve(x+1, y, arr , n , ans , vis,path+'D');

    }
    //Left - x,y-1
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x, y-1, arr , n , ans , vis,path+'L');
    }
    //Right - x,y+1
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1, arr , n , ans , vis,path+'R');
    }
    //Up - x-1,y
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y, arr , n , ans , vis,path+'U');
    }
    vis[x][y] = 0;
}                     
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path = "";
    if(arr[0][0] == 0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}
/*
Sample Input 1:
4
1 0 0 0 
1 1 0 1
1 1 0 0
0 1 1 1
Sample Output 1:
DDRDRR DRDDRR
*/


//THE N QUEEN PUZZLE                                                {T.C = N! , S.C = N*N}
#include <bits/stdc++.h> 
void addSolution(vector<vector<int>>&board, vector<vector<int>>&ans,int n){
	vector<int>temp;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++){
			temp.push_back(board[i][j]);
		}
	}
	return ans.push_back(temp);
}
bool isSafe(int row , int col, vector<vector<int>>&board, int n){
	int x = row;
	int y = col;

	//check for same row
	while( y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
	}
	
	//check for left-up diagonal attack
	x = row;
	y = col;
	while(x >= 0 && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x--;
	}

	//check for left-down diagonal attack
	x = row;
	y = col;
	while(x < n && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x++;
	}

	return true;
}
void solve(int col, vector<vector<int>>&ans, vector<vector<int>>&board, int n){
	//base case
	if(col == n){
		addSolution(board,ans,n);
		return;
	}
	//handle 1 case rest can be by recursion
	for(int row =  0 ; row < n ; row++){
		if(isSafe(row , col , board, n)){
			board[row][col] = 1;
			solve(col+1,ans,board,n);

			//backtrack
			board[row][col] = 0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	vector<vector<int>>board(n,vector<int>(n,0));
	vector<vector<int>>ans;

	solve(0 ,ans , board , n);
	return ans;
}
/*
Sample Input 1:
1
4   
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
//valid example
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
*/


//SUDOKU SOLVER                                                         {T.C = 9^M (M = no. of empty cell) , S.C = O(1)}
#include <bits/stdc++.h> 
bool isSafe(int row , int col , vector<vector<int>>&board, int val){
    for(int i = 0 ; i < board.size() ; i++){
        //row check
        if(board[row][i] == val){
            return false;
        }
        //column check
        if(board[i][col] == val){
            return false;
        }
        //3x3 matrix unique val check
        if(board[3*(row/3)+ i/3][3*(col/3)+ i%3] == val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board)
{
    int n = board[0].size();

    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < n ; col++){
            //cell is empty
            if(board[row][col] == 0){
                for(int val = 1 ; val <= 9 ; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;

                        //recursive call
                        bool possibleSolution = solve(board);
                        if(possibleSolution){
                            return true;
                        }
                        else{
                            //backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}
/*
Sample Input 1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
Sample Output 1
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
*/