class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.begin() == s.end()) return 0;
        
        map<char, int> hash;
        
        string::iterator front = s.begin();
        string::iterator back = s.begin() + 1;
        
        int length = 1;
        int biggest = 1;
        
        while (back != s.end()) {
            map<char, int>::iterator back_lookup = hash.find(*back);
            if (*front != *back && back_lookup == hash.end()) {
                hash[*front] = 1;
                hash[*back] = 1;
                back++;
                length++;
                
                if (length > biggest) {
                    biggest = length;
                }
            } else {
                front++;
                back = front + 1;
                length = 1;
                hash.clear();
            }

        }
        
        return biggest;
    }
};