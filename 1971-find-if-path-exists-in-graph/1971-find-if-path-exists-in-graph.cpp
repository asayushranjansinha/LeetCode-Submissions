class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        vector<bool> visited(n,false);
        
        for(int i = 0; i < edges.size(); i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
            
        }
        queue<int>q;
        q.push(source);
        
        bool flag = false;
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            if(node == destination){
                flag = true;
                break;
            }
            
            for(auto iterator: adj[node]){
                if(visited[iterator] == false){
                    q.push(iterator);
                    visited[iterator] = true;
                }
            }
        }
        return flag;
    }
};