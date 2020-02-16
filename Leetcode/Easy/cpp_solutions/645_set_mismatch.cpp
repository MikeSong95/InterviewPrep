class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        map<int, int> hashmap;
        int missing_num, dup_num;
        vector<int> sol;
        
        for (int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator iter = hashmap.find(nums[i]);
            
            if (hashmap.find(nums[i]) != hashmap.end()) {
                iter->second = iter->second + 1;
            } else {
                hashmap.insert(pair<int, int>(nums[i], 1));
            }
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            map<int, int>::iterator iter = hashmap.find(i);
            
            if (iter == hashmap.end()) {
                missing_num = i;
            } else if (iter->second == 2) {
                dup_num = i;
            }
        }
        
        sol.push_back(dup_num);
        sol.push_back(missing_num);
        
        return sol;
    }
};