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
    int findMaxValueIndex(vector<int> &nums,int startIndex, int lastIndex){
        if(startIndex > lastIndex){ return -1; }
        
        int index = startIndex;
        for(int i = startIndex + 1; i <= lastIndex; i++){
            if(nums[i] > nums[index]){
                index = i;
            }
        }
        return index;
    }
    void solve(TreeNode* & root, int startIndex, int lastIndex, vector<int> &nums){
        if(startIndex > lastIndex){ return ; }
        
        // find max value in range
        int maxValueIndex = findMaxValueIndex(nums,startIndex,lastIndex);
        int maxValue = nums[maxValueIndex];
        
        // create node with max value
        root = new TreeNode(maxValue);
        
        // recursive call to create leftpart
        solve(root->left,startIndex,maxValueIndex-1,nums);
        
        // recursive call to create right part
        solve(root->right,maxValueIndex+1,lastIndex,nums);    
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int startIndex = 0,lastIndex = nums.size() - 1;
        
        // if no elements in array
        if(lastIndex < 0){ return NULL; }
        
        TreeNode* root = NULL;
        solve(root,startIndex,lastIndex,nums);
        
        return root;
    }
};