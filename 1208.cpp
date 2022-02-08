class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.length();
        vector<int> diff(length);
        for (int i = 0; i < length; i++) {
            diff[i] = abs(s[i]-t[i]);
        }
        int left = 0, right = 0, cost = diff[0], maxlen = 0;
        while(left <= right) { // sliding window
            if(cost <= maxCost) {
                right++;
                if (right >= length){
                    maxlen = max(maxlen, right - left);
                    break;
                }
                else {
                    cost += diff[right];
                }  
            }
            else {
                maxlen = max(maxlen, right - left);
                cost -= diff[left];
                if (left == right) { //boundary case
                    left++;
                    right++;
                    if (left >= length) break;
                    else cost = diff[left];
                }
                else left++;
            }
        }
        return maxlen;
    }
};