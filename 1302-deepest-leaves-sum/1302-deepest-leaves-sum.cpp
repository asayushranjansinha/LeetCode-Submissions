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
    void solve(TreeNode* root, int depth, int &maxDepth, int &sum){
        if(!root){ return ; }
        if(depth > maxDepth){
            sum = 0;
            maxDepth = depth;
        }
        
        if(depth == maxDepth){
            sum += root->val;
        }
        solve(root->left,depth+1,maxDepth,sum);
        solve(root->right,depth+1,maxDepth,sum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0,maxDepth = 0,sum = 0;
        solve(root,depth,maxDepth,sum);
        
        return sum;
    }
};