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
    void pushElements(TreeNode* root, vector<int> &el){
        if(root == NULL){
            return;
        }
        
        pushElements(root->left,el);
        el.push_back(root->val);
        pushElements(root->right,el);
        
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> elements;
        pushElements(root,elements);
        
        int diff = INT_MAX;
        for(int i = 0; i < elements.size() - 1; i++){
            diff = min(diff,(abs(elements[i] - elements[i+1])));
        }
        return diff;
    }
};