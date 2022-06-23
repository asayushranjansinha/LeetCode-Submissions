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
class BSTIterator{
    stack<TreeNode*> tree;
    
    public:
    
    BSTIterator(TreeNode* root){
        pushAll(root);
    }
    
    void pushAll(TreeNode* root){
        while(root != NULL){
            tree.push(root);
            root = root->left;
        }
    }
    bool hasNext(){
        return tree.size() > 0;
    }
    
    int getNext(){
        if(!hasNext()) { return -1e9; }
        TreeNode* next = tree.top();
        tree.pop();
        
        if(next->right != NULL){
            pushAll(next->right);
        }
        return next->val;
    }
};
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        
        BSTIterator iterator1(root1);
        BSTIterator iterator2(root2);
        
        auto val1 = iterator1.getNext();
        auto val2 = iterator2.getNext();
        
        while(val1 != -1e9 && val2 != -1e9){
            if(val1 == val2){
                res.push_back(val1);
                res.push_back(val2);
                
                val1 = iterator1.getNext();
                val2 = iterator2.getNext();
            }
            else if(val1 < val2){
                res.push_back(val1);
                val1 = iterator1.getNext();
            }
            else{
                res.push_back(val2);
                val2 = iterator2.getNext();
            }
        }
        
        while(val1 != -1e9){
            res.push_back(val1);
            val1 = iterator1.getNext();
        }
        while(val2 != -1e9){
            res.push_back(val2);
            val2 = iterator2.getNext();
        }
        return res;
    }
};