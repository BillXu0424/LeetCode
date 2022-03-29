class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        if (x < y) {
            swap(x, y);
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a') s[i] = 'b';
                else if (s[i] == 'b') s[i] = 'a';
            }
        }

        int ret = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] != 'a' && s[i] != 'b') i++;
            
            int ca = 0, cb = 0;
            while (i < n && (s[i] == 'a' || s[i] == 'b')) {
                if (s[i] == 'a') {
                    ca++;
                } else {
                    if (ca > 0) {
                        ca--;
                        ret += x;
                    } else {
                        cb++;
                    }
                }
                i++;
            }
            
            ret += min(ca, cb) * y;
        }

        return ret;
    }
};