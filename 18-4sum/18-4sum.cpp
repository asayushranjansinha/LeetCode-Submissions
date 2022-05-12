class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i <= n-4; i++){
            for(int j = i+1; j <= n-3; j++){
                int sum = target - (nums[i]+nums[j]);
                
                int lo = j+1,hi = n-1;
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        
                        res.push_back(temp);
                        
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++;
                        hi--;
                    }else if(nums[lo] + nums[hi] < sum){
                        lo++;
                    }else{
                        hi--;
                    }
                }
                
                while(j <= n-3 && nums[j] == nums[j+1]) j++;
            }
            while(i <= n-4 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};