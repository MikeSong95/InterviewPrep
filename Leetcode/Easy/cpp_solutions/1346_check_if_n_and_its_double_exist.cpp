class Solution {
public:
    bool checkIfExist(vector<int>& arr) {       
        map<int, int> hashmap; 

        for (int i = 0; i < arr.size(); i++) {
            map<int,int>::iterator iter = hashmap.find(arr[i]);
            
            if (iter != hashmap.end()) {    // already exists so update
                int new_val = iter->second + 1;
                hashmap.erase(iter);  
                hashmap.insert(pair<int,int>(arr[i],new_val));
            } else {                        // doesn't exist to add
                hashmap.insert(pair<int,int>(arr[i],1));
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            map<int,int>::iterator iter = hashmap.find(arr[i]*2);
            
            if (arr[i] == 0) {
                if (iter->second >= 2) return true;
            } else {
                 if (hashmap.find(arr[i]*2) != hashmap.end()) return true;
            }
        }
    
        return false;
    }
};