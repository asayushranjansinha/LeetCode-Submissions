class Solution {
public:
    void mutateGrid(int row, int col, vector<vector<int>>&grid){
        int N = grid.size();
        int M = grid[0].size();
        
        if(row < 0 || col < 0 || row == N || col == M || grid[row][col] != 1) return;
        
        grid[row][col] = 0;
        mutateGrid(row-1,col,grid);
        mutateGrid(row+1,col,grid);
        mutateGrid(row,col-1,grid);
        mutateGrid(row,col+1,grid);
        
        return;
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> duplicateGrid = grid;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if((i * j == 0 || i == N-1 || j == M-1 ) && (duplicateGrid[i][j] == 1)){
                    mutateGrid(i,j,duplicateGrid);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(duplicateGrid[i][j] == 1) count++;
            }
        }
        return count;
    }
};