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
    void inOrder(TreeNode* root, vector<TreeNode*> &inorder){
        if(root == NULL){
            return;
        }
        
        inOrder(root->left,inorder);
        inorder.push_back(root);
        inOrder(root->right,inorder);
        
        return;
    }
    TreeNode* solve(TreeNode* root, int low, int high,vector<TreeNode*> &inorder){
        if(low > high){
            return NULL;
        }
        
        int mid = (low + high)/2;
        
        root = new TreeNode(inorder[mid]->val);
        root->left = solve(root->left,low,mid-1,inorder);
        root->right = solve(root->right,mid+1,high,inorder);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        inOrder(root,inorder);
        
        int n = inorder.size();
        root = solve(root,0,n-1,inorder);
        return root;
    }
};