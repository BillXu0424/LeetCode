class Solution {
public:
    string removeKdigits(string num, int k) {
        while (k > 0) {
            int len = num.length(), i = 0;
            if (len == 1) {
                num = "0";
                break;
            }
            while (i < len - 1) {
                if (num[i] > num[i + 1]) {
                    num.erase(num.begin() + i);
                    break;
                }
                i++;
            }
            if (i == len - 1) {
                num.erase(num.end() - 1);
            }
            k--;
        }
        size_t pos = num.find_first_not_of("0");
        if (pos == 0) return num;
        if (pos == string::npos) {
            num = "0";
        }
        else {
            num.erase(0, pos);
        }
        return num;
    }
};