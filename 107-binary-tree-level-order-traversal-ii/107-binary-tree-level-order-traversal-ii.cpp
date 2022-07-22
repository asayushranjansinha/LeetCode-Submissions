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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){ return res; }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false){
            int size = q.size();
            vector<int> ans;
            while(size-->0){
                auto node = q.front();
                q.pop();
                
                if(node->left){ q.push(node->left); }
                if(node->right){ q.push(node->right); }
                
                ans.push_back(node->val);
            }
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};