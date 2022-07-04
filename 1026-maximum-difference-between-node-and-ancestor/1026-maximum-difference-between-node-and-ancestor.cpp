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
    pair<int,int> solve(TreeNode* root, int &diff){
        if(root == NULL){ return  make_pair(INT_MIN,INT_MAX); }
        
        // postorder dfs approach
        auto left = solve(root->left,diff);
        int leftMax = left.first;
        int leftMin = left.second;
        
        auto right = solve(root->right,diff);
        int rightMax = right.first;
        int rightMin = right.second;
        
        // smarter way of calculating max/min in cpp for 3 values is max({,,})
        int currmax = max({leftMax,rightMax,root->val}); 
        int currmin = min({leftMin,rightMin,root->val});
       
        diff = max({diff,currmax - root->val, root->val - currmin});
        return {currmax,currmin};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        solve(root,diff);
        return diff;
    }
};