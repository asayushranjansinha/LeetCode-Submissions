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
    pair<int,int> solve(TreeNode* root, int &diff){
        if(root == NULL){
            return{-1e8,1e8};
        }
        
        auto left = solve(root->left,diff);
        auto right = solve(root->right,diff);
        
        int leftmaxi = left.first;
        int rightmini = right.second;
        
        int ndiff = min( abs(root->val - leftmaxi),
                         abs(root->val - rightmini));
        
        diff = min(diff,ndiff);
        int maxi = max(root->val,right.first);
        int mini = min(root->val,left.second);
        return {maxi,mini};
    }
public:
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        auto p = solve(root,diff);
        return diff;
    }
};