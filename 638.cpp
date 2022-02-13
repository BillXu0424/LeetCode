class Solution {
public:
    map<vector<int>, int> memo;

    int dfs(vector<int> price, vector<int> curNeeds, vector<vector<int>> & filterSpecial, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i]; // without buying any special offer
            }
            for (auto & curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; ++i) {
                    if (curSpecial[i] > curNeeds[i]) { // can't buy more items than specified in cur_needs 
                        break;
                    }
                    nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) { 
                    minPrice = min(minPrice, dfs(price, nxtNeeds, filterSpecial, n) + specialPrice);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        vector<vector<int>> filterSpecial;
        for (auto & sp : special) {
            int totalPrice = 0;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (sp[i] > needs[i]) {
                    flag = false;
                    break;
                }
                totalPrice += sp[i] * price[i];
            }
            if (flag && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, needs, filterSpecial, n);
    }
};