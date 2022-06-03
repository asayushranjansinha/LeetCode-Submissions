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
    int helper(TreeNode* root){
        if(!root){
            return 1e8;
        }
        else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        
        int nodesViaLeft = helper(root->left) + 1;
        int nodesViaRight = helper(root->right) + 1;
        
        return min(nodesViaLeft,nodesViaRight);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return helper(root);
    }
};