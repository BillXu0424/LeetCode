class Solution {
public:
    int minFlips(string target) {
        int times = 0, len = target.length();
        char last = '0';
        for (int i = 0; i < len; i++) {
            if (target[i] != last) times++;
            last = target[i];
        }
        return times;
    }
};