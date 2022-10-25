class Solution {
private:
    string updateString(string s){
        string newString = "@";
        for(auto ch : s){
            newString += '#';
            newString += ch;
        }
        newString += '#';
        newString += '*';
        return newString;
    }
    
    pair<int,int> manachersAlgorithm(string input){
        int len = input.size();
        vector<int> characterMatchCount(len,0);
        
        int currentMirrorIdx = 0, lastMatchingIdx = 0;
        for(int potentialMirrorIdx = 1; potentialMirrorIdx < len - 1; potentialMirrorIdx++){
            int mirrorImgIdx = 2 * currentMirrorIdx - potentialMirrorIdx;
            
            if(potentialMirrorIdx < lastMatchingIdx){
                characterMatchCount[potentialMirrorIdx] = min(characterMatchCount[mirrorImgIdx],lastMatchingIdx - potentialMirrorIdx);
            }
            
            
            while(input[potentialMirrorIdx - characterMatchCount[potentialMirrorIdx] - 1] == 
                  input[potentialMirrorIdx + characterMatchCount[potentialMirrorIdx] + 1]){
                
                characterMatchCount[potentialMirrorIdx]++;
            }
            
            if(characterMatchCount[potentialMirrorIdx] + potentialMirrorIdx > lastMatchingIdx){
                currentMirrorIdx = potentialMirrorIdx;
                lastMatchingIdx = currentMirrorIdx + characterMatchCount[currentMirrorIdx];
            }
        }
        
        int maxIdx = 0,maxVal = 0;
        for(int i = 0; i < len; i++){
            if(maxVal < characterMatchCount[i]){
                maxIdx = i;
                maxVal = characterMatchCount[i];
            }
        }
        
        return {maxIdx,maxVal};
    }
    
    string palindrome(string s, int idx, int len){
        string res = "";
        while(len--){
            res += s[idx++];
        }
        return res;
    }
public:
    string longestPalindrome(string s) {
        string input = updateString(s);
        pair<int,int>output = manachersAlgorithm(input);
        int len = output.second;
        int maxIdx = output.first;
        
        int firstIdx = (maxIdx - len + 1);
        int actualIdx = (firstIdx - 2)/2;
        
        return palindrome(s,actualIdx,len);    
    }
};