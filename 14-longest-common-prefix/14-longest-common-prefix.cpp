class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string res = "";
        
        // this will sort all strings in strs in lexicographical order
        sort(strs.begin(),strs.end());
        
        // maximum length of the common prefix is of length of first string in 
        // the sorted array
        int firstStringSize = strs[0].size();
        
        // compare each character of first string in sorted array with all other strings
        for(int characterIndex = 0; characterIndex < firstStringSize; characterIndex++){
            char character1 = strs[0][characterIndex];
            
            bool flag = true;
            for(int strsIndex = 1; strsIndex < size; strsIndex++){
                char character2 = strs[strsIndex][characterIndex];
                
                
                // when first different character found, then return the prefix calculated till now.
                if(character1 != character2){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                res.push_back(character1);
            }
            else{
                return res;
            }
        }
        return res;
    }
};