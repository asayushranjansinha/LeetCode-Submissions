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
    TreeNode* solve(TreeNode* &root,int low,int high){
        if(root == NULL){ return root; }
        
        // recursion to left node
        root->left = solve(root->left,low,high);
        
        // recursion to right node
        root->right = solve(root->right,low,high);
        
        // subtrees are done now, modify node
        if(root->val < low){
            return root->right;
        }
        else if(root->val > high){
            return root->left;
        }
        else{
            return root;
        }
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};