class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> result;
        
        for (int length = 2; length <= 9; ++length) {
            for (int start = 0; start <= 9 - length; ++start) {
                string sub = s.substr(start, length);
                int num = stoi(sub);
                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};