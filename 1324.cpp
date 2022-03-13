class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words, res;
        string_split(s, words);
        int num_words = words.size(), max = 0;
        for (int i = 0; i < num_words; i++) {
            if (words[i].length() > max) max = words[i].length();
        }
        for (int i = 0; i < max; i++) {
            string temp;
            for (int j = 0; j < num_words; j++) {
                if (i + 1 <= words[j].length()) {
                    temp.append(1, words[j][i]);
                }
                else {
                    temp.append(1, ' ');
                }
            }
            if (find_trailing_space(temp) == -1) {
                res.emplace_back(temp);
            }
            else {
                res.emplace_back(temp.substr(0, find_trailing_space(temp) + 1));
            }
        }
        return res;
    }

    void string_split(string s, vector<string>& vec){
        if(vec.size() > 0)
            vec.clear();
        int length = s.length();
        int start = 0;
        for(int i = 0; i < length; i++){
            if(s[i] == ' ' && i == 0)
                start += 1;
            else if(s[i] == ' '){
                vec.push_back(s.substr(start, i-start));
                start = i + 1;
            }
            else if(i == length - 1){
                vec.push_back(s.substr(start, i + 1 - start));
            }
        }
    }

    int find_trailing_space(string s) {
        int len = s.length();
        if (s[len - 1] != ' ') return -1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') return i;
        }
        return -1;
    }
};