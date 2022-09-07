class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> triplets;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < N; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                //avoiding duplicates
                
                int element1 = nums[i];
                int target = -element1;
                
                int low = i + 1;
                int high = N - 1;
                
                while(low < high){
                    int element2 = nums[low];
                    int element3 = nums[high];
                    int sum = element2 + element3;
                    
                    if(sum == target){
                        vector<int> triplet;
                        triplet.push_back(element1);
                        triplet.push_back(element2);
                        triplet.push_back(element3);
                        
                        triplets.push_back(triplet);
                        
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;

                        low++;
                        high--;
                    }
                    else if(sum > target) high--;
                    else low++;
                }
            }
        }
        return triplets;
    }
};