class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        
        if(n <= 1){
            return ans;
        }
        
        int i = 0;
        for(i = 0; i < n-1; i++){
            
            int newTarget = target - numbers[i];
            int lo = i+1;
            int hi = n-1;
                       
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(numbers[mid] == newTarget){
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }
                else if(numbers[mid] < newTarget){
                    lo = mid+1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        return ans;
    }
};