class Solution {
public:
    int search(vector<int>& nums, int target) {
        int candidate = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        if(candidate < nums.size() && nums[candidate] == target) return candidate;
        return -1;
    }
};