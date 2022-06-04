class Solution {
    bool isQueenSafe(vector<string> &board,int row,int col,int size){
        bool safe = true;
        
        // checking in same row & all previous columns
        for(int j = col - 1; j >= 0; j--){
            if(board[row][j] == 'Q'){
                safe = false;
                break;
            }
        }
        
        // checking diagonally upwards
        int i = row-1,j = col-1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                safe = false;
                break;
            }
            i--;
            j--;
        }
        
        // checking diagonally downwards
        i = row+1,j = col-1;
        while(i < size && j >= 0){
            if(board[i][j] == 'Q'){
                safe = false;
                break;
            }
            i++;
            j--;
        }
        return safe;
    }
    
    void nQueens(vector<vector<string>> &ans,vector<string> &board, int queensSoFar, int col, int size){
        if(queensSoFar == size){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < size; row++){
            if(isQueenSafe(board,row,col,size)){
                board[row][col] = 'Q';
                nQueens(ans,board,queensSoFar+1,col+1,size);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        
        nQueens(ans,board,0,0,n);
        return ans;
    }
};