class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int first = 0, second = 0, row = bank.size(), res = 0;
        for (int i = 0; i < row; i++) {
            if (first == 0) {
                for (auto c : bank[i]) {
                    if (c == '1') first++;
                }
                continue;
            }
            if (second == 0) {
                for (auto c : bank[i]) {
                    if (c == '1') second++;
                }
                if (second != 0) {
                    res += first * second;
                    first = second;
                    second = 0;
                    continue; 
                }  
            }
        }
        return res;
    }
};