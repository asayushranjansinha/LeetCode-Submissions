class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int N = nums.size();
        if(N == 1){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int i = 0,j = N-1;
        int cnt = 0;
        while(i < j){
            if(nums[i] + nums[j] == k){
                i++;
                j--;
                cnt++;
            }else if(nums[i] + nums[j] < k){
                i++;
            }else {
                j--;
            }
        }
        return cnt;
    }
};