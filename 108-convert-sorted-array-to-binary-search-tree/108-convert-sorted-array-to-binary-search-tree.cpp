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
    TreeNode* createBST(int low, int high,vector<int> &nums){
        // basecase
        if(low > high){
            return NULL;
        }
        
        int midIndex = (low + high)/2;
        int val = nums[midIndex];
        TreeNode* root = new TreeNode(val);
        
//         recursive calls to create left & right subtrees
        root->left = createBST(low,midIndex-1,nums);
        root->right = createBST(midIndex+1,high,nums);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0,high = nums.size();
        TreeNode* root = createBST(low,high-1,nums);
        return root;
    }
};