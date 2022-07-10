/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) { return ans; }
        
        queue<Node*> q;
        q.push(root);
        
        while(q.empty() == false){
            int size = q.size();
            vector<int> level;
            while(size-->0){
                auto front = q.front();
                q.pop();
            
                for(auto el : front->children){
                    q.push(el);
                } 
                
                level.push_back(front->val);
            }
            ans.push_back(level);
        }
        return ans;        
    }
};