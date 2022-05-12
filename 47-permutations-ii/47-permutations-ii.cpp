class Solution {
private:
    void solve(vector<int>& nums,set<vector<int>> &ans,vector<int> t){
        if(t.size()==nums.size()){            // Base case-> if temporsry vector size becomes equal to size of given list 
            ans.insert(t);                // Before returning store the valid permutation inside the ans
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=11){            // check if the element is already included
                int j=nums[i];
                nums[i]=11;        // make the current ele to 11 (which is out of the range) so that we will not insert this element in next call
                t.push_back(j);      // store it in the temporary vector
                solve(nums,ans,t);  //recursively call to complete the permutations
                nums[i]=j;      // backtrack 
                t.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;          //to store unique permutations
        vector<vector<int>> ans;
        
        solve(nums,s,{});
        
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};
// 2nd Approach A simple extension of permutation 1. You just need to skip the same element to create unique permutations.

// CODE ->

// class Solution {
// private:
//     void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> t){
//         if(t.size()==nums.size()){
//             ans.push_back(t);
//             return ;
//         }
        
//         for(int j=0;j<nums.size();j++){
//             if(nums[j]!=11){
// 			// The difference between the upper code and this code
			
//             if(j>0 && nums[j]==nums[j-1]) continue;       // skip the element which has already been included
//             int i=nums[j];
//             nums[j]=11;
//             t.push_back(i);
//             solve(nums,ans,t);
//             t.pop_back();
//             nums[j]=i;
//             }
//         }
//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());          // sort the givern nums vector to check the consecutive elements
//         vector<vector<int>> ans;
//         solve(nums,ans,{});
//         return ans;
//     }
// };