class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        int count = 0;
        vector<int> indegree(N,0);
        vector<int>adj[N];
        
        // create adj list
        for(auto edges : pre){
            int u = edges[0];
            int v = edges[1];
            
            adj[v].push_back(u);
        }
        
        // calc indegree for all nodes
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        // push all 0 indegree nodes into queue
        queue<int>q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            count++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0) q.push(it);
            }
        }        
        return count == N;
    }
};