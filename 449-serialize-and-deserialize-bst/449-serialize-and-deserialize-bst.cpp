/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){ return ""; }
        
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false){
            auto front = q.front();
            q.pop();
            
            if(front != NULL){
                res.append(to_string(front->val) + "|");
                q.push(front->left);
                q.push(front->right);
            }
            else{
                res.append("#|");   
            }
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){ return NULL; }
        
        stringstream s(data);
        string str;
        
        getline(s,str,'|');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false){
            auto node = q.front();
            q.pop();
            
            getline(s,str,'|');
            if(str == "#"){
                node->left = NULL;
            }
            else {
                TreeNode* leftchild = new TreeNode(stoi(str));
                node->left = leftchild;
                q.push(leftchild);
            }
            
            getline(s,str,'|');
            if(str == "#"){
                node->right = NULL;
            }
            else {
                TreeNode* rightchild = new TreeNode(stoi(str));
                node->right = rightchild;
                q.push(rightchild);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;