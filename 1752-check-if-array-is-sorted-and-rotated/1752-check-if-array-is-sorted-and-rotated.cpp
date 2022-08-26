class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int item1 = nums[i];
            int item2 = nums[(i+1)%nums.size()];
            
            if(item1 > item2){
                count++;
            }
        }
        if(count <= 1) return true;
        return false;
    }
};