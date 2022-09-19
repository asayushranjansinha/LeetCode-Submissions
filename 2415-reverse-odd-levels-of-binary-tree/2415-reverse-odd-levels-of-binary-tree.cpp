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
    bool isLeaf(TreeNode* root){
        return (!root->left) && (!root->right);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(isLeaf(root)) return root;
        
        // carry reference to node instead of integer values
        queue<TreeNode*> que;
        que.push(root);
        
        int level = 0;
        vector<int>curLevel;
        while(que.empty() == false){
            int size = que.size();
            vector<int>nextLevel;
            
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                
                if(level % 2 == 1){
                    // reverse the values
                    node->val = curLevel[size - i - 1];
                }
                
                // push left child
                if(node->left){
                    que.push(node->left);
                    nextLevel.push_back(node->left->val);
                }
                
                // push right child
                if(node->right){
                    que.push(node->right);
                    nextLevel.push_back(node->right->val);
                }
            }
            
            // update levels before going to next
            curLevel = nextLevel;
            level +=1;
        }
        return root;
    }
};