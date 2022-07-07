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
/* Three things to consider while solving the question : 
** 1. We can only delete node while backtracking, i.e postorder
** 2. Answer should only store the root nodes of all broken subtrees
** 3. To optimize on quality we will use unordered_map/set to check if node is to be deleted
      instead of looping over the array.
*/

class Solution {
private:
    TreeNode* solve(TreeNode* root,unordered_map<int,bool> &map, vector<TreeNode*> &ans){
        if(root == NULL){ return NULL; }
        
        // recursive calls to delete nodes 
        root->left = solve(root->left,map,ans);
        root->right = solve(root->right,map,ans);
        
        // check if node is to be deleted
        if(map.find(root->val) != map.end()){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            
            if(left != NULL){
                ans.push_back(left);
            }
            if(right != NULL){
                ans.push_back(right);
            }
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool> map;
        // marked all nodes to be deleted
        for(auto el: to_delete){
            map[el] = true;
        }
        
        vector<TreeNode*> ans;
        root = solve(root,map,ans);
        if(root && map.find(root->val) == map.end()){
            ans.push_back(root);
        }
        return ans;
    }
};