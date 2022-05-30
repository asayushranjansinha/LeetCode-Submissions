/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findRootToNodePath(TreeNode* root,TreeNode* target,vector<TreeNode*> &path){
        if(root == NULL){
            return false;
        }
        if(root == target){
            path.push_back(root);
            return true;
        }
        
        bool findInLeftChild = findRootToNodePath(root->left,target,path);
        if(findInLeftChild){
            path.push_back(root);
            return findInLeftChild;
        }
        
        bool findInRightChild = findRootToNodePath(root->right,target,path);
        if(findInRightChild){
            path.push_back(root);
            return findInRightChild;
        }
        return false;
    }
    
    void printKDistance(TreeNode* root, int k, TreeNode* blockNode, vector<int> &ans){
        if(root == NULL || k < 0 || root == blockNode){
            return;
        }
        
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        
        printKDistance(root->left,k-1,blockNode,ans);
        printKDistance(root->right,k-1,blockNode,ans);
        return;        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> nodesAtDistanceK;
        
        vector<TreeNode*> path;
        findRootToNodePath(root,target,path);
        
        for(int i = 0; i < path.size(); i++){
            if(i != 0){
                printKDistance(path[i],k-i,path[i-1],nodesAtDistanceK);
            }else{
                printKDistance(path[i],k-i,NULL,nodesAtDistanceK);
            }
        }
        
        return nodesAtDistanceK;
    }
};