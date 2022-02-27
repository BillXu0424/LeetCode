class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string n_str(10, 0);
        while (n > 0) {
            n_str[n % 10]++;
            n /= 10;
        }
        unordered_set<string> hm;
        int pow = 1;
        for (int i = 0; i < 30; i++) {
            string temp_str(10, 0);
            if (i != 0) pow <<= 1;
            int temp = pow;
            while (temp > 0) {
                temp_str[temp % 10]++;
                temp /= 10;
            }
            hm.insert(temp_str);
        }
        return hm.find(n_str) != hm.end() ? true : false;
    }
};