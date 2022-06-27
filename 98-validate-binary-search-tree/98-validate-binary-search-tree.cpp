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
    bool solve(TreeNode* root, long long int max,long long int min){
        if(!root){ return true; }
        
        if(max > root->val && min < root->val){
            return solve(root->left,root->val,min) && solve(root->right,max,root->val);
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long int max = LLONG_MAX, min = LLONG_MIN;
        return solve(root,max,min);
    }
};