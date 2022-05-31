class Solution {
public:
    int convertToBinary(string s) {
        int num = 0;
        for(auto i: s) {
            num = num << 1;
            num += i - '0';
        }
        return num;
    }
    bool hasAllCodes(string s, int k) {
        unordered_set<int> codesDone;
        int n = s.size();
        unsigned int curr = convertToBinary(s.substr(0, k));
        codesDone.insert(curr);
        int totalNum = (1 << k);
        for(int i = 1; i<n-k+1; i++) {
            if(codesDone.size() == totalNum) break;
            curr = curr << 1;
            curr -= (s[i-1] - '0') << k;
            curr += (s[i+k-1] - '0');
            if(codesDone.find(curr) == codesDone.end()) {
                codesDone.insert(curr);
            }
        }
        return codesDone.size() == totalNum;
    }
};