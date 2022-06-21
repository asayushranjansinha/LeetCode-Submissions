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
    vector<int> inorder;
    void inOrder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        inOrder(root->left);
        inorder.push_back(root->val);
        inOrder(root->right);
        return;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int low = 0, high = inorder.size() - 1;
        cout << inorder.size() << endl;
        while(low < high){
            if(inorder[low] + inorder[high] == k){
                return true;
            }
            else if(inorder[low] + inorder[high] < k){
                low++;
            }
            else{
                high--;
            }
        }
        return false;
    }
};