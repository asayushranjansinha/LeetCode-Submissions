class Solution {
public:
    // function to check if two trees are identical
    bool areIdentical(TreeNode* r1, TreeNode *r2) 
    {
        // if both the trees are null => they are identical hence return true
        if(r1 == NULL and r2 == NULL) return true;
        // if either of trees are NULL return false because they are unequal
        if(r1 == NULL or r2 == NULL) return false;
        // else check for following conditions
        // if the root values of both trees are same
        // if the left subtree of r1 is identical to left subtree of r2
        // if the right subtree of r1 is identical to right subtree of r2
        return (r1->val == r2->val and areIdentical(r1->left, r2->left) and areIdentical(r1->right, r2->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // check if subRoot is NULL if NULL return true as nothing have to be checked
        // each leaf node have NULL as child node thus a subtree
        if(subRoot == NULL) return true;
        // if root is NULL and subRoot is NOT NULL
        // => we can't traverse further subroot exists but root doesn't therefore return false
        if(root == NULL)return false;
        // check if the root and subRoot are identical, if yes return true
        if(areIdentical(root, subRoot)) return true;
        // check for subtrees of the main tree by traversing the right and left child nodes
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};