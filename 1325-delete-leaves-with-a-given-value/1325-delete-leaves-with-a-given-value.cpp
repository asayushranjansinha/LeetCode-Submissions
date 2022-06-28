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
// leaf can only be found by dfs
// step 1 : dfs
class Solution {
    bool isLeaf(TreeNode* root){
        return (!root->left) && (!root->right);
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){ return NULL; }
        
        // post order fashion is perfect
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        
        // operate on node
        if(isLeaf(root) && root->val == target){
            // delete
            return NULL;
        }
        return root;
    }
};