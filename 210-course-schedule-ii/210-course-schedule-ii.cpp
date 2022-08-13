class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<int> toposort;
        vector<int> indegree(N,0);
        vector<int>adj[N];
        
        for(auto edge : pre){
            int u = edge[0];
            int v = edge[1];
            
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            toposort.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }                

        if(cnt != N) {
            toposort.clear();
        }
        return toposort;
    }
};