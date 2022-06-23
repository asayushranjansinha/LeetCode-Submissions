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
    vector<int> res;
    void pushAll(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        pushAll(root->left);
        res.push_back(root->val);
        pushAll(root->right);
        
        return;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        
        pushAll(root1);
        pushAll(root2);
        sort(res.begin(),res.end());
        
        return res;
    }
};