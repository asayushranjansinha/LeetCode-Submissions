class Solution {
    bool isQueenSafe(int row,int col, vector<vector<int>> board,int size){
        // same row
        for(int j = 0; j < col; j++){
            if(board[row][j] == 1){
                return false;
            }
        }
        
        for(int i = row-1,j = col-1; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        
        for(int i = row+1,j = col-1; i < size && j >= 0; i++,j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<vector<int>>&board,int size, int queensSoFar, int col,int &cnt){
        if(queensSoFar == size){
            cnt++;
            return;
        }
        
        for(int row = 0; row < size; row++){
            if(isQueenSafe(row,col,board,size) == true){
                board[row][col] = 1;
                solve(board,size,queensSoFar+1,col+1,cnt);
                board[row][col] = 0;
            }
        }
        return;
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        int cnt = 0;
        solve(board,n,0,0,cnt);
        return cnt;
    }
};