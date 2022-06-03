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
    TreeNode* createSubtree(int start,int end,vector<int> &nums){
        if(start > end || start >= nums.size() || end < 0){
            return nullptr;
        }
        
        int index = (start + end)/2;
        int val = nums[index];
        TreeNode* root = new TreeNode(val);
        root->left = createSubtree(start,index-1,nums);
        root->right = createSubtree(index+1,end,nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0,end = nums.size();
        TreeNode* ans = createSubtree(start,end,nums);
        return ans;
    }
};