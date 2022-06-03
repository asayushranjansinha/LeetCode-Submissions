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
    int helper(TreeNode* root, int &sum, int isLeftLeaf){
        if(root == NULL){
            return 0;
        }
        else if(root->left == NULL && root->right == NULL){
            if(isLeftLeaf){
                return root->val;
            }
            return 0;
        }
        
        return sum + helper(root->left,sum,1) + helper(root->right,sum,0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        return helper(root,sum,0);
    }
};