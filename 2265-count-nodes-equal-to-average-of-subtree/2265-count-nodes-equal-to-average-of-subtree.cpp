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
    // <sum , count>
    pair<int,int> solve(TreeNode* root, int &ans){
        // no sum and no children for null node
        if(!root){ return {0,0}; }
                
        // postorder iteration
        pair<int,int>left = solve(root->left,ans);
        int leftSum = left.first;
        int leftCount = left.second;
        
        pair<int,int>right = solve(root->right,ans);
        int rightSum = right.first;
        int rightCount = right.second;
        
        // calc sum & avg
        int subtreeSum = leftSum + rightSum + root->val;
        int subtreeCount = leftCount + rightCount + 1;
        int averageValue = subtreeSum / subtreeCount;
        
        if(root->val == averageValue){
            ans += 1;
        }
        
        return {subtreeSum,subtreeCount};        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};