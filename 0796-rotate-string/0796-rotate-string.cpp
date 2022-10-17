class Solution {
private:
    bool compareStrings(string original, string goal, int startIndex){
        int N = original.size();
        int M = goal.size();
        
        for(int orgIndex = 0; orgIndex < N; orgIndex++){
            if(original[orgIndex] != goal[startIndex]) return false;
            startIndex = (startIndex + 1) % M;
        }
        return true;
    }
public:
    bool rotateString(string original, string goal) {
        int originalSize = original.size();
        int goalSize = goal.size();
        
        if(originalSize != goalSize) return false;
        for(int idx = 0; idx < goalSize; idx++){
            if(original[0] == goal[idx] && compareStrings(original,goal,idx)){
                return true;
            }
        }
        return false;
    }
};