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
    void helper(TreeNode* root, string path, vector<string> &paths){
        if(root == NULL){
            return ;
        }
        else if(root->left == NULL && root->right == NULL){
            path = path + to_string(root->val);
            paths.push_back(path);
            return;
        }
        // add val to the current path
        path = path + to_string(root->val) + "->";
        
        // continue to move via both childs
        helper(root->left,path,paths);
        helper(root->right,path,paths);
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL){
            return paths;
        }
        
        string path = "";
        helper(root,path,paths);
        return paths;
    }
};