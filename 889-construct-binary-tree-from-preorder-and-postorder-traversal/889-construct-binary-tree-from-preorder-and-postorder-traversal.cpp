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
/* We are given two things, 
** 1. Pre order of BT
** 2. Post order of BT

** At any point of time we know that the first element of the preorder or last element of postorder is the 
   root node of the binary tree.
** So we will recursively iterate over the preorder and create nodes & increment preorder pointer.
** Since, we know that for an ideal preorder format will be (root-> left -> right), & we have already created 
   root and incremented preorder pointer, so now we have to create left and right subtrees if it exists.
** Only way to check if at any node it has a left or right subtree is by post order, since it follows the 
   format (left -> right -> root). Now if the postorder pointer points to a different element than root, this 
   means that the tree has subtrees, otherwise the subtree is complete.
** After completion of creation of a binary tree at any level we will increment the postorder pointer for        future. If at any moment post order pointer points to same element as root, we will increment the pointer
   & return to previous recursive stage.
*/
class Solution {
    TreeNode* constructHelper(int& prePointer, int& postPointer, vector<int> &pre, vector<int> &post){
        // create node from prePointer
        TreeNode* root = new TreeNode(pre[prePointer++]);
        
        // check if root has subtrees by checking postorder
        if(post[postPointer] != root->val){
            // since it is first check create left subtree
            root->left = constructHelper(prePointer,postPointer,pre,post);
        }
        if(post[postPointer] != root->val){
            // since it is second check create right subtree
            root->right = constructHelper(prePointer,postPointer,pre,post);
        }
        
        // increment postorder
        postPointer++;
        return root;        
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0,postIndex = 0;
        return constructHelper(preIndex,postIndex,preorder,postorder);
    }
};