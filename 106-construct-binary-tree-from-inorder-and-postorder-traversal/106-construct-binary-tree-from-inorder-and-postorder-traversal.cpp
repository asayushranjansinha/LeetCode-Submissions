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
    void createMap(vector<int> &in, unordered_map<int,int> &map){
        for(int i = 0; i < in.size(); i++){
            int val = in[i];
            map[val] = i;
        }
    }
    TreeNode* solve(vector<int> &in, vector<int> &post, int &index, int start, int end, unordered_map<int,int> &map){
        if(index < 0){
            return NULL;
        }else if(start > end){
            return NULL;
        }
        
        int value = post[index--];
        TreeNode* root = new TreeNode(value);
        int inorderPos = map[value];
        
        root->right = solve(in, post, index, inorderPos + 1, end, map);
        root->left = solve(in, post, index, start, inorderPos - 1, map);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> map;
        createMap(in,map);
        
        int index = post.size() - 1, start = 0, end = post.size()-1;
        
        TreeNode* root = solve(in,post,index,start,end,map);
        return root;
    }
};