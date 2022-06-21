class BSTIterator{
    stack<TreeNode*> nxt;
    stack<TreeNode*> prv;
    
    public:
    
    BSTIterator(TreeNode* root){
        pushAll(root,1); // create next stack
        pushAll(root,0); // create previous stack
    }
    
    void pushAll(TreeNode* root,int dir){
        if(dir == 1){
            // pushing into next stack
            while(root!= NULL){
                nxt.push(root);
                root = root->left;
            }
        }
        else{
            // pushing into previous stack
            while(root!= NULL){
                prv.push(root);
                root = root->right;
            }
        }
    }
    
    int next(){
        auto node = nxt.top();
        nxt.pop();
        
        if(node->right){
            pushAll(node->right,1);
        }
        return node->val;
    }
    
    int previous(){
        auto node = prv.top();
        prv.pop();
        
        if(node->left){
            pushAll(node->left,0);
        }
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root);
        BSTIterator r(root);
        
        int i = l.next(), j = r.previous();
        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }else{
                j = r.previous();
            }
        }
        return false;
    }
};