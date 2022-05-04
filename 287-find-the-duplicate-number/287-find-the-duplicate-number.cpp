class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < N-1; i++){
            if(nums[i] == nums[i+1]){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};