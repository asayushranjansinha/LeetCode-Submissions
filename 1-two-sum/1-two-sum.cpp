class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            int n1 = nums[i];
            int n2 = target - n1;
            
            if(mp.find(n2) != mp.end()){
                int i1 = i;
                int i2 = mp[n2];
                
                ans.push_back(i1);
                ans.push_back(i2);
                break;
            }
            mp[n1] = i;
            
        }
        return ans;
    }
};