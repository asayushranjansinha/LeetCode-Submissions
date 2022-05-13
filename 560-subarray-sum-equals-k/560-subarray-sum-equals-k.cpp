class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int cnt = 0,sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int remainingSum = sum - k;

            
            if(mp.find(remainingSum) != mp.end()){
                cnt += mp[remainingSum];
            }
            mp[sum]++;
        }
        return cnt;
    }
};