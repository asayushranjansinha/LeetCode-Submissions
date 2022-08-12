class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0 to i - 1 : 0
        // i to j - 1 : 1
        // j to k : unknown
        // k + 1 to end : 2
        int N = nums.size();
        int i = 0,j = 0,k = N-1;
        while(j <= k){
            if(nums[j] == 0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 1){
                j++;
            }
            else{
                swap(nums[j],nums[k]);
                k--;
            }
        }
    }
};