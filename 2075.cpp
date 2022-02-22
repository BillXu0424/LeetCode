class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cur_start = 0, cols = encodedText.length() / rows, index = 0;
        string originalText;
        while (cur_start < cols) {
            originalText.append(1, encodedText[index]);
            if (index / cols == rows - 1 || index % cols == cols - 1) index = ++cur_start;
            else index += (cols + 1);
        }
        if (!originalText.empty()) originalText.erase(originalText.find_last_not_of(" ") + 1);
        return originalText;
    }
};