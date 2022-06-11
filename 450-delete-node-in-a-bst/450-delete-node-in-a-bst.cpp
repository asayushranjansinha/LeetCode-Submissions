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
    TreeNode* findMax(TreeNode* root){
        TreeNode* maxNode = root->left;
        while(maxNode->right != NULL){
            maxNode = maxNode->right;
        }
        return maxNode;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        
        else if(root->val == key){
            // node found now delete
            
            // no child / leaf node case
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            
            // two child case
            else if(root->right != NULL && root->left != NULL){
                TreeNode* maxInLeftSubtree = findMax(root);
                root->val = maxInLeftSubtree->val;
                root->left = deleteNode(root->left,maxInLeftSubtree->val);
                return root;
            }
            
            // one child case
            
            // only left child
            else if(root->left != NULL && root->right == NULL){
                TreeNode* leftChild = root->left;
                delete(root);
                return leftChild;
            }
            
            // only right child
            else if(root->right != NULL && root->left == NULL){
                TreeNode* rightChild = root->right;
                delete(root);
                return rightChild;
            }
        }
        
        else if(root->val < key){
            // value less than key, search in right subtree
            root->right = deleteNode(root->right,key);
        }
        
        else if(root->val > key){
            // value greater than key, search in left subtree
            root->left = deleteNode(root->left,key);
        }
        
        return root;
    }
};