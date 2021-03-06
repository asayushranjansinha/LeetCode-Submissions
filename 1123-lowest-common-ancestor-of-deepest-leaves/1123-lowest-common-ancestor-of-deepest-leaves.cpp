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
/*
** At each node we will have depth of both left & right subtree,
** because of which we will always know the highest subtree,
** so we can always focus on the highest subtree.
** Whenever the hight of both subtrees is equal then, root must be desired root
*/
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root){ return NULL; }
        
        int leftDepth = countDepth(root->left);
        int rightDepth = countDepth(root->right);
        
        if(leftDepth == rightDepth){
            return root;
        }
        else if(leftDepth < rightDepth){
            return lcaDeepestLeaves(root->right);
        }
        else{
            return lcaDeepestLeaves(root->left);
        }
    }
private:
    unordered_map<TreeNode*,int> depth;
    int countDepth(TreeNode* root){
        if(!root){ return -1; }
        
        int leftDepth = countDepth(root->left);
        int rightDepth = countDepth(root->right);
        if(depth[root]){
            return depth[root];
        }
        return depth[root] = 1 + max(leftDepth,rightDepth);
    }
};