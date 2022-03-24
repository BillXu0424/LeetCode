class Solution {
public:
    int maxDiff(int num) {
        stringstream stream;
        string str1 = to_string(num), str2 = str1;
        char str1_first = str1[0];
        if (str1_first == '9') {
            for (int i = 1; i < str1.length(); i++) {
                if (str1[i] < '9') {
                    str1_first = str1[i];
                    break;
                }
            }
        }
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] == str1_first) str1[i] = '9';
        }
        int a;
        stream << str1;
	    stream >> a;
        stream.clear();
        char str2_first = str2[0];
        if (str2[0] == '1') {
            for (int i = 1; i < str2.length(); i++) {
                if (str2[i] > '1') {
                    str2_first = str2[i];
                    break;
                }
            }
            for (int i = 0; i < str2.length(); i++) {
                if (str2_first == '1') break;
                if (str2[i] == str2_first) str2[i] = '0';
            }
        }
        else {
            str2_first = str2[0];
            for (int i = 0; i < str2.length(); i++) {
                if (str2[i] == str2_first) str2[i] = '1';
            }
        }
        int b;
        stream << str2;
	    stream >> b;
        return a - b;
    }
};