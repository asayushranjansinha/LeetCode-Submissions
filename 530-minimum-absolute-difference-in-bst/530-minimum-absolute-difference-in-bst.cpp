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
    int diff;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return {-1e8,1e8};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int leftmaxi = left.first;
        int leftmini = left.second;
        
        int rightmaxi = right.first;
        int rightmini = right.second;
        
        int ndiff = min( abs(root->val - leftmaxi),
                         abs(rightmini - root->val));
        
        diff = min(diff,ndiff);
        
        int maxi = max(root->val,rightmaxi);
        int mini = min(root->val, leftmini);
        return {maxi,mini};
        
    }
public:
    int getMinimumDifference(TreeNode* root) {
        diff = INT_MAX; 
        solve(root);
        return diff;
    }
};