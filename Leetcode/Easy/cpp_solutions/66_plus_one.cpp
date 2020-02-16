class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int carry = 1;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry == 1) {
                digits[i] = digits[i] + 1;
                if (digits[i] == 10) {
                    digits[i] = 0;
                    carry = 1;
                } else {
                    carry = 0;
                }
            }
        }
        
        if (carry == 1) digits.insert(digits.begin(), 1);
        
        return digits;
    }
};