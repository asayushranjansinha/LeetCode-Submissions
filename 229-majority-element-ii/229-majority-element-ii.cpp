/* 
    Intuition : Boyer Moore's Voting Algorithm
*   There can at max be two elements which have >= n/3 frequency
*   So we try to find these two elements using the algo
*   Explanation is not so intuitive so read the algo.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1, candidate2 = -1;
        int count1 = 0, count2 = 0;
        vector<int>result;
        int N = nums.size();
        
        for(auto it : nums){
            if(candidate1 == it){
                count1++;
            }
            else if(candidate2 == it){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = it;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = it;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0,count2 = 0;
        for(auto it : nums){
            if(it == candidate1) count1++;
            else if(it == candidate2) count2++;
        }
        
        if(count1 > N/3) result.push_back(candidate1);
        if(count2 > N/3) result.push_back(candidate2);
        
        return result;
    }
};