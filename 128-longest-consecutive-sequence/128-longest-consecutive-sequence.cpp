class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        set<int> hashset;
        for(auto it : nums){
            hashset.insert(it);
        }
        
        int longestStreak = 0;
        for(int i = 0; i < N; i++){
            int previousNumber = nums[i] - 1;
            int currentNumber = nums[i];
            
            // this is to ensure that current number is the starting of the streak
            // otherwise we must have already calculated this number as a part of the streak
            if(hashset.count(previousNumber)) continue;
            
            int currentStreak = 1;
            while(hashset.count(currentNumber + 1)){
                currentNumber += 1;
                currentStreak += 1;
            }
            
            longestStreak = max(longestStreak,currentStreak);
        }
        return longestStreak;
    }
};