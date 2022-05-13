class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         moore's algorithms
        int val = nums[0];
        int freq = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(val == nums[i]) {
                freq++;
            } else {
                freq--;
            }
            if(freq == 0){
                val = nums[i];
                freq = 1;
            }
        }
        return val;
    }
};