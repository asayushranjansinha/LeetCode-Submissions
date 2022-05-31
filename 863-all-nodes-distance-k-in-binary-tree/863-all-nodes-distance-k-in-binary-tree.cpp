/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void nodeParentMapping(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(root == nullptr){
            return;
        }
        
        queue<TreeNode*> qu;
        qu.push(root);
        parent[root] = nullptr;
        
        while(!qu.empty()){
            TreeNode* currentNode = qu.front();
            qu.pop();
            
            if(currentNode->left){
                parent[currentNode->left] = currentNode;
                qu.push(currentNode->left);
            }
            if(currentNode->right){
                parent[currentNode->right] = currentNode;
                qu.push(currentNode->right);
            }
        }
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         step 1: find target Node ,already given here
//         step 2: create node->parent mapping
//         step 3: solve
        
        // created node->parent mapping
        unordered_map<TreeNode*,TreeNode*> parentMap;
        nodeParentMapping(root,parentMap);
        
        
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool> visitedNodes;
        
        // start iteration by marking node as visited
        q.push(target);
        visitedNodes[target] = true;
        
        int currentLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currentLevel++ == k){ break; }
            
            // since we are moving radially outward increase level
            for(int i = 0; i < size; i++){
                // extracet node from queue
                TreeNode* currentNode = q.front();
                q.pop();
                
                if(currentNode->left && !visitedNodes[currentNode->left]){
                    cout << "left child of " << currentNode->val << endl;
                    q.push(currentNode->left);
                    visitedNodes[currentNode->left] = true;
                }
                
                if(currentNode->right && !visitedNodes[currentNode->right]){
                    cout << "right child of " << currentNode->val << endl;
                    q.push(currentNode->right);
                    visitedNodes[currentNode->right] = true;
                }
                
                if(parentMap[currentNode] && !visitedNodes[parentMap[currentNode]]){
                    cout << "parent of " << currentNode->val << endl;
                    q.push(parentMap[currentNode]);
                    visitedNodes[parentMap[currentNode]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* currentNode = q.front();
            q.pop();

            result.push_back(currentNode->val);
        }
        return result;
    }
};