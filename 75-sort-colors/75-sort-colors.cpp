class Solution {
public:
    // brute force
    void sortColors(vector<int>& nums) {
        int N = nums.size(),z=0,o=0,t=0;
        for(auto num : nums){
            if(num == 0){
                z++;
            }else if(num == 1){
                o++;
            }else{
                t++;
            }
        }
        
        int i = 0;
        while(z--){
            nums[i] = 0;
            i++;
        }
        while(o--){
            nums[i] = 1;
            i++;
        }
        while(t--){
            nums[i] = 2;
            i++;
        }
        return;
    }
};