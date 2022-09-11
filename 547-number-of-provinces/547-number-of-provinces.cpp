class Solution {
    int count = 0;
    void dfs(vector<int>adj[],int city, vector<int>&visited){
        visited[city] = 1;
        
        for(auto nbr : adj[city]){
            if(visited[nbr] == 0){
                dfs(adj,nbr,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        int M = isConnected[0].size();
        
        vector<int> adj[N+1];
        
        // create adjacency list
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        vector<int> visited(N+1,0);
        count = 0;
        for(int i = 1; i <= N; i++){
            if(visited[i] == 0){
                ++count;
                dfs(adj,i,visited);
            }   
        }
        return count;
    }
};