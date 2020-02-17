class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub = "";
        int length = 1;
        bool isSubstring = true;
        
        while (length <= s.size() / 2) {
            sub = s.substr(0,length);
            for (int i = length; i < s.size(); i += length) {
                if (sub != s.substr(i, length)) {
                    isSubstring = false;
                } 
            }
            
            if (isSubstring) {
                return true;
            } 
            
            length++;
            isSubstring = true;
        }
        
        return false;
    }
};