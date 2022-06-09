class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        
        if(n <= 1){
            return ans;
        }
        
        int i = 1, j = n;
        while(i < j){
            if(numbers[i-1] + numbers[j-1] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(numbers[i-1] + numbers[j-1] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};