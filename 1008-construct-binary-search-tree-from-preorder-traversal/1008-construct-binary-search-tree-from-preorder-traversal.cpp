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
    TreeNode* insertInBST(TreeNode* &root, int val){
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        
        if(root->val < val){
            root->right = insertInBST(root->right,val);
        }
        else if(root->val > val){
            root->left = insertInBST(root->left,val);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int noOfNodes = preorder.size();
        TreeNode* firstNode = new TreeNode(preorder[0]);
        
        for(int i = 1; i < noOfNodes; i++){
            firstNode = insertInBST(firstNode,preorder[i]);
        }
        return firstNode;
    }
};