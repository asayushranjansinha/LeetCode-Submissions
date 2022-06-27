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
    void solve(TreeNode* root, TreeNode* granpa,TreeNode* parent, int &ans){
        if(root == NULL){ return ; }
        
        if(granpa && granpa->val % 2 == 0){
            // grandparent exists & is even
            ans += root->val;
        }
        
        // recursive calls to child nodes
        // parent is grandparent 
        // node is parent
        solve(root->left,parent,root,ans);
        solve(root->right,parent,root,ans);
        
        return;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode* granpa = NULL, *parent = NULL;
        int ans = 0;
        solve(root,granpa,parent,ans);
        
        
        return ans;
    }
};