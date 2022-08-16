class Solution {
    void solve(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        vis[i][j] = 1;
        int N = grid.size();
        int M = grid[0].size();
        
        for(int del = -1; del <= 1; del++){
            if(i + del >= 0 && i + del < N && vis[i+del][j] == 0 && grid[i+del][j] == '1'){
                solve(i+del, j, grid,vis);
            }
        }
        
        for(int del = -1; del <= 1; del++){
            if(j + del >= 0 && j + del < M && vis[i][j+del] == 0 && grid[i][j+del] == '1'){
                solve(i, j+del, grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    solve(i,j,grid,vis);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};