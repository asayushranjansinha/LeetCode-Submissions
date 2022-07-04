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
    void solve(TreeNode* root, int &count, int maxi){
        if(root == NULL){ return ; }
        
        if(maxi <= root->val){ count++; }
        maxi = max(maxi,root->val);
        
        solve(root->left,count,maxi);
        solve(root->right,count,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root,count,-1e8);
        return count;
    }
};