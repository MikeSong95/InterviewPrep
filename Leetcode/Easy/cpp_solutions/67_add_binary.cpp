class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string sum = "";
        int carry = 0;
        int digit;
        int index = 0;
        
        while (index < a.length() || index < b.length()) {
            if (index >= a.length()) {
                int b_digit = b[index] - '0';
                
                digit = (b_digit + carry) % 2;
                
                if (b_digit + carry == 2) carry = 1;
                else carry = 0;
            } else if (index >= b.length()) {
                int a_digit = a[index] - '0';
                
                digit = (a_digit + carry) % 2;
                
                if (a_digit + carry == 2) carry = 1;
                else carry = 0;
            } else {
                int a_digit = a[index] - '0';
                int b_digit = b[index] - '0';

                digit = (a_digit + b_digit + carry) % 2;
                
                if (a_digit + b_digit + carry >= 2) carry = 1;
                else carry = 0;
            }

            index++;
            sum.append(to_string(digit));
        }
                
        if (carry == 1) {
            sum.append(to_string(carry));
        }
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};