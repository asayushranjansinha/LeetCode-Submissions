class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        int n = numbers.size();
        if(n <= 1){
            return ans;
        }
        
        
        for(int i = 0; i < n; i++){
            int val1 = numbers[i];
            int val2 = target - val1;
            
            if(mp[val2] > 0){
                ans.push_back(mp[val2]);
                ans.push_back(i+1);                
                return ans;
            }
            
            mp[val1] = i+1;
        }
        for(auto i : mp){
            cout << i.second << endl;
        }
        return ans;
    }
};