/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root,vector<int> &leafNodes){
        if(root == nullptr){
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            leafNodes.push_back(root->val);
        }
        
        dfs(root->left,leafNodes);
        dfs(root->right,leafNodes);
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leafNodes1,leafNodes2;
        
        dfs(root1,leafNodes1);
        dfs(root2,leafNodes2);
        
        if(leafNodes1.size() != leafNodes2.size()){
            return false;
        }
        
        int n = leafNodes1.size();
        for(int i = 0; i < n; i++){
            if(leafNodes1[i] != leafNodes2[i]){
                return false;
            }
        }
        return true;
    }
};