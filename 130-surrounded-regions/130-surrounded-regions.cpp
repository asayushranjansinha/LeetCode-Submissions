class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis,
            int delrow[], int delcol[]){
        int N = board.size();
        int M = board[0].size();
        
        vis[row][col] = 1;
        // traverse surrounding cells
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < N && 
               ncol >= 0 && ncol < M && 
               board[nrow][ncol] == 'O' && 
               !vis[nrow][ncol]){
                dfs(nrow, ncol,board,vis,delrow,delcol);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int N = board.size();
        int M = board[0].size();
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        //step 1: boundary traversal
        // top and bottom rows
        for(int col = 0; col < M; col++){
            if(board[0][col] == 'O' && !vis[0][col]){
                dfs(0,col,board,vis,delrow,delcol);
            }
            
            if(board[N-1][col] == 'O' && !vis[N-1][col]){
                dfs(N-1,col,board,vis,delrow,delcol);
            }
        }
        
        // left and right cols
        for(int row = 0; row < N; row++){
            if(board[row][0] == 'O' && !vis[row][0]){
                dfs(row,0,board,vis,delrow,delcol);
            }
            
            if(board[row][M-1] == 'O' && !vis[row][M-1]){
                dfs(row,M-1,board,vis,delrow,delcol);
            }
        }
        
        // change matrix
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};