class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int TOTALROWS = grid.size();
        int TOTALCOLUMNS = grid[0].size();
        
        int freshOrangeCount = 0;
        int maxtime = 0;
        
        int visited[TOTALROWS][TOTALCOLUMNS];
        int deltaRows[] = {-1,0,+1,0};
        int deltaCols[] = {0,+1,0,-1};
//                      {{row,col},time}
        queue< pair < pair<int,int> , int > > que;
        
        
        // search for already rotten oranges
        for(int i = 0; i < TOTALROWS; i++){
            for(int j = 0; j < TOTALCOLUMNS; j++){
                if(grid[i][j] == 1){
                    // fresh orange
                    freshOrangeCount++;
                }
                
                if(grid[i][j] == 2){
                    // rotten orange found
                    visited[i][j] = 1;
                    que.push({{i,j},maxtime}); // time or rotting
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }
        
        // traverse breadth wise to rot all neighbouring oranges 
        while(que.empty() == false){
            int row = que.front().first.first;
            int col = que.front().first.second;
            int time = que.front().second;
            que.pop();
            maxtime = max(time,maxtime);
            
            // rot all neighbouring oranges
            for(int i = 0; i < 4; i++){
                int nRow = row + deltaRows[i];
                int nCol = col + deltaCols[i];
                
                if(nRow >= 0 && nRow < TOTALROWS && 
                   nCol >= 0 && nCol < TOTALCOLUMNS && 
                   grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0){
                    visited[nRow][nCol] = 1;
                    que.push({{nRow,nCol},time+1});
                    freshOrangeCount--;
                }
            }
        }
        
        // check if all freshoranges are rotten 
        if(freshOrangeCount == 0) return maxtime;
        return -1;
    }
};