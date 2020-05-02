#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> getPrimes(int n) {
    unordered_map<int, int> primes;
    primes[2] = 1;
    for(int i = 3; i <= n; i++) {
        bool prime = true;
        
        for(int j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                prime=false;
                break;
            }
        }

        if (prime) {
            primes[i] = 1;
        }
    }

    return primes;
}

int main(void) {
    int t, n;
    int largest = 0;

    unordered_map<int, int> p;
    vector<int> nums;

    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        n *= 2;
        nums.push_back(n);
        if (n > largest) {
            largest = n;
        }
    }

    p = getPrimes(largest);

    for (auto num : nums) {    
        unordered_map<int, int>::iterator it = p.begin();

        while (it != p.end()) {
            unordered_map<int, int>::iterator it2 = p.find(num - it->first);
            if (it2 != p.end()) {
                cout << it->first << " " << it2->first << endl;
                break;
            }
            it++;
        }
    }

}