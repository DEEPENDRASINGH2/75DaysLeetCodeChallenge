#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
       
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }

      
        vector<long long> multiples(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            for (int j = i; j <= max_val; j += i) {
                multiples[i] += count[j];
            }
        }

    
        vector<long long> exact_gcd(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            // Total pairs where both elements are multiples of i
            long long pairs = multiples[i] * (multiples[i] - 1) / 2;
            
           
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= exact_gcd[j];
            }
            exact_gcd[i] = pairs;
        }

        
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + exact_gcd[i];
        }

        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            // We want to find the first index `i` such that pref[i] > q
            int left = 1, right = max_val, res = max_val;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (pref[mid] > q) {
                    res = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            answer.push_back(res);
        }

        return answer;
    }
};