class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0;
        int biggest = 0;
        double divide = 0;
        double num_zeros = 0;
        
        while (i < seats.size()) {
            if (seats[i] == 1) {
                if (divide < 2) divide++;
            } else {
                num_zeros++;
                i++;
            }
         
            while (i < seats.size()) {
                if (seats[i] == 1) break;
                else {
                    num_zeros++;
                    i++;
                }
            }
    
            if (i == seats.size()) i--;
            
            if (seats[i] == 1 && divide < 2) divide++;
            
            if (divide == 0) divide = 1;

            if (ceil(num_zeros / divide) > biggest) biggest = ceil(num_zeros / divide);
        
            if (seats[i] == 1) divide = 1;
            else divide = 0;
            
            num_zeros = 0;
            i++;
        }
        
        return biggest;
    }
};