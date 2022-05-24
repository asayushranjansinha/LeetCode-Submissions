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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;

        if(!root){
            return ans;
        }
        
//      map<horizontal Distance,map<level,vector<integer value > > >
        map<int,map<int,vector<int> > > nodes;
//                          horizon.. level..
        queue<pair<TreeNode*,pair<int,int> > > q;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(q.empty() == false){
            auto front = q.front();
            q.pop();
            
            auto node = front.first;
            auto hDistance = front.second.first;
            auto level = front.second.second;
            
            nodes[hDistance][level].push_back(node->val);
            
            if(node->left){
                q.push(make_pair(node->left,make_pair(hDistance-1,level+1)));
            }
            if(node->right){
                q.push(make_pair(node->right,make_pair(hDistance+1,level+1)));
            }
        }
        
        for(auto col : nodes){
            vector<int>res;
            for(auto row : col.second){
                sort(row.second.begin(),row.second.end());
                for(auto k : row.second){
                    res.push_back(k);
                }
                
            }
            ans.push_back(res);
        }
        return ans;        
    }
};