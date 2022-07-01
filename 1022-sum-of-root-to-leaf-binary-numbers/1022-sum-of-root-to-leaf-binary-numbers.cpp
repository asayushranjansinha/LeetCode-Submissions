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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    int solve(TreeNode* root, int sum){
        if(root == NULL){ return 0; }
        
        sum = (2 * sum )+root->val;
        if(isLeaf(root)) { return sum; }
        return solve(root->left,sum) + solve(root->right,sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root){ return 0; }
        return solve(root,0);
    }
};