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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // if both trees are null then merge tree is also null
        if(!root1 && !root2) { return NULL; }
        
        // sum values
        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;
        int val = val1 + val2;
        
        TreeNode* root = new TreeNode(val);
        
        // create left subtree using recursion
        if(root1 && root2){
            root->left = mergeTrees(root1->left,root2->left);
        }
        else if(root2){
            root->left = mergeTrees(NULL,root2->left);
        }
        else if(root1){
            root->left = mergeTrees(root1->left,NULL);
        }
        
        // create right subtree 
        if(root1 && root2){
            root->right = mergeTrees(root1->right,root2->right);
        }
        else if(root2){
            root->right = mergeTrees(NULL,root2->right);
        }
        else if(root1){
            root->right = mergeTrees(root1->right,NULL);
        }
        return root;
    }
};