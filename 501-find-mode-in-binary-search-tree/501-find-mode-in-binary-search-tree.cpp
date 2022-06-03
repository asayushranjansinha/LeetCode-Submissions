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
    void helper(TreeNode* root,map<int,int> &mp){
        if(!root){
            return;
        }
        mp[root->val]++;
        helper(root->left,mp);
        helper(root->right,mp);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        
        map<int,int> mp;
        helper(root,mp);
        
        int mostFreq = INT_MIN;
        for(auto i : mp){
            mostFreq = max(mostFreq,i.second);
        }
        
        for(auto i : mp){
            if(i.second == mostFreq){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};