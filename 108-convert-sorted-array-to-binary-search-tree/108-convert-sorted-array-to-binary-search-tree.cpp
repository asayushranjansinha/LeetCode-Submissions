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
    TreeNode* insert(TreeNode* root, int lo, int hi, vector<int> &nums){
        if(lo > hi){
            return NULL;
        }
        
        int mid = lo + (hi - lo)/2;
        int val = nums[mid];
        root = new TreeNode(val);
        
        root->left = insert(root->left,lo,mid-1,nums);
        root->right = insert(root->right,mid+1,hi,nums);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = insert(root,0,n-1,nums);
        return root;
    }
};