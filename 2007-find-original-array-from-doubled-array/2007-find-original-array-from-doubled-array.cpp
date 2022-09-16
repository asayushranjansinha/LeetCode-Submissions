class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int N = changed.size();
        
        if(N % 2) return {};
        
        unordered_map<int,int> mpp;
        vector<int> original;
        
        for(auto it : changed){
            mpp[it]++;
        }
        
        sort(changed.begin(),changed.end());
        for(int i = 0; i < N; i++){
            int num1 = changed[i];
            int freq1 = mpp[num1];
            
            if(freq1 == 0) continue;
            
            if(num1 == 0 && freq1 % 2) return {};
            
            int num2 = num1 * 2;
            int freq2 = mpp[num2];
            
            if(freq1 > freq2) return {};
            
            while(mpp[num1] > 0){
                original.push_back(num1);
                mpp[num2]--;
                mpp[num1]--;
            }
        }
        return original;
    }
};