class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {}; // null vector
        }
        else if (n == 1){
            return {0}; // only single node
        }
        
        vector<int>degree(n,0);
        vector<int>adj[n];
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        
        queue<int>queue;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)queue.push(i);
        }
        
        vector<int>ans;
        while(!queue.empty()){
            int size = queue.size();
            ans.clear();

            for(int i = 0; i < size; i++){
                int node = queue.front();
                queue.pop();
                ans.push_back(node);
                
                for(auto it : adj[node]){
                    degree[it]--;
                    if(degree[it] == 1) queue.push(it);
                }
            }
        }
        return ans;
    }
};