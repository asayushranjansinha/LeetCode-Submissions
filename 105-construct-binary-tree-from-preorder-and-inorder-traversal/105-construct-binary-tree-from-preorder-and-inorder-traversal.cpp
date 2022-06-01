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
 inorder = left + root + right
 preorder = root + left + right
 
 */
class Solution {
private:
    void createMap(vector<int> &inorder,unordered_map<int,int> &map){
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            map[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> &inorder,vector<int> &preorder,
                                unordered_map<int,int> &map,
                                        int start,int end,int &index){
        
        if(index >= inorder.size() ||start > end){
            return NULL;
        }
        // select root
        int rootValue = preorder[index++];
        TreeNode* root = new TreeNode(rootValue);
        
        // find root in preorder
        int rootPosition = map[rootValue];
        
        // build subtrees by recursive calls
        root->left = solve(inorder,preorder,map,start,rootPosition - 1,index);
        root->right = solve(inorder,preorder,map,rootPosition+1,end,index);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // step 1: find root
        // step 2: build left subtree from inorder
        // step 3: build right subtree from inorder
        // step 4: return root
        unordered_map<int,int> map;
        createMap(inorder,map);
        
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int currentRootIndex = 0;
        TreeNode* root = solve(inorder,preorder,map,inorderStart,inorderEnd,currentRootIndex);
        return root;
    }
};