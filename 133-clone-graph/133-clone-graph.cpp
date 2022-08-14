/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* cur, unordered_map<Node*,Node*>&map){
        vector<Node*> neig;
        Node* clone = new Node(cur->val);
        map[cur] = clone;
        
        
        for(auto it : cur->neighbors){
            if(map.find(it) != map.end()){
                // clone already exists
                neig.push_back(map[it]);
            }
            else{
                neig.push_back(dfs(it,map));
            }
        }
        clone->neighbors = neig;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        else if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node*,Node*> map;
        Node* clone = dfs(node,map);
        return clone;
    }
};