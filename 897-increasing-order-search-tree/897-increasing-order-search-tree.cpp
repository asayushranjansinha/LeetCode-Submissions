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
    void inorder(TreeNode* root, TreeNode* &prev){
        if(root == NULL){ return; }
        
        inorder(root->left,prev);
        prev->left = NULL;
        prev->right = root;
        prev = root;
        inorder(root->right,prev);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* prev = dummy;
        inorder(root,prev);
        prev->left = NULL;
        prev->right = NULL;
        return dummy->right;
    }
};