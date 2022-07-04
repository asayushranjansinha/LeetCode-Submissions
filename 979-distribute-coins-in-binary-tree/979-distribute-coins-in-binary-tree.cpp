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
/* 
** Since there are n nodes and n coins therefore, for each deficit or surplus coin we have to move it somewhere
** So we ask children nodes to return the number of coins they have or they need
** whatever the children will return will be count as a move
*/

class Solution {
    int solve(TreeNode* root, int& steps){
        if(root == NULL){ return 0; }
        
        auto left = solve(root->left,steps);
        auto right = solve(root->right,steps);
        
        // calculate coins that need to be transferred
        steps += abs(left) + abs(right);
        int coins = left + right + root->val - 1;
        return coins;
    }
public:
    int distributeCoins(TreeNode* root) {
        int steps = 0;
        solve(root,steps);
        return steps;
    }
};