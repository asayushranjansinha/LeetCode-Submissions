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
    bool simplify(TreeNode* &root){
        // basecase
        if(!root){ return false; }
        // 1 should be present in either left subtree or rightsubtree or root 
        bool left = simplify(root->left);
        if(!left){ root->left = NULL; } // remove non 1 nodes
        
        bool right = simplify(root->right);
        if(!right){ root->right = NULL; }        
        
        if(!left && !right && root->val != 1){ root = NULL; return false;}
        if(left || right || root->val == 1){ return true; }
        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        simplify(root); 
        return root;
    }
};