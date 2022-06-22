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
private:
    void solve(TreeNode* & root, int &sum){
        if(root == NULL){
            return;
        }
        
        // count & modify right subtree
        solve(root->right,sum);
        
        // modify root-val
        root->val += sum;
        sum = root->val;
        
        // modify left subtree
        solve(root->left,sum);
        return;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        
        return root;
    }
};