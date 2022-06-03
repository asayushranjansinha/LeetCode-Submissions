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
    int sumOfLeftLeaves(TreeNode* root) {
        pair<TreeNode*,int> node;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        
        int sum = 0;
        while(q.size() > 0){
            auto frontNode = q.front();
            q.pop();
            
            root = frontNode.first;
            int isLeftLeaf = frontNode.second;
            
            if(root->left == NULL && root->right == NULL){
                // isLeaf 
                if(isLeftLeaf){
                    sum += root->val;
                }
            }
            
            if(root->left){
                q.push(make_pair(root->left,1));
            }
            if(root->right){
                q.push(make_pair(root->right,0));
            }
        }
        return sum;
    }
};