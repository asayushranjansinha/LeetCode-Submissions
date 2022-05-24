class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<int>> prevIndex(m+1,vector<int>(n+1,0));
        
        for(int index = 1; index <= size; index++){
            int countZeros = count(strs[index-1].begin(),strs[index-1].end(),'0');
            int countOnes = strs[index-1].size() - countZeros;
            
            vector<vector<int>> currIndex(m+1,vector<int>(n+1,0));
            for(int zero = 0; zero <= m; zero++){
                for(int one = 0; one <= n; one++){
                    
                    int take = 0;
                    int notTake = prevIndex[zero][one];
                    if(zero-countZeros >= 0 && one-countOnes >= 0){
                        take = 1 + prevIndex[zero-countZeros][one-countOnes];
                    }
                    
                    currIndex[zero][one] = max(take,notTake);
                }
            }
            prevIndex = currIndex;
        }
        return prevIndex[m][n];
    }
};