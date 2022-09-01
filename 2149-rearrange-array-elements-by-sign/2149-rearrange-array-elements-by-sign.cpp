class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>allPositives;
        vector<int>allNegatives;
        
        int N = nums.size();
        for(int i = 0; i < N; i++){
            if(nums[i] < 0){
                allNegatives.push_back(nums[i]);
            }
            else{
                allPositives.push_back(nums[i]);
            }
        }
        
        vector<int> result;
        for(int i = 0; i < allNegatives.size(); i++){
            result.push_back(allPositives[i]);
            result.push_back(allNegatives[i]);
        }
        return result;
    }
};