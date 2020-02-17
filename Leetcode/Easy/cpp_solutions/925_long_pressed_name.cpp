class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        string::iterator name_iter = name.begin();
        string::iterator typed_iter = typed.begin();
        
        while (name_iter != name.end() && typed_iter != typed.end()) {
            if (*name_iter == *typed_iter) {
                name_iter++;
                typed_iter++;
            } else {
                typed_iter++;
            }
        }
        
        if (name_iter == name.end() && typed_iter != typed.end()) {
            while (typed_iter != typed.end()) {
                if (*typed_iter != *(name_iter - 1)) {
                    return false;
                }
                
                typed_iter++;
            }
            
            return true;
        } else if (name_iter != name.end() && typed_iter == typed.end()) {
            return false;            
        } else {
            return true;
        }
    }
};